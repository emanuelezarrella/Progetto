programma:	main.o item.o list.o studente.o
	gcc main.o item.o list.o studfente.o -o 

main.o: main.c
	gcc -c main.c

item.o:item.c
	gcc -c item.c

list.o: list.c
	gcc -c list.c

studente.o: studente.c
	gcc -c studente.c

clean:rm -f *.o programma