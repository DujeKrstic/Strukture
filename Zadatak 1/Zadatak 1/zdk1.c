#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 1024
#define MAX_SIZE 50
#define FILE_ERROR_OPEN -1

//Napisati program koji prvo pro?ita koliko redaka ima datoteka, tj.koliko ima studenata
//zapisanih u datoteci.Nakon toga potrebno je dinami?ki alocirati prostor za niz struktura
//studenata(ime, prezime, bodovi) i u?itati iz datoteke sve zapise.Na ekran ispisati ime,
//prezime, apsolutni i relativni broj bodova.
//Napomena: Svaki redak datoteke sadrži ime i prezime studenta te broj bodova na kolokviju.
//	relatvan_br_bodova = br_bodova / max_br_bodova * 100

typedef struct _student { //tip strukture je _student, a ime je Student

	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;

}Student;


int readNoRowsInFile() {

	int counter = 0;
	char buffer[MAX_LINE] = { 0 };

	FILE* filePointer = NULL;
	filePointer = fopen("students.txt", "r");

	if (!filePointer) {
		printf("\nNema nicega.");
		return FILE_ERROR_OPEN;
	}
	while (!feof(filePointer)) {
		fgets(buffer, MAX_LINE, filePointer); //cita liniju pa poveca counter(broj linija) sve dok ne dodje do kraja fajla
		counter++;
	}
	fclose(filePointer);
	return counter;
}

//_________________ILI_________________________

/* int readNoRowsInFile() {

	int counter = 0;
	char buffer[MAX_LINE] = {0};

	FILE* filePointer=fopen("students.txt","r");

	if (filePointer == NULL) {
		printf("\nNije moguce otvorit datoteku");
		return FILE_ERROR_OPEN;
	}
	if(filePointer != NULL){
		while (!feof(filePointer)) {
			fgets(buffer, MAX_LINE, filePointer); //cita liniju pa poveca counter(broj linija) sve dok ne dodje do kraja fajla
			counter++;
		}
	}
	fclose(filePointer);
	return counter;
}
*/

void readFromFile(Student* students, int noRows) {


	FILE* filePointer = fopen("students.txt", "r");

	if (filePointer == NULL) {
		printf("\nNije moguce otvorit datoteku");
		return FILE_ERROR_OPEN;
	}

	if (filePointer != NULL) {
		for (int i = 0; i < noRows; i++) {
			fscanf(filePointer, "%s %s %lf", students[i].name, students[i].surname, &students[i].points);
		}
	}
	fclose(filePointer);

}

int RelativeNumberOfPoints(int max_number_of_points, double points) {
	int rpoints = 0;

	rpoints = points / max_number_of_points * 100;

	return rpoints;
}

int main() {

	int noRows = 0;
	int i = 0;
	int max_number_of_points = 50;
	double relative_points = 0.0;
	noRows = readNoRowsInFile();
	printf("\nBroj redova je %d\n", noRows);

	Student* students = (Student*)malloc(noRows * sizeof(Student)); //dinamicka alokacija memorije
	readFromFile(students, noRows);

	for (i = 0; i < noRows; i++) {

		relative_points = RelativeNumberOfPoints(max_number_of_points, students[i].points);
		printf("Ime: %s, Prezime: %s, Apsolutni broj bodova: %lf, Relativan broj bodova %lf\n", students[i].name, students[i].surname, students[i].points, relative_points);
	}

	free(students);

	return 0;
}





