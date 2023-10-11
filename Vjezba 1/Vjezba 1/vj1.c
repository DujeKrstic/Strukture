/*
1. Napisati program koji prvo procita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i ucitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrzi ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE (50)
#define MAX_LINE (1024)
#define FILE_ERROR_OPEN (-1)


int readNoRowsInFile() {
	int counter = 0;
	FILE *filePointer = NULL;
	char buffer[MAX_LINE] = { 0 };
}

typedef struct _student {
	char ime[50];
} Student;

int main() {

	//Student student;

	int noRows = 0;
	noRows = readNoRowsInFile();

	printf("%d", noRows);

	return 0;
}