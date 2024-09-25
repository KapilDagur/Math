#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

//MATRIX 
int matrix[MAXSIZE][MAXSIZE];
int size;

void transpose(){
    int row;
    int col;
    int temp;

    for(row = 0; row < size; row++){
        for(col = size; col > row-1; col--){
            temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
}

void display(){
    int row;
    int col;
    for(row = 0; row < size; row++){
        for(col = 0; col < size; col++)
            printf("%d\t", matrix[row][col]);
        printf("\n");
    }
}


int main(int argc, char const *argv[])
{

    int row;
    int col;
    int count=1;
    //Init Matrix...
    size = 3;
    for(row = 0; row < size; row++)
        for(col = 0; col < size; col++)
            matrix[row][col] = count++;
    
    display();
    transpose();
    display();

    return 0;
}
