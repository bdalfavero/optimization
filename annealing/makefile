# makefile for annealing program.

anneal: main.o annealing.o tour.o
	gcc -g main.o annealing.o tour.o -lm -o anneal

main.o: main.c annealing.h annealing.c tour.h tour.c rand.h
	gcc -g -c main.c -o main.o

annealing.o: rand.h annealing.c annealing.h
	gcc -g -c annealing.c -o annealing.o

tour.o: rand.h tour.h tour.c
	gcc -g -c tour.c -o tour.o