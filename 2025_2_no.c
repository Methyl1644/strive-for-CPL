#include <stdio.h>/*
int main(){
    int h,m;
    scanf("%d:%d",&h,&m);
    if(h<12&&h>0){
        printf("%02d:%02d a.m.\n",h,m);
    }
    else if(h==0){
        printf("12:%02d a.m.\n",m);
    }
    else if(h==12){
        printf("12:%02d p.m.\n",m);
    }
    else{
        h=h-12;
        printf("%02d:%02d p.m.\n",h,m);
    }
    return 0;
}*/
#include <stdio.h>/*
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int l=n+k;
    {if((n%4)!=0){
        printf("Normal year!\n");
    }
    else if((n%4)==0&&(n%100)!=0){
        printf("Leap year!\n");
    }
    else if((n%400)==0){
        printf("Leap year!\n");
    }
    else{
        printf("Normal year!\n");
    }}
    {if((l%4)!=0){
        printf("Normal year!\n");
    }
    else if((l%4)==0&&(l%100)!=0){
        printf("Leap year!\n");
    }
    else if((l%400)==0){
        printf("Leap year!\n");
    }
    else{
        printf("Normal year!\n");
    }}
    return 0;

}*/
#include <math.h>
/*
int main() {
    int n;
    double x;
    scanf("%lf %d",&x,&n);
    double S=0.00;
    for (double i=0;i<(n+1);i++) {
        double q=pow(-1,i);
        double w=pow(x,2*i+1);
        S +=(q*w)/(2*i+1);
    }
    S *=4;
    printf("%.10lf",S);
    return 0;
}*//*
int main() {
    int n=0;
    scanf("%d",&n);
    int max=n;int s=0;
    while (n!=1) {
        s++;
        if (n%2==1) {
           n=3*n+1;
            max>n ? (max=max) : (max=n);

        }
        else {
            n /=2;
            max>n ? (max=max) : (max=n);
        }
    }
    printf("%d %d",s,max);
    return 0;
}*//*
#include <string.h>
    int main() {
        int n;
        scanf("%d",&n);getchar();
        char a[19198100]={0};
        for (int i=0;i<n;i++) {
            scanf("%c",&a[i]);
        }
        int k=0;
        scanf("%d",&k);
        char b[19198100];
        strcpy(b,a);
        for (int i=0;i<k;i++) {
            a[i]=b[k-1-i];
        }
        for (int i=k;i<n;i++) {
            a[i]=b[n-1+k-i];
        }
        printf("%s",a);
        return 0;
    }*/
int main() {
    int n;
    scanf("%d",&n);
    if (n<2) {
        printf("0");
        return 0;
    }
    int prime[10000]={0};
    prime[0]=2;
    int k=0;int t=1;int i=3;
    for (i;i<=n;i++) {
        k=0;
        while (i%prime[k]!=0&&k<t) {
            k++;
        }
        if (k==t) {
            prime[t]=i;
            t++;
        }

    }
    printf("%d",t);
    return 0;
}