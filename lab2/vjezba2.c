#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct osoba{
	char ime[20];
	char prezime[20];
	int god;
	struct osoba* next;
} osoba;

osoba* CreateOsoba(char* ime, char* prezime, int god) {

	osoba* temp;
	temp = (osoba*)malloc(sizeof(osoba));

	strcpy(temp->ime, ime);
	strcpy(temp->prezime, prezime);
	temp->god = god;
	temp->next = NULL;

	return temp;
}

void AddToBeging(osoba* head , osoba* covjek) {
	
	osoba* temp;

	if (head->next == NULL) {
		head->next = covjek;
	}
	else {
		temp = head->next;
		head->next = covjek;
		covjek->next = temp;
	}
}

osoba* FindLast(osoba* head) {
	
	while (head->next != NULL) {
		head = head->next;
	}

	return head;
}

void AddToEnd(osoba* head, osoba* covjek) {

	osoba* last;
	last = FindLast(head);
	last->next = covjek;

}

void DeleteRecursive(osoba* head) {

	if (head->next == NULL) {
		free(head);
	}
	else {
		DeleteRecursive(head->next);
		free(head);
	}
}

void DeleteList(osoba* head) {

	if (head->next != NULL) {
		DeleteRecursive(head->next);
		head->next = NULL;
	}
}

void PrintList(osoba head) {

	head = *head.next;
	while (1){
		printf("%s %s %d.\n", head.ime, head.prezime, head.god);
		if (head.next == NULL)
			break;
		head = *head.next;
	}
}


int main()
{
	osoba head;
	osoba temp1 = { "Walter" ,"White" ,1958 };
	osoba temp2 = { "Alan" ,"Wake",1977 };
	osoba temp3 = { "Dexter","Morgan",1970 };
	osoba* pravljenje;
	head.next = NULL;

	pravljenje = CreateOsoba(temp1.ime, temp1.prezime, temp1.god);
	AddToBeging(&head, pravljenje);
	pravljenje = CreateOsoba(temp2.ime, temp2.prezime, temp2.god);
	AddToBeging(&head, pravljenje);
	pravljenje = CreateOsoba(temp3.ime, temp3.prezime, temp3.god);
	AddToBeging(&head, pravljenje);
	pravljenje = CreateOsoba(temp1.ime, temp1.prezime, temp1.god);
	AddToEnd(&head, pravljenje);

	PrintList(head);

	DeleteList(&head);

	printf("hello world!");

	return 0;
}