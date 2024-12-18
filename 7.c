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
start_time = MPI_Wtime(); 
if (rank == 0) { 
int i; 
printf("Before Scatter : sendbuf of rank 0 : "); 
for (i = 0; i < size; i++) { 
srand(i); 
sendbuf[i] = (float)(rand() % 1000) / 10; 
printf("%.1f ", sendbuf[i]); 
} 
printf("\nAfter Scatter :\n"); 
} 

MPI_Scatter(sendbuf, 1, MPI_FLOAT, &recvbuf, 1, MPI_FLOAT, 0, MPI_COMM_WORLD); 

printf("rank= %d Recvbuf: %.1f\n", rank, recvbuf); 
 
end_time = MPI_Wtime(); 

time_taken = end_time - start_time; 

if (rank == 0) { 
printf("Time taken for MPI_Scatter: %.6f seconds\n", time_taken); 
} 
MPI_Finalize(); 
}
