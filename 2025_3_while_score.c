#include <stdio.h>
/*int main() {
    int n=0;
    scanf("%d",&n);getchar();
    char s[n];
    scanf("%s",s);
    for (int i=0;i<=(n-1);i++) {
        if (s[i]=='?') {
            s[i]=s[n-1-i];
        }
    }
    printf("%s",s);
    return 0;
}*//*
int main() {
    int n;scanf("%d",&n);
    int s[1644]={0};
    for (int i=1;i<=n;i++) {
        int k=i;
        while (k<=n) {
            s[k]=!s[k];
            k +=i;
        }

    }
    for (int j=1;j<=n;j++) {
        if (s[j]==1) {
            printf("%d ",j);
        }
    }
    return 0;
}*//*
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int r=0;
    for (int i=2;i<=n;i++) {
        r=(r+k)%i;
    }
    printf("%d",r);
    return 0;

}*//*
int main() {
    int T=0;
    scanf("%d",&T);
    for (int k=1;k<=T;k++) {
        int n;scanf("%d",&n);
        int a[114514];
        for (int t=0;t<n;t++) {
            scanf("%d",&a[t]);
        }
        int b[114154];
        for (int t = 0; t < n; t++) {
            b[t] = a[t];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (b[j] > b[j + 1]) {
                    int tmp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = tmp;
                }
            }
        }
        if (a[n-1]==b[n-1]) {
            printf("Yes\n");
        }
        else{printf("No\n");}
    }
return 0;
}*/
#include <math.h>
#include <string.h>
/*
int main() {
    int n;scanf("%d",&n);getchar();
    for (int i=1;i<=n;i++) {
        char a[16];
        scanf("%s",a);
        int l=strlen(a);
        int s=0;int check=0;
        for (int j=0;j<=l-1;j++) {
            check=0;
            switch (a[j]) {
                case '1': a[j]=1;s=s+a[j]*pow(3,l-1-j);break;
                case '0': a[j]=0;s=s+a[j]*pow(3,l-1-j);break;
                case 'Z': a[j]=-1;s=s+a[j]*pow(3,l-1-j);break;
                default: check++ ;break;
            }
            if (check>0) {
                printf("Radix Error\n");
                break;
            }
        }
        if (check>0) {continue;}

        printf("%d\n",s);
    }
    return 0;
}*/
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int main() {
    int n=0;scanf("%d",&n);getchar();
    for (int i=0;i<n;i++) {
        char a[20];scanf("%s",a);
        int l = strlen(a);
        int check = 0;
        int start = 0;
        if (l == 0) {
            check = 1;
        } else if (a[0] == '-') {
            start = 1;
            if (l == 1) {
                check = 1;
            }
        } else if (a[0] < '0' || a[0] > '9') {
            check = 1;
            }
        if (!check) {
            if (a[0] == '-' && l == 2 && a[1] == '0') {
                check = 1;
            }
            else if (a[start] == '0' && l > start + 1) {
                check = 1;
            }
        }
        if(!check) {
            for (int j = start; j < l; j++) {
                if (a[j] < '0' || a[j] > '9'){
                    check = 1;
                    break;
                }
            }
        }
        int A;
        if (check != 0) {
            printf("Radix Error\n");
        }

        else {A=atoi(a);
            if (A==0) {
            printf("0\n");
        }

        else if (A>0){
            char c[30];int j=0;int carry=0;
            while (A!=0||carry!=0) {
                int current= A%3 + carry;
                A /=3;
                carry=0;
                switch (current) {
                    case 0: c[j++]='0';break;
                    case 1: c[j++]='1';break;
                    case 2: c[j++]='Z';carry++;break;
                    case 3: c[j++]='0';carry++;break;
                }
            }
            c[j]='\0';
            for (int k=j-1;k>=0;k--) {
                printf("%c",c[k]);
            }
        }
        else {
            A=-A;
            char c[30];int j=0;int carry=0;
            while (A!=0||carry!=0) {
                int current= A%3 + carry;
                A /=3;
                carry=0;
                switch (current) {
                    case 0: c[j++]='0';break;
                    case 1: c[j++]='1';break;
                    case 2: c[j++]='Z';carry++;break;
                    case 3: c[j++]='0';carry++;break;
                }
            }
            c[j]='\0';
            for (int k=0;k<j;k++) {
                if (c[k]=='1')
                    c[k]='Z';
                else if (c[k]=='Z')
                    c[k]='1';

            }

            for (int k=j-1;k>=0;k--) {
                printf("%c",c[k]);
            }
        }
            printf("\n");
        }
    }
}*/
int main() {

}