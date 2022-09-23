# *.c ../data_libs/*.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
CFLAGS=-c -Wall -Wextra -Werror -c
CC=gcc
T=../../build
dir1=../data_libs
dir2=../data_module
dir3=../yet_another_decision_module
IO=data_io
stat=data_stat
proc=data_process
dec=decision
sort=sort
main=main_executable_module
all: out
out: $(main).o $(sort).o $(dir1)/$(IO).o $(dir1)/$(stat).o $(dir2)/$(proc).o $(dir3)/$(dec).o
	$(CC) $(main).o $(sort).o $(IO).o $(stat).o $(proc).o $(dec).o -o $(T)/Quest_3
build_with_static: $(main).o $(sort).o $(dir1)/$(IO).o data_stat.a $(dir2)/$(proc).o $(dir3)/$(dec).o
	$(CC) $(main).o $(sort).o $(IO).o data_stat.a $(proc).o $(dec).o -o $(T)/Quest_5
data_stat.a: $(dir1)/$(stat).o
	ar rc data_stat.a $(stat).o
	ranlib data_stat.a
	rm -rf data_stat.o
$(main).o: $(main).c
	$(CC) $(CFLAGS) $(main).c
$(sort).o: $(sort).c
	$(CC) $(CFLAGS) $(sort).c
$(dir1)/$(IO).o: $(dir1)/$(IO).c 
	$(CC) $(CFLAGS) $(dir1)/$(IO).c
$(dir1)/$(stat).o: $(dir1)/$(stat).c
	$(CC) $(CFLAGS) $(dir1)/$(stat).c
$(dir2)/$(proc).o: $(dir2)/$(proc).c
	$(CC) $(CFLAGS) $(dir2)/$(proc).c
$(dir3)/$(dec).o: $(dir3)/$(dec).c
	$(CC) $(CFLAGS) $(dir3)/$(dec).c
clean: 
	rm -rf *.o a.out *.a
rebuild: clean all