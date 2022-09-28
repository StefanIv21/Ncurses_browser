
CC = gcc -std=c99
CFLAGS = -g -Wall -lm

build: task1 task2 task3 task4

task1: task1.c comun.c
	$(CC) -std=c99 -g -o task1 task1.c comun.c $(CFLAGS)

task2: task2.c comun.c
	$(CC) -std=c99 -g -o task2 task2.c comun.c $(CFLAGS)

task3: task3.c comun.c
	$(CC) -std=c99 -g -o task3 task3.c comun.c $(CFLAGS)

task4: task4.c comun.c
	$(CC) -std=c99 -g -o task4 task4.c comun.c $(CFLAGS)

.PHONY : clean
clean :
	rm -f task1 task2 task3 task4 task5
	rm -f *.out
	rm my_diff
