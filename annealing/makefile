# makefile for annealing program.

anneal: main.o annealing.o
	gcc main.o annealing.o -lm -o anneal

main.o: main.c annealing.c annealing.h
	gcc -c main.c -o main.o

annealing.o: annealing.c annealing.h
	gcc -c annealing.c -o annealing.o