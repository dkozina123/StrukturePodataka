#include<stdio.h>

typedef struct Polinom{
    int coff;
    int exp;
    struct Polinom* next;
}Polinom;

Polinom* Create(int coff, int exp){
    Polinom* nE=NULL;
    nE=(Polinom*)malloc(sizeof(Polinom));
    *nE.next=NULL;
    *nE.coff=coff;
    *nE.exp=exp;
    return nE;
}

int InsertSorted(Polinom* Head,Polinom* nE){
    
    Polinom *temp;
    temp = *Head.next;

    while(temp != NULL && ){}


}

int main(){

    Polinom p1;


    return 0;
}