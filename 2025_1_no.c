#include <stdio.h>
#include <math.h>
/*int main() {
    int price=0;
    scanf ("%d",&price);
    printf("Price is %d",price);

    return 0;
}//*/
// Created by Methyl-intelligent on 2025/9/23.
/*int main() {
    double a=4*atan(1.0/5.0);
    double b=atan(1.0/239.0);
    double p1=a-b;
    double c=640320.0*640320.0*640320.0;
    double l=log(c+744);
    double s=sqrt(163.0);
    double p2=l/s;
    printf("%.15lf\n",4*p1);
    printf("%.15lf",p2);
    return 0;

}*/
int main() {
    double G=6.674e-11;
    double M=77.15;
    double m=0;
    double r=0;
    scanf("%lf %lf",&m,&r);
    double R=r*r;
    double y=G*M*m;
    double F=y/R;
    printf("%.4le",F);
    return 0;
}