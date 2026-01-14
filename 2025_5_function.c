#include <stdio.h>
#include <math.h>
/*int C(int i,int t) {
    int c=0;
    for (int j=0;j<i;j++) {
        c +=t*pow(10,j);
    }
    return c;
}

int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    int s=0;
    for (int i=1;i<=n;i++) {
        s +=C(i,t);
    }
    printf("%d",s);

    return 0;
}*/
/*
int A[2077];
int B[2077];

int search(int n,int C[2077]) {
    int l=0;
    for (int i=n-1;i>=0;i--) {
        if (C[i]<C[i-1])
            l++;
        else
            break;
    }
    return l+1;
}
int locate(int l,int n,int C[2077]) {
    int k=C[n-l-1];
    int p;
    int flag=0;
    for (int i=k+1;i<=n;i++) {
        for (int j=n-1;j>=n-l;j--) {
            if (C[j]==i) {
                p=j;flag=1;
                break;
            }
        }
        if (flag)
            break;
    }
    return p;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    int l=search(n,A);
    int p=locate(l,n,A);

    int temp=A[p];
    A[p]=A[n-l-1];
    A[n-l-1]=temp;

    for (int i=0;i<n;i++) {
        B[i]=A[i];
    }

    for (int i=n-1;i>=n-l;i--) {
        A[i]=B[2*n-l-1-i];
    }

    for (int i=0;i<n;i++) {
        printf("%d ",A[i]);
    }

    return 0;
}*/
/*
int A[5];
int isPrime(int x) {
    int flag = 1; // 1 表示该数是素数
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            flag = 0;
        }
    }
    return flag;
}
int reverse(int x) {
    int i=0;int r=0;
    while (x!=0) {
        A[i]=x%10;
        x /=10;
        i++;
    }
    for (int j=0;j<i;j++) {
        r +=A[j]*pow(10,i-1-j);
    }
    return r;
}
int main() {
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=2;i<=n;i++) {
        if (isPrime(i)) {
            int r=reverse(i);
            if (isPrime(r))
                sum++;
        }
    }
    printf("%d",sum);
    return 0;
}*//*
void p1(long long x) {
    if (x>0&&x<21) {
        switch (x) {
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
    if (x>20&&x<100) {
        int a=x/10;
        int b=x%10;
        switch (a) {
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
        if (b!=0) {
            switch (b) {
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
    if (x>=100&&x<1000) {
        int a,b,c,d;
    a=x%10;x /=10;
    c=x%10;d=x/10;
    switch (d) {
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
    if (a!=0||c!=0) {
        printf(" and ");
        int k=10*c+a;
        if (k>0&&k<21) {
            switch (k) {
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
        if (k>20&k<100) {
            int m=k/10;
            int n=k%10;
            switch (m) {
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
            if (n!=0) {
                switch (n) {
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
    }
    }
}


int main() {
    long long n;
    scanf("%lld",&n);
    if (n==0)
        printf("zero");
    if (n>0) {
         if (n<1000) {
               p1(n);
         }
        else if(n>=1000&&n<1000000){
            long long a,b;
            a=n/1000;b=n%1000;
            p1(a);
            printf(" thousand ");
            if (b!=0)
                p1(b);
        }
        else if (n>=1000000&&n<1000000000) {
            long long a,b,c;
            a=n%1000;n /=1000;
            b=n%1000;c=n/1000;
            p1(c);
            printf(" million ");
            if (b!=0) {
                p1(b);
                printf(" thousand ");
            }
            if (c!=0)
                p1(a);
        }
        else if (n>=1000000000&&n<1000000000000) {
            long long a,b,c,d;
            a=n%1000;n /=1000;
            b=n%1000;n /=1000;
            c=n%1000;d=n/1000;
            p1(d);
            printf(" billion ");
            if (c!=0) {
                p1(c);
                printf(" million ");
            }
            if (b!=0) {
                p1(b);
                printf(" thousand ");
            }
            if (c!=0)
                p1(a);
        }
    }
    if (n<0) {
        n=-n;
        printf("minus ");
        if (n<1000) {
            p1(n);
        }
        else if(n>=1000&&n<1000000){
            long long a,b;
            a=n/1000;b=n%1000;
            p1(a);
            printf(" thousand ");
            if (b!=0)
                p1(b);
        }
        else if (n>=1000000&&n<1000000000) {
            long long a,b,c;
            a=n%1000;n /=1000;
            b=n%1000;c=n/1000;
            p1(c);
            printf(" million ");
            if (b!=0) {
                p1(b);
                printf(" thousand ");
            }
            if (c!=0)
                p1(a);
        }
        else if (n>=1000000000&&n<1000000000000) {
            long long a,b,c,d;
            a=n%1000;n /=1000;
            b=n%1000;n /=1000;
            c=n%1000;d=n/1000;
            p1(d);
            printf(" billion ");
            if (c!=0) {
                p1(c);
                printf(" million ");
            }
            if (b!=0) {
                p1(b);
                printf(" thousand ");
            }
            if (c!=0)
                p1(a);
        }
    }
    return 0;
}*//*
int T(int x,int B) {
    int A[2]={0};
    int i=0;
    while (x!=0) {
        A[i]=x%10;
        x /=10;
        i++;
    }
    int p;
    p=A[0]+A[1]*B;

    return p;
}
int max(int x) {
    int a,b;
    a=x/10;
    b=x%10;
    if (a>b)
        return a;
    else
        return b;
}
int main() {
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    int f=1;
    for (int B=2;B<=40;B++) {
        if (B>max(p)&&B>max(q)&&B>max(r)) {
            int P,Q,R;
            P=T(p,B);Q=T(q,B);R=T(r,B);
            if (P*Q==R) {
                f=0;
                printf("%d",B);
                break;
            }
        }
    }
    if (f)
        printf("0");

    return 0;
}*/
/*
#include <stdio.h>

int A[1919810];
int B[1919810];
int la[1919810];
int sum[1919810];

int find(int A[1919810],int l,int B,int t) {
    if (t>A[l-1]+B) {
        return l-1;
    }
    else {
        int a=0;int b=l-1;
        while (a<b-1) {
            int m=(a+b)/2;
            if (A[m]+B==t){
                return m;
            }
            else if (A[m]+B<t) {
                a=m;

            }
            else {
                b=m;
            }
        }
        return a;
    }
}

int main() {
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);

    for (int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&B[i]);
    }

    int flag=1;
    int finish=0;

    for (int i=0;i<m;i++) {
        if (A[0]+B[i]>t) {
            sum[i]=0;
        }
        else {
            flag=0;
            int k=find(A,n,B[i],t);
            sum[i]=A[k]+B[i];
            if (sum[i]==t) {
                finish=1;
                printf("0");
                break;
            }

        }
    }
    if (flag) {
        printf("-1");
        return 0;
    }
    else if (finish) {
        return 0;
    }
    else {
        int max=0;
        for (int i=0;i<m;i++) {
            if (sum[i]>max)
                max=sum[i];
        }

        int ans=t-max;

        printf("%d",ans);

        return 0;
    }
}*/
/*
int main() {
    int A[7]={1,3,6,9,14,17,19};
    int k=find(A,7,0,14);
    printf("%d",k);
    return 0;
}
*/