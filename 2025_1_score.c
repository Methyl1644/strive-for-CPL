#include <stdio.h>
#include <math.h>
/*int main() {
    int a=0;
    scanf("%d",&a);
    printf("%d %c",a,a);
    return 0;

}*/

#include <math.h>
/*int main() {
    double a=5280.0*5280.0*5280.0;
    double g=sqrt(61.0);
    double b=236674.0+30303.0*g;
    double c=b*b*b*a+744.0;
    double d=log(c);
    double e=sqrt(427.0);
    double f=d/e;
    double y=0;
    y=6.0*atan(1.0/8.0)+2.0*atan(1.0/57.0)+atan(1.0/239.0);
    printf("%.15f\n",f);
    printf("%.15f\n",4*y);
    return 0;

}*/
#include <stdio.h>
#include <math.h>

/*int main() {
    // 第一个公式计算π
    double term1 = pow(5280, 3);                  // 5280的三次方
    double sqrt61 = sqrt(61);                     // 计算√61
    double term2 = 236674 + 30303 * sqrt61;       // 236674 + 30303√61
    double term3 = pow(term2, 3);                 // 上面结果的三次方
    double inside_log = term1 * term3 + 744;      // 5280³(...)³ + 744
    double pi1 = log(inside_log) / sqrt(427);           // 最终公式计算

    // 第二个公式(Machin公式)计算π
    double arctan1_8 = atan(1.0 / 8);             // arctan(1/8)
    double arctan1_57 = atan(1.0 / 57);           // arctan(1/57)
    double arctan1_239 = atan(1.0 / 239);         // arctan(1/239)
    double pi2 = 4 * (6 * arctan1_8 + 2 * arctan1_57 + arctan1_239);

    // 输出结果，保留15位小数
    printf("%.15f\n", pi1);
    printf("%.15f\n", pi2);

    return 0;
}*/
/*int main() {
    float P,L,T;
    scanf("%f %f %f",&P,&L,&T);
    float V=L*L*L;
    printf("%.4g\n",P*V*(1/8.314)/T);
    return 0;
}*/
/*int main() {
    int xa,ya,xb,yb;
    scanf ("%d %d",&xa,&ya);
    scanf ("%d %d",&xb,&yb);
    double a=xa-xb;
    double b=ya-yb;
    double c=hypot(a,b);
    double arg=atan2(yb-ya,xb-xa);
    double r=arg*180.0;
    double pi=acos(-1.0);
    double angle=90.0-r/pi;
    printf("%.4f %.4f",c,fmod(angle+360,360));
    return 0;
}*//*
int main() {
    int p,q;
    scanf("%d %d",&p,&q);
    float m=q/2.0;
    float n=(p/3.0)*(p/3.0)*(p/3.0);
    float g=sqrt(m*m+n);
    float a=cbrtf(-m+g);
    float b=cbrtf(-m-g);
    float x=a+b;
    printf("%f %f %f %f %f %f\n",m,n,g,a,b,x);
    printf ("%.3f",x);
    return 0;
}*/
int main() {
    char name[20];
    int pre=0;
    double frac=0;
    double factor=1000.000000;
    char unit;
    scanf("%s %d %lf %lf %c",name,&pre,&frac,&factor,&unit);
    name[2]='\0';
    printf("%s: ",name);
    printf("%d ",pre);
    printf("(%.5lf) | ",frac);
    double sciEexp=pre+frac;
    printf("%.5E ",sciEexp);
    double conv=sciEexp*factor;
    printf("%.5lf ",conv);
    char U=unit-32;
    printf("%c",unit-32);
    return 0;




}
