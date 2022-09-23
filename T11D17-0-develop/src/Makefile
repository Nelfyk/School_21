cc=gcc
flags=-Wall -Wextra -Werror

all: door_struct list_test stack_test

door_struct: dmanager_module.o
	$(cc) dmanager_module.o -o ../build/Quest1
list_test: list_test.o list.o
	$(cc) list_test.o list.o -o ../build/Quest2
stack_test: stack_test.o stack.o
	$(cc) stack_test.o stack.o -o ../build/Quest3
stack_test.o: stack_test.c
	$(cc) $(flags) -c stack_test.c
stack.o: stack.c
	$(cc) $(flags) -c stack.c
list_test.o: list_test.c
	$(cc) $(flags) -c list_test.c
list.o: list.c
	$(cc) $(flags) -c list.c
dmanager_module.o: dmanager_module.c
	$(cc) $(flags) -c dmanager_module.c
clean:
	rm -f *.o
	rm -f ../build/*
rebuild: clean all
