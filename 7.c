#include <stdio.h> 
#include <stdlib.h> 
#include <mpi.h> 
int main(int argc, char* argv[]) 
{ 
int size, rank; 
MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
MPI_Comm_size(MPI_COMM_WORLD, &size); 
float recvbuf, sendbuf[100]; 
double start_time, end_time, time_taken; 
// Record start time 
start_time = MPI_Wtime(); 
if (rank == 0) { 
int i; 
printf("Before Scatter : sendbuf of rank 0 : "); 
for (i = 0; i < size; i++) { 
srand(i);  // seeding random number generator for different values on each process 
sendbuf[i] = (float)(rand() % 1000) / 10; 
printf("%.1f ", sendbuf[i]); 
} 
printf("\nAfter Scatter :\n"); 
} 
// Perform the scatter operation 
MPI_Scatter(sendbuf, 1, MPI_FLOAT, &recvbuf, 1, MPI_FLOAT, 0, MPI_COMM_WORLD); 
// Print the received data 
printf("rank= %d Recvbuf: %.1f\n", rank, recvbuf); 
// Record end time 
end_time = MPI_Wtime(); 
// Calculate time taken for scatter operation 
time_taken = end_time - start_time; 
// Only rank 0 will print the total time taken 
if (rank == 0) { 
printf("Time taken for MPI_Scatter: %.6f seconds\n", time_taken); 
} 
MPI_Finalize(); 
} 
