/*
2. Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste,
B. ispisuje listu,
C. dinamicki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. brise odredeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	Person head = { .next = NULL, .name = {0},
					.surname = {0}, .birthYear = 0 };
	menu(&head)

		int menu(Position head) {
		char choice = '\0';

	}

	return 0;
}