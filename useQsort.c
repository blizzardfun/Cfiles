#include <stdio.h>
#include <stdlib.h>
//==============================================
//integer compare function
int intcompare( const void *a, const void *b)
{ // +x for a > b   -x for a< b   0 for a== b

     return (*(int *)a - *(int *)b);
};
//=============================================
// character compare function
int charcompare( const void *a, const void *b)
{ // +1 for a > b   -1 for a< b   0 for a== b

     if (*(char *)a > *(char *)b) return 1;
     else if (*(char *)a < *(char *)b) return -1;
     else return 0;
};
//=============================================
// structure and structure compare function
typedef struct {
    int x;
    int y;
} point;


int pointcompare( const void *a, const void *b)
{   // sort order determine by x value only
    // +1 for a > b   -1 for a< b   0 for a== b

     if ((*(point *)a).x > (*(point *)b).x) return 1;
     else if ((*(point *)a).x < (*(point *)b).x) return -1;
     else return 0;
};

// arrays to sort
point pointValues[] = {1,2,9,8,3,4,8,7,4,5};
int intValues[] = {10,5,20,4,30,2,40,1};
char charValues[] = {"The smart fox"};

// ==================================================
// using qsort and function pointers-  sort integers, characters and user defined structures 
// sort order is determine by compare functions
int main () 
{
    int n;
    //sort integers
    qsort(intValues,8,sizeof(int),intcompare);
    // print the result
    for (n=0; n<8; n++)
        printf("%d ",intValues[n]);
    printf("\n");

    //sort characters
    qsort(charValues,13,sizeof(char),charcompare);
    // print result
    for (n=0; n<13; n++)
        printf("%c ",charValues[n]);
    printf("\n");

    // sort structures
    qsort(pointValues,5,sizeof(point),pointcompare);
    // print the result
    for (n=0; n<5; n++)
        printf("x= %d y= %d \n ",pointValues[n].x,pointValues[n].y);
}