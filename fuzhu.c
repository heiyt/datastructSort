#include "main.h"

void showList(int list[],int n)
{
    static int i;
    for(i=0;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

void swap(int *a,int *b)
{
    static int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}


