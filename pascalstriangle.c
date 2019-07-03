#include <stdio.h>
#include <stdlib.h>

int main() {
    // print the first three rows of pascal's triangle
    // the purpose here was to practice memory allocation the values are just hard coded in
    // 
    int rows = 3;
    int i, j;
    /* define the pointer for the structure */
    int **pnumbers;

    /* allocate memory for holding three pointers to rows */
    pnumbers = (int **) malloc(rows * sizeof(int));

    /* allocate memory for storing the individual elements in a row */
    for (i=0; i< rows; i++){
    	pnumbers[i] = (int *) malloc((i + 1) * sizeof(int));
    }


    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    // print the triangle
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }
    // free the memory used
   for (i=0; i< rows; i++){
    	free(pnumbers[i] );
    }


   free(pnumbers);

  return 0;
}