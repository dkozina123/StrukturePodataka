#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct direktorij;
typedef struct direktorij* pozicijad;
typedef struct direktorij {
	char ime[15];
	pozicijad next;
	pozicijad below;
}direktorij;

struct stogdirektorij;
typedef struct stogdirektorij* pozicijasd;
typedef struct stogdirektorij {
	pozicijad direktorij;
	pozicijasd next;
}stogdirektorij;

pozicijad stvoridirektorij(char[]);
bool odabir(pozicijad*, pozicijasd, char[]);
int md(pozicijad, char[]);
int cddir(pozicijad*, pozicijasd, char[]);
int cddot(pozicijad*, pozicijasd);
int dir(pozicijad);
int push(pozicijasd, pozicijad);
pozicijad pop(pozicijasd);
int forbiddenstogprint(pozicijasd, pozicijad);


