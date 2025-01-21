#include <stdio.h>
#include<time.h>
#include<omp.h>
#include<stdlib.h>

void main(){
    int num, i;
    printf("Enter the number of steps:");
    scanf("%d",&num);
    time_t st, et;
    double t_t;
    st=clock();
    double step=1.0/(double)num, pi=0.0;
    #pragma omp parallel for reduction(+:pi)
    for(i=0; i<num; i++){
        double x=(i+0.5)*step;
        double local_pi=(4.0*step)/(1+x*x);
        pi+=local_pi;
    }
    
    et=clock();
    t_t=((double)(et-st))/CLOCKS_PER_SEC;
    printf("\n Value of Pi:%.16lf\n",pi);
    printf("\n Time taken:%f\n",t_t);
}
