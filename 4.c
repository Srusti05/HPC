#include <stdio.h>
#include<time.h>
#include<omp.h>
#include<stdlib.h>

void main(){
    int n, i;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    time_t st, et;
    double t_t;
    st=clock();
    int a=(int)malloc(n*sizeof(int));
    a[0]=0;
    a[1]=1;
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("id of thread used for calculatinf fibonacci series: 1\n");
            for(i=2; i<n; i++){
                a[i]=a[i-2]+a[i-1];
            }
        }
        
        #pragma omp single
        {
            printf("id of thread used for displaying fibonacci series: 2\n");
            for(i=0; i<n; i++){
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
    et=clock();
    t_t=((double)(et-st))/CLOCKS_PER_SEC;
    printf("Time taken:%f",t_t);
}
