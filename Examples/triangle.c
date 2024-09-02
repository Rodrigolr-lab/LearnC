#include <stdio.h>
#include <stdlib.h>

int main() {
    int fibbon_size = 9;
    int i, j;
    /* TODO: define the 2D pointer variable here */
    int ** pnumbers ;

    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = (int **) malloc( 3 * sizeof(int *));

    for(i = 0; i < fibbon_size; i++){
        for(j = 0; j <= i; j++){
            pnumbers[i] = (int *) malloc( (i+1) * sizeof(int));
        }
    }

    /* TODO: allocate memory for storing the individual elements in a row */
    // pnumbers[0] = (int *) malloc(1 * sizeof(int));
    // pnumbers[1] = (int *) malloc(2 * sizeof(int));
    // pnumbers[2] = (int *) malloc(3 * sizeof(int));

    // so faltava alocar dinamicamente os valores
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < fibbon_size; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < fibbon_size; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);
    return 0;
}



/*
 * 1
 * 11
 * 121
 */
