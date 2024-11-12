#include<stdio.h>
#include<stdlib.h>


typedef struct Polinom {
    int coff;
    int exp;
    struct Polinom* next;
}Polinom;

Polinom* Create(int coff, int exp) {
    Polinom* nE = NULL;
    nE = (Polinom*)malloc(sizeof(Polinom));
    if (nE == NULL) {
        printf("malloc failed exiting...");
        return NULL;
    }
    nE->next = NULL;
    nE->coff = coff;
    nE->exp = exp;
    return nE;
}

int InsertSorted(Polinom* Head, Polinom* nE) {

    Polinom* temp;
    temp = Head->next;

    if (temp == NULL) {
        Head->next = nE;
        return 0;
    }

    Polinom* predzam = Head;

    while (1) {
        if (nE->exp < temp->exp) {
            predzam = temp;
            temp = temp->next;
            if (temp == NULL) {
                predzam->next = nE;
                return 0;
            }
        }
        else if (nE->exp > temp->exp) {
            predzam->next = nE;
            nE->next = temp;
            return 0;
        }
        else if (nE->exp == temp->exp) {
            temp->coff = nE->coff + temp->coff;
            free(nE);
            return 0;
        }
 
    }

}

void PrintPolinom(Polinom Head) {
    
    while (1) {
        Head = *Head.next;
        printf("%dx^%d", Head.coff, Head.exp);
        if (Head.next == NULL) {
            printf("\n");
            return 0;
        }
        printf(" + ");
    }
}

void ZbrajanjePolinoma(Polinom p1, Polinom p2, Polinom* rj) {
    Polinom temp;
    Polinom* unos;
   
    while (p1.next != NULL && p2.next != NULL) {
        if (p1.exp > p2.exp) {
            unos = Create(p1.coff, p1.exp);
            InsertSorted(rj,unos);
            p1 = *p1.next;
        }
        else if (p1.exp < p2.exp) {
            unos = Create(p2.coff, p2.exp);
            InsertSorted(rj, unos);
            p2 = *p2.next;
        }
        else {
            int sum_coeff = p1.coff + p2.coff;
            if (sum_coeff != 0) {
                unos = Create(sum_coeff, p1.exp);
                InsertSorted(rj, unos);
            }
            p1 = *p1.next;
            p2 = *p2.next;
        }
    } 
    while (p1.next != NULL) {
        unos = Create(p1.coff, p1.exp);
        InsertSorted(rj, unos);
        p1 = *p1.next;
    }
    while (p2.next != NULL) {
        unos = Create(p2.coff, p2.exp);
        InsertSorted(rj, unos);
        p2 = *p2.next;
    }

}

int main() {

    Polinom p1;
    p1.next = NULL;
    Polinom* novi;

    novi = Create(3, 4);
    InsertSorted(&p1, novi);
    novi = Create(7, 2);
    InsertSorted(&p1, novi);
    novi = Create(3, 4);
    InsertSorted(&p1, novi);
    novi = Create(5, 7);
    InsertSorted(&p1, novi);
    novi = Create(-1, 2);
    InsertSorted(&p1, novi);

    PrintPolinom(p1);

    return 0;
}