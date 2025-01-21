#include <stdio.h>
#include <omp.h>

int main() {
    int n;  

    printf("Enter the number of items in each section: ");
    scanf("%d", &n);

    double clothing[n], gaming[n], grocery[n], stationary[n];
    double total_amount = 0.0;

    // Input prices for all sections
    printf("Enter prices for %d items in the Clothing section:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &clothing[i]);
    }

    printf("Enter prices for %d items in the Gaming section:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &gaming[i]);
    }

    printf("Enter prices for %d items in the Grocery section:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &grocery[i]);
    }

    printf("Enter prices for %d items in the Stationary section:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &stationary[i]);
    }


    double start_time = omp_get_wtime();

    // Parallel sum of all sections
    #pragma omp parallel for reduction(+:total_amount)
    for (int i = 0; i < n; i++) {
        total_amount += clothing[i] + gaming[i] + grocery[i] + stationary[i];
    }

    // End the timer
    double end_time = omp_get_wtime();

    // Output the total amount and time taken
    printf("The total amount to be paid is: %.2lf\n", total_amount);
    printf("Time taken for parallel processing: %.6f seconds\n", end_time - start_time);

    return 0;
}
