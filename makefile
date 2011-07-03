all:

	gcc main.c arithmetique.c arithmetique.h liste.c liste.h main.h -o calc.bin
	./calc.bin

