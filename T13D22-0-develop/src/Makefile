cc = gcc
flag = -Wall -Wextra -Werror

all: cipher logging_cipher

cipher: cipher.o cipher_function.o logger.o
	$(cc) cipher.o cipher_function.o logger.o -o ../build/cipher
logging_cipher: cipher.o cipher_function.o_with_d logger.o
	$(cc) cipher.o cipher_function.o logger.o -o ../build/logging_cipher
cipher.o: cipher.c
	$(cc) $(flag) -c cipher.c
cipher_function.o: cipher_function.c
	$(cc) $(flag) -c cipher_function.c 
cipher_function.o_with_d: cipher_function.c
	$(cc) $(flag) -c cipher_function.c -D LOGGING 
logger.o: logger.c
	$(cc) $(flag) -c logger.c
clean:
	rm -f *.o
	rm -f ../build/*
rebuild: clean all


# logging_cipher