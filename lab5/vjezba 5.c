#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct broj
{
	float br;
	struct broj* next;

}broj;

void AddToBegining(float x,broj* head) {

	broj* temp;
	temp = (broj*)malloc(sizeof(broj));
	if (temp == NULL) {
		printf("nema vise memorije");
	}

	temp->br = x;
	temp->next = head->next;
	head->next = temp;
}

float Remove(broj* head) {

	float x;
	broj* temp;

	x = head->next->br;
	temp = head->next->next;
	free(head->next);
	head->next = temp;

	return x;
}

float Izracunaj(broj* head) {

	FILE* f = NULL;
	float broj;
	char znak;
	float a;
	float b;

	f = fopen("postfix.txt", "r");
	if (f == NULL) {
		printf("fajl se nije mogao otvorit");
		return -1;
	}
	while (feof(f) == 0) {
		if (fscanf(f, " %f", &broj)) {
			AddToBegining(broj, head);
		}
		else {
			fseek(f, -1, SEEK_CUR);
			fscanf(f, " %c", &znak);
			if (znak == '+') {
				a = Remove(head);
				b = Remove(head);
				AddToBegining(a + b, head);
			}
			else if (znak == '-') {
				a = Remove(head);
				b = Remove(head);
				AddToBegining(b - a, head);
			}
			else if (znak == '/') {
				a = Remove(head);
				b = Remove(head);
				AddToBegining(b / a, head);
			}
			else if (znak == '*') {
				a = Remove(head);
				b = Remove(head);
				AddToBegining(a * b, head);
			}
		}
	}
	return Remove(head);
}


int main() {
	

	broj Head = { 0.0,NULL };

	printf("postfils je dao: %f", Izracunaj(&Head));

	return 0;
}