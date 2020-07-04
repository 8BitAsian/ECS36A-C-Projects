all: test_prog5

test_prog5: test_prog5.c prog5.o
	gcc -Wall -Werror test_prog5.c prog5.o -o test_prog5

prog5.o: prog5.c prog5.h
	gcc -Wall -Werror -c prog5.c -o prog5.o

clean:
	test_prog5 prog5.o
