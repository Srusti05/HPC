#include <stdio.h>
#include<time.h>
#include<omp.h>
#include<stdlib.h>

void main(){
    int n, i;
    printf("Enter the number of students:");
    scanf("%d",&n);
    time_t st, et;
    double t_t;
    st=clock();
    double a=(double)malloc(n*sizeof(double));
    double arr_max=0;
    #pragma omp for
    for(i=0; i<n; i++){
        srand(i);
        a[i]=(double)(rand()%100)/10;
    }
    
    printf("CGPA of students:\n");
    for(i=0; i<n; i++){
        printf("%.2lf ", a[i]);
    }
    
    #pragma omp for
    for(i=0; i<n; i++){
        #pragma omp critical
        if(arr_max < a[i]){
            arr_max=a[i];
        }
    }
    et=clock();
    printf("\nStudent with highest cgpa:%.2lf\n", arr_max);
    t_t=((double)(et-st))/CLOCKS_PER_SEC;
    printf("\n Time taken:%f\n",t_t);
}
