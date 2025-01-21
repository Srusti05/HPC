#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void multiply(int **A, int **B, int **C, int N, int parallel) {
    #pragma omp parallel for collapse(2) if(parallel)  // Parallelize if "parallel" is true
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int N;
    printf("Enter matrix size (e.g., 1000, 2000, 3000): ");
    scanf("%d", &N);

    // Dynamically allocate memory for matrices
    int *A = (int *)malloc(N * sizeof(int *));
    int *B = (int *)malloc(N * sizeof(int *));
    int *C = (int *)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize matrices A and B with 1, and C with 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    // Sequential multiplication
    clock_t start = clock();
    multiply(A, B, C, N, 0);  // Sequential multiplication
    clock_t end = clock();
    printf("Time taken for sequential multiplication: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Parallel multiplication using OpenMP
    start = clock();
    multiply(A, B, C, N, 1);  // Parallel multiplication
    end = clock();
    printf("Time taken for parallel multiplication (OpenMP): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
