#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrixlib.h"

void countRow(int row, matrix_t* board);
void countCol(int col, matrix_t* board);

int main() {
    int rows, cols;
    matrix_t* picboard;
    time_t t;
    
    int seed;
    char setSeed;
    printf("Set seed manually? (Y/N): ");
    scanf("%s",&setSeed);
    if(setSeed == 'Y' || setSeed == 'y'){
    	printf("Give seed: ");
        scanf("%d",&seed);
    } else if (setSeed == 'N' || setSeed == 'n'){
    	seed = time(&t);
    }
    srand((unsigned) seed);
    printf("Seed utilized: %d\n",seed);
    
    printf("Enter rows: ");
    scanf("%d",&rows);
    assert(rows > 0);
    printf("Enter columns: ");
    scanf("%d",&cols);
    assert(cols > 0);
    
    picboard = matinit(rows,cols,0);
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            picboard->matrix[i][j] = (rand() % 2);
        }
    }
    
    printf("Rows:\n");
    for(int i = 0; i < rows; i++){
        countRow(i,picboard);
        printf("\n");
    }
    
    printf("\nCols:\n");
    for(int i = 0; i < cols; i++){
        countCol(i,picboard);
        printf("\n");
    }
    char showBoard;
    printf("Show resulting board? (Y/N) ");
    scanf("%s",&showBoard);
    if(showBoard == 'Y' || showBoard == 'y'){
        matprint(picboard);
    }
    return 0;
}

void countRow(int row, matrix_t* board){
    int count = 0;
    int streak = 0;
    for(int i = 0; i < board->cols; i++){
        if(board->matrix[row][i] == 0){
            if(streak > 0){
                count++;
                printf("%d ", streak);
                streak = 0;
            }
        } else {
            streak++;
        }
    }
    if(streak > 0){
        printf("%d ", streak);
    } else if(count == 0){
        printf("X");
    }
}

void countCol(int col, matrix_t* board){
    int count = 0;
    int streak = 0;
    for(int i = 0; i < board->rows; i++){
        if(board->matrix[i][col] == 0){
            if(streak > 0){
                count++;
                printf("%d ", streak);
                streak = 0;
            }
        } else {
            streak++;
        }
    }
    if(streak > 0){
        printf("%d ", streak);
    } else if(count == 0){
        printf("X");
    }
}
