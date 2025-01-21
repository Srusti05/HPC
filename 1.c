#include <stdio.h>
#include <omp.h>

int main() {
    int n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    double A[n][n], x[n], y[n];

    printf("Enter matrix A elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter vector x elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    for (int i = 0; i < n; i++)
        y[i] = 0.0;

    double start_time = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    double end_time = omp_get_wtime();

    printf("Result vector y:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f\n", y[i]);

    printf("Time taken: %.6f seconds\n", end_time - start_time);

    return 0;
}

