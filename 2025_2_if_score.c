#include <stdio.h>/*
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int A=a*a;int B=b*b;int C=c*c;
    int p=a+b-c;int q=b+c-a;int r=a+c-b;
    int P=A+B-C;int Q=B+C-A;int R=A+C-B;
    if (p<=0||q<=0||r<=0) {
        printf("not triangle");
    }
    else if (a==b&&b==c) {
        printf("equilateral triangle");
    }
    else if (A==B+C||B==A+C||C==A+B) {
        printf("right triangle");
    }
    else if (P<0||Q<0||R<0) {
        if (a==b||b==c||c==a) {
            printf("obtuse isosceles triangle");
        }
        else printf("obtuse triangle");
    }
    else if (a==b||b==c||c==a) {
        printf("acute isosceles triangle");
    }
    else printf("acute triangle");
    return 0;
}*//*
int main() {
    int n=0;
    scanf("%d",&n);
    int N=2*n-1;
    int a[114514];
    for (int i=0;i<N;i++) {
        scanf("%d",&a[i]);
    }
    int b[1000]={0};
     for (int i=0;i<N;i++) {
         b[a[i]]++;
     }
     for (int j=0;j<1000;j++) {
         while (b[j]==1) {
             printf("%d",j);
             return 0;
         }
     }
    return 0;
 }*//*3
int main() {
    int n=0;
    scanf("%d",&n);
    int sum=0;
    int current=1;
    for (int i=1;i<=n;i++) {
        current=(current*i)%10007;
        sum=(sum+current)%10007;
    }
    printf("%d",sum);
    return 0;
}*//*4
int main() {
    int N=0;
    scanf("%d",&N);
    int A=N/100;int B=N%100;int C=B/10;int D=B%10;//A百位，C十位，D个位
    if (N==0) {
        printf("zero");
    }
    else if (N<=20) {
        switch (N) {
            case 1: printf("one"); break;
            case 2: printf("two"); break;
            case 3: printf("three"); break;
            case 4: printf("four"); break;
            case 5: printf("five"); break;
            case 6: printf("six"); break;
            case 7: printf("seven"); break;
            case 8: printf("eight"); break;
            case 9: printf("nine"); break;
            case 10:printf("ten"); break;
            case 11:printf("eleven"); break;
            case 12:printf("twelve"); break;
            case 13:printf("thirteen"); break;
            case 14:printf("fourteen"); break;
            case 15:printf("fifteen"); break;
            case 16:printf("sixteen"); break;
            case 17:printf("seventeen"); break;
            case 18:printf("eighteen"); break;
            case 19:printf("nineteen"); break;
            case 20:printf("twenty"); break;
            default:break;
        }
    }
   else if (N>=20&&N<=99) {
       switch (C) {
           case 2: printf("twenty"); break;
           case 3: printf("thirty"); break;
           case 4: printf("forty"); break;
           case 5: printf("fifty"); break;
           case 6: printf("sixty"); break;
           case 7: printf("seventy"); break;
           case 8: printf("eighty"); break;
           case 9: printf("ninety"); break;
           default:break;
       }
       switch (D) {
           case 1: printf("-one"); break;
           case 2: printf("-two"); break;
           case 3: printf("-three"); break;
           case 4: printf("-four"); break;
           case 5: printf("-five"); break;
           case 6: printf("-six"); break;
           case 7: printf("-seven"); break;
           case 8: printf("-eight"); break;
           case 9: printf("-nine"); break;
               default:break;
       }
   }
    else if (N==100||N==200||N==300||N==400||N==500||N==600||N==700||N==800||N==900) {
        switch (A) {
            case 1: printf("one hundred"); break;
            case 2: printf("two hundred"); break;
            case 3: printf("three hundred"); break;
            case 4: printf("four hundred"); break;
            case 5: printf("five hundred"); break;
            case 6: printf("six hundred"); break;
            case 7: printf("seven hundred"); break;
            case 8: printf("eight hundred"); break;
            case 9: printf("nine hundred"); break;
            default:break;
        }
    }
    else {
        switch (A) {
            case 1: printf("one hundred and"); break;
            case 2: printf("two hundred and"); break;
            case 3: printf("three hundred and"); break;
            case 4: printf("four hundred and"); break;
            case 5: printf("five hundred and"); break;
            case 6: printf("six hundred and"); break;
            case 7: printf("seven hundred and"); break;
            case 8: printf("eight hundred and"); break;
            case 9: printf("nine hundred and"); break;
            default:break;
        }
       if (B<=20) {
           switch (B) {
               case 1: printf(" one"); break;
               case 2: printf(" two"); break;
               case 3: printf(" three"); break;
               case 4: printf(" four"); break;
               case 5: printf(" five"); break;
               case 6: printf(" six"); break;
               case 7: printf(" seven"); break;
               case 8: printf(" eight"); break;
               case 9: printf(" nine"); break;
               case 10:printf(" ten"); break;
               case 11:printf(" eleven"); break;
               case 12:printf(" twelve"); break;
               case 13:printf(" thirteen"); break;
               case 14:printf(" fourteen"); break;
               case 15:printf(" fifteen"); break;
               case 16:printf(" sixteen"); break;
               case 17:printf(" seventeen"); break;
               case 18:printf(" eighteen"); break;
               case 19:printf(" nineteen"); break;
               case 20:printf(" twenty"); break;
               default:break;
           }

       }
      else {
          switch (C) {
              case 2: printf(" twenty"); break;
              case 3: printf(" thirty"); break;
              case 4: printf(" forty"); break;
              case 5: printf(" fifty"); break;
              case 6: printf(" sixty"); break;
              case 7: printf(" seventy"); break;
              case 8: printf(" eighty"); break;
              case 9: printf(" ninety"); break;
              default:break;
          }
          switch (D) {
              case 1: printf("-one"); break;
              case 2: printf("-two"); break;
              case 3: printf("-three"); break;
              case 4: printf("-four"); break;
              case 5: printf("-five"); break;
              case 6: printf("-six"); break;
              case 7: printf("-seven"); break;
              case 8: printf("-eight"); break;
              case 9: printf("-nine"); break;
              default:break;
          }
      }
    }

}*//*5
int main() {
    int N=0;
    scanf("%d",&N);
    int M=0;
    while (N!=495) {
        int A=N/100;int B=N%100;
        int C=B/10;int D=B%10;
        int S[3]={0};
        S[0]=A;S[1]=C;S[2]=D;
        int min=S[0];int max=S[2];
        for (int i=0;i<3;i++) {
            if (S[i]<min) {
                min=S[i];
            }
        }
        for (int i=0;i<3;i++) {
            if (S[i]>max) {
                max=S[i];
            }
        }
        int MAX=100*max+min;int MIN=max+100*min;
        int N1=MAX-MIN;
        if ((N-N1)>0) {
            M=M+N-N1;
        }
        N=N1;
    }
    printf("%d",M);
    return 0;
}*/
int main() {
    int n=0;
    scanf("%d",&n);
    int s[10086]={0};
    for (int i=0;i<(n+1);i++) {
        scanf("%d",&s[i]);
    }
    int stand=0;
    int t=0;
    for (int i=0;i<(n+1);i++) {

        if (stand<i) {
            int k=i-stand;
            t=t+k;
            stand=i;
        }
            stand=stand+s[i];


    }
    printf("%d",t);
}
