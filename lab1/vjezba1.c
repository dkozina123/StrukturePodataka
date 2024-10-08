
#define _CRT_SECURE_NO_WARNINGS
#define ERROR_OPENING_FILE -1
#include<stdio.h>
#define BUFFER_SIZE 1024

typedef struct {
	char ime[10];
	char prezime[10];
	int bod;
}Student;

int count_rows(char* filename);



int main()
{
	FILE* f=NULL;

	f = fopen("studenti.txt", "r");
	
	

	
	
	fclose(f);
	
	return 0;
}


int count_rows(char* filename); {
	
	FILE* fp = NULL;
	char buffer[BUFFER_SIZE];
	int count == 0;

	fp = fopen(filename, "r");
	if (f == NULL)
	{
		printf("neuspjesno otvaranje");
		return ERROR_OPENING_FILE;
	}
	while (!feof(f)) {
		fgets(buffer, BUFFER_SIZE, fp);
		count++;
	}

	fclose(fp);

	return count;
}





