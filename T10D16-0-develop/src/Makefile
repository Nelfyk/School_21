cc=gcc
flags=-Wall -Wextra -Werror
all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

strlen_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strlen_test();' -o ../build/Quest_1
strcmp_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strcmp_test();' -o ../build/Quest_2
strcpy_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strcpy_test();' -o ../build/Quest_3
strcat_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strcat_test();' -o ../build/Quest_4
strchr_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strchr_test();' -o ../build/Quest_5
strstr_tests: s21_string_test.c s21_string.c
	$(cc) s21_string_test.c s21_string.c -Dname='s21_strstr_test();' -o ../build/Quest_6
s21_string_test.o: s21_string_test.c
	$(cc) -c $(flags) s21_string_test.c
s21_string.o: s21_string.c
	$(cc) -c $(flags) s21_string.c
clean: 
	rm -f *.o
	rm -f ../build/*
rebuild: clean all

# -Dname='s21_strlen_test()'