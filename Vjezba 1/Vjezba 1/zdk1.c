/*
1. Napisati program koji prvo procita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i ucitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrzi ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE (50)
#define MAX_LINE (1024)
#define FILE_ERROR_OPEN (-1)

typedef struct _duje
{
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;

}Duje;

int readNorowsInFile() {
	int counter = 0;
	FILE* FilePointer = NULL;
	char buffer[MAX_LINE] = { 0 };
	FilePointer = fopen("dat.txt", "r");
	if (!FilePointer) {
		printf("Greska.\n");
		return FILE_ERROR_OPEN;
	}
	while (!feof(FilePointer)) {
		fgets(buffer, MAX_LINE, FilePointer);
		counter++;

	}
	fclose(FilePointer);
	return counter;
}
int main() {
	int noRows = 0;
	noRows = readNorowsInFile();
	printf("%d", noRows);
	return 0;
}