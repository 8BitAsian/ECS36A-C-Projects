all: test_arr_utils test_str_utils 

test_arr_utils: test_arr_utils.c arr_utils.o
	gcc -Wall -Werror test_arr_utils.c arr_utils.o -o test_arr_utils

test_str_utils: test_str_utils.c str_utils.o
	gcc -Wall -Werror test_str_utils.c str_utils.o -o test_str_utils

arr_utils.o: arr_utils.c arr_utils.h
	gcc -Wall -Werror -c arr_utils.c -o arr_utils.o

str_utils.o: str_utils.c str_utils.h
	gcc -Wall -Werror -c str_utils.c -o str_utils.o

clean: 
	test_arr_utils test_str_utils arr_utils.o str_utils.o

