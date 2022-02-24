CC = clang
C_OPTS = -g

clean:
	rm -rf dist
	
prep:
	mkdir dist
	
compile: main.bin test.bin 

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

test.bin: test/test.c
	$(CC) $(C_OPTS) $< -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lcheck -lm -lrt -lpthread -lsumbit

run: clean prep compile
	./dist/main.bin

test: clean prep test.bin
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

format:
	doxygen Doxyfile
	
doxy-prepare:
	doxygen -g Doxyfile
	
all: clean prep compile run format
	./dist/main.bin
