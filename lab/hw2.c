#include <stdio.h>
#include <math.h>
 
int main (){
   float sd, av, x, f;
   scanf("%f %f %f", &sd, &av, &x);
   f = (1/(sd*sqrt(2*acos(-1))))*exp(-pow(x-av,2)/(2*pow(sd,2)));
   printf("%.6f\n", f);
   return 0;
}
