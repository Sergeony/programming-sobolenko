CC = clang
C_OPTS = -g

clean:
	rm -rf dist
	
prep:
	mkdir dist
	
compile: arrays_main.bin cycles_main.bin addition_main.bin

arrays_main.bin: src/arrays/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
cycles_main.bin: src/cycles/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
addition_main.bin: src/addition/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/arrays_main.bin
	./dist/cycles_main.bin
	./dist/addition_main.bin
	
all:
	make clean prep compile run
