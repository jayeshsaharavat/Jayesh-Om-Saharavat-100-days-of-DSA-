#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = 0;
    
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Top row
        for (int j = left; j <= right; j++) {
            result[(*returnSize)++] = matrix[top][j];
        }
        top++;
        
        // Right column
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        
        // Bottom row, if needed
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[(*returnSize)++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        // Left column, if needed
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}
