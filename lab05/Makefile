CC = clang
C_OPTS = -g

clean:
	rm -rf dist
	
prep:
	mkdir dist
	
compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main.bin
	
all:
	make clean prep compile run
