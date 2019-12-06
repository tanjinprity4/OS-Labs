#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 4

int matA[MAX][MAX]; 
int matB[MAX][MAX]; 

int matSumResult[MAX][MAX];
int matDiffResult[MAX][MAX]; 
int matProductResult[MAX][MAX];

typedef void* (*Operators)(void*);

void fillMatrix(int matrix[MAX][MAX]) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void printMatrix(int matrix[MAX][MAX]) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the sum of the
// values at the coordinates of matA and matB.
void* computeSum(void* args) {
    int *index = (int*) args;
    int row = (*index)/MAX;
    int col = (*index)%MAX;
	
    matSumResult[row][col] = matA[row][col] + matB[row][col];
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the difference of the
// values at the coordinates of matA and matB.
void* computeDiff(void* args) {
    int *index = (int*) args;
    int row = (*index)/MAX;
    int col = (*index)%MAX;
	
    matDiffResult[row][col] = matA[row][col] - matB[row][col];
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the inner product
// of matA and matB.
void* computeProduct(void* args) {
    int *index = (int*) args;
    int row = (*index)/MAX;
    int col = (*index)%MAX;
	
    matProductResult[row][col] = matA[row][col] * matB[row][col];
}

// Spawn a thread to fill each cell in each result matrix.
// How many threads will you spawn?
int main() {
    srand(time(0));  // Do Not Remove. Just ignore and continue below.
    
    // 1. Fill the matrices (matA and matB) with random values.
    fillMatrix(matA);
    fillMatrix(matB);
    
    // 2. Print the initial matrices.
    printf("Matrix A:\n");
    printMatrix(matA);
    printf("Matrix B:\n");
    printMatrix(matB);
    
    // 3. Create pthread_t objects for our threads.
    pthread_t objects[3][MAX*MAX];
    
    // 4. Create a thread for each cell of each matrix operation.
    // 
    // You'll need to pass in the coordinates of the cell you want the thread
    // to compute. One way to do this is to "encode" the coordinates into a number
    // and then pass it into the thread function. For example,
    // 
    // long coordinates = MAX*row + col;
    // 
    // Then the thread will have to "decode" that number back into the row and col.
    // 
    // Another option is to malloc memory for the coordinates, populate the coordinates
    // into that space, and pass that address to the thread. The thread will then have
    // to free that space when it's done with what's in that memory.
    
    Operators operations[3];
		operations[0] = &computeProduct;
    operations[1] = &computeSum;
    operations[2] = &computeDiff;
  
    for(int i = 0; i < 3; i++){
			for(int j = 0; j < MAX*MAX; j++){
        int *operation_id = (int*)malloc(sizeof(int));
        int *index = (int*)malloc(sizeof(int));
        *operation_id = i;
				*index = j; 
        
        pthread_create(&objects[*operation_id][*index], NULL, operations[*operation_id], (void*)index);
      }
    }
    // 5. Wait for all threads to finish.
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < MAX*MAX; j++){
        pthread_join(objects[i][j], NULL);
      }
    }
    
    // 6. Print the results.
    printf("Results:\n");
    printf("Sum:\n");
    printMatrix(matSumResult);
    printf("Difference:\n");
    printMatrix(matDiffResult);
    printf("Product:\n");
    printMatrix(matProductResult);
    return 0;
}