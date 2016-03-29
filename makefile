aes_test: main.o aes.o
	gcc -std=c99 main.o aes.o -g -O2 -o aes_test
main.o: main.c aes.h
	gcc -std=c99 -c -g -O2 main.c
aes.o: aes.c aes.h
	gcc -std=c99 -c -g -O2 aes.c
clean:
	rm *.o aes_test
