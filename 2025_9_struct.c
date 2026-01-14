#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int compare(const void *a,const void *b) {
    int A = *(const int*)a;
    int B = *(const int*)b;
    return A - B;
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    int *a= malloc(n*4);
    for (int i=0;i<n;i++) {
        scanf("%d",a+i);
    }
    for (int i=0;i<q;i++) {
        int r;
        scanf("%d",&r);
        int *res = (int*)bsearch(&r,a,n,4,compare);
        if (res != NULL) {
            printf("%lld\n",res - a);
        }
        else
            printf("-1\n");
    }
    return 0;
}*//*
char A[10086];
char s[111];
char *array[10086];//类型一定要匹配！！！
int compare(const void *a,const void *b) {
    char **A = (char **)a;
    char **B = (char **)b;
    return strcmp(*A,*B);
}
int main() {
    scanf("%s",A);
    scanf("%s",s);
    char *token = strtok(A,s);
    int index = 0;
    while (token != NULL) {
        array[index] = token;
        index ++;
        token = strtok(NULL,s);
    }
    qsort(array,index,sizeof(char*),compare);
    for (int i=0;i<index;i++) {
        printf("%s\n",array[i]);
    }
    return 0;
}*/
struct team {
    char name[50];
    char member[11][25];
    int attack[12];
    int defence[12];
    int org[12];
};
int C1(const void *a,const void *b) {
    struct team *A = (struct team *)a;
    struct team *B = (struct team *)b;
    if ((A->attack[11])>(B->attack[11])) return -1;
    else if (A->attack[11]<B->attack[11]) return 1;
    else return 0;
}
int C2(const void *a,const void *b) {
    struct team *A = (struct team *)a;
    struct team *B = (struct team *)b;
    if ((A->defence[11])>(B->defence[11])) return -1;
    else if (A->defence[11]<B->defence[11]) return 1;
    else return 0;
}
int C3(const void *a,const void *b) {
    struct team *A = (struct team *)a;
    struct team *B = (struct team *)b;
    if ((A->org[11])>(B->org[11])) return -1;
    else if (A->org[11]<B->org[11]) return 1;
    else return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    struct team *T = (struct team *)malloc(n*sizeof(struct team));
    for (int i=0;i<n;i++) {
        scanf("%s",T[i].name);
        int A = 0;
        int D = 0;
        int O = 0;
        for (int j=0;j<11;j++) {
            scanf("%s",T[i].member[j]);
            scanf("%d",&T[i].attack[j]);
            A += T[i].attack[j];
            scanf("%d",&T[i].defence[j]);//不要忘了&&&&&&&&&&&&&&&&&！！！！！！！！！
            D += T[i].defence[j];
            scanf("%d",&T[i].org[j]);
            O += T[i].org[j];
        }
        T[i].attack[11] = A;
        T[i].defence[11] = D;
        T[i].org[11] = O;
    }
    qsort(T,n,sizeof(struct team),C1);
    for (int i=0;i<n;i++) {
        printf("%s ",T[i].name);
    }
    printf("\n");
    qsort(T,n,sizeof(struct team),C2);
    for (int i=0;i<n;i++) {
        printf("%s ",T[i].name);
    }
    printf("\n");
    qsort(T,n,sizeof(struct team),C3);
    for (int i=0;i<n;i++) {
        printf("%s ",T[i].name);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>/*
int X[22222];
int main() {
    int p1,p2;
    scanf("%d %d",&p1,&p2);
    char x[20];
    scanf("%s",x);
    int *a = malloc(p1*4+4);
    int *b = malloc(p2*4+4);
    for (int i = 0 ;i <= p1;i++) {
        scanf("%d",a+i);
    }
    for (int i = 0 ;i <= p2;i++) {
        scanf("%d",b+i);
    }
    //P1+P2
    if (p1>p2) {
        for (int i=0;i<=p1;i++) {
            if (i<p1-p2) {
                if (i == 0) {
                    if (*a == -1) printf("-");
                    else if (*a != 1) printf("%d",*a);
                    else if (*a == 0) continue;
                }
                else {
                    if (*(a+i)>1) printf("+%d",*(a+i));
                    else if (*(a+i)==1) printf("+");
                    else if (*(a+i)==0) continue;
                    else if (*(a+i)==-1) printf("-");
                    else printf("%d",*(a+i));
                }
                if (p1-i>0) printf("%s",x);
                if (p1-i>1) printf("^%d",p1-i);
            }
            else if (i<p1){
                if ((*(a+i)+*(b+i-p1+p2))>1) printf("+%d",*(a+i)+*(b+i-p1+p2));
                else if (*(a+i)+*(b+i-p1+p2)==1) printf("+");
                else if (*(a+i)+*(b+i-p1+p2)==0) continue;
                else if (*(a+i)+*(b+i-p1+p2)==-1) printf("-");
                else if (*(a+i)+*(b+i-p1+p2)==0) continue;
                if (p1-i>0) printf("%s",x);
                if (p1-i>1) printf("^%d",p1-i);
            }
            else {
                if ((*(a+i)+*(b+i-p1+p2))>0) printf("+%d",*(a+i)+*(b+i-p1+p2));
                else if (*(a+i)+*(b+i-p1+p2)==0) continue;
                else printf("%d",*(a+i)+*(b+i-p1+p2));
            }
        }
    }
    else if (p1<p2){
        for (int i=0;i<=p2;i++) {
            if (i<p2-p1||p2==p1) {
                if (i == 0) {
                    if (*b == -1) printf("-");
                    else if (*b != 1) printf("%d",*b);
                    else if (*b == 0) continue;
                }
                else {
                    if (*(b+i)>1) printf("+%d",*(b+i));
                    else if (*(b+i)==1) printf("+");
                    else if (*(b+i)==0) continue;
                    else if (*(b+i)==-1) printf("-");
                    else printf("%d",*(b+i));
                }
                if (p2-i>0) printf("%s",x);
                if (p2-i>1) printf("^%d",p2-i);
            }
            else if (i<p2){
                if ((*(b+i)+*(a+i-p2+p1))>1) printf("+%d",*(b+i)+*(a+i-p2+p1));
                else if (*(b+i)+*(a+i-p2+p1)==1) printf("+");
                else if (*(b+i)+*(a+i-p2+p1)==0) continue;
                else if (*(b+i)+*(a+i-p2+p1)==-1) printf("-");
                else printf("%d",*(b+i)+*(a+i-p2+p1));
                printf("%s",x);
                if (p2-i>1) printf("^%d",p2-i);
            }
            else {
                if ((*(b+i)+*(a+i-p2+p1))>0) printf("+%d",*(b+i)+*(a+i-p2+p1));
                else if ((*(b+i)+*(a+i-p2+p1))==0) continue;
                else printf("%d",*(b+i)+*(a+i-p2+p1));
            }
        }
    }
    else {
        for (int i=0;i<=p1;i++) {
            if (i==0) {
                if (*b+*a == -1) printf("-");
                else if (*b+*a != 1) printf("%d",*b);
                else if (*b+*a == 0) continue;
                printf("%s",x);
                if (p1-i>1) printf("^%d",p1-i);
            }
            else if (i<p1) {
                if ((*(b+i)+*(a+i))>1) printf("+%d",*(b+i)+*(a+i));
                else if (*(b+i)+*(a+i)==1) printf("+");
                else if (*(b+i)+*(a+i)==0) continue;
                else if (*(b+i)+*(a+i)==-1) printf("-");
                else printf("%d",*(b+i)+*(a+i));
                printf("%s",x);
                if (p2-i>1) printf("^%d",p2-i);
            }
        }
    }
    printf("\n");
    //P1-P2
    if (p1>p2) {
        for (int i=0;i<=p1;i++) {
            if (i<p1-p2) {
                if (i == 0) {
                    if (*a == -1) printf("-");
                    else if (*a != 1) printf("%d",*a);
                }
                else {
                    if (*(a+i)>1) printf("+%d",*(a+i));
                    else if (*(a+i)==1) printf("+");
                    else if (*(a+i)==0) continue;
                    else if (*(a+i)==-1) printf("-");
                    else printf("%d",*(a+i));
                }
                if (p1-i>0) printf("%s",x);
                if (p1-i>1) printf("^%d",p1-i);
            }
            else if (i<p1){
                if ((*(a+i)-*(b+i-p1+p2))>1) printf("+%d",*(a+i)-*(b+i-p1+p2));
                else if (*(a+i)-*(b+i-p1+p2)==1) printf("+");
                else if (*(a+i)-*(b+i-p1+p2)==0) continue;
                else if (*(a+i)-*(b+i-p1+p2)==-1) printf("-");
                else printf("%d",*(a+i)-*(b+i-p1+p2));
                printf("%s",x);
                if (p1-i>1) printf("^%d",p1-i);
            }
            else {
                if ((*(a+i)-*(b+i-p1+p2))>0) printf("+%d",*(a+i)-*(b+i-p1+p2));
                else if ((*(a+i)-*(b+i-p1+p2))==0) continue;
                else printf("%d",*(a+i)-*(b+i-p1+p2));
            }
        }
    }
    else {
        for (int i=0;i<=p2;i++) {
            if (i<p2-p1) {
                if (i == 0) {
                    if (-*b == -1) printf("-");
                    else if (-*b != 1) printf("%d",*b);
                }
                else {
                    if (-*(b+i)>1) printf("+%d",*(b+i));
                    else if (-*(b+i)==1) printf("+");
                    else if (-*(b+i)==0) continue;
                    else if (-*(b+i)==-1) printf("-");
                    else printf("%d",-*(b+i));
                }
                if (p2-i>0) printf("%s",x);
                if (p2-i>1) printf("^%d",p2-i);
            }
            else if (i<p2){
                if ((-*(b+i)+*(a+i-p2+p1))>1) printf("+%d",-*(b+i)+*(a+i-p2+p1));
                else if (-*(b+i)+*(a+i-p2+p1)==1) printf("+");
                else if (-*(b+i)+*(a+i-p2+p1)==0) continue;
                else if (-*(b+i)+*(a+i-p2+p1)==-1) printf("-");
                else printf("%d",-*(b+i)+*(a+i-p2+p1));
                printf("%s",x);
                if (p2-i>1) printf("^%d",p2-i);
            }
            else {
                if ((-*(b+i)+*(a+i-p2+p1))>0) printf("+%d",-*(b+i)+*(a+i-p2+p1));
                else if ((-*(b+i)+*(a+i-p2+p1))==0) continue;
                else printf("%d",-*(b+i)+*(a+i-p2+p1));
            }
        }
    }
    printf("\n");
    //P1*P2

    for (int i=0;i<=p1;i++) {
        for (int j=0;j<=p2;j++) {
            X[p1-i+p2-j] += a[i]*b[j];
        }
    }
    for (int i=p1+p2;i>=0;i--) {
        if (i == p1+p2) {
            if (X[i] == -1) printf("-");
            else if (X[i] != 1) printf("%d",X[i]);
            printf("%s",x);
            printf("^%d",i);
        }
        else if (i>0) {
            if (X[i]>1) printf("+%d",X[i]);
            else if (X[i]==1) printf("+");
            else if (X[i]==0) continue;
            else if (X[i]==-1) printf("-");
            else printf("%d",X[i]);
            printf("%s",x);
            if (i>1) printf("^%d",i);
        }
        else {
            if (X[0]>0) printf("+%d",X[0]);
            else if (X[0]==0) continue;
            else printf("%d",X[0]);
        }
    }
    free(a);
    free(b);
    return 0;
}*//*
int X[22222];
int main() {
    int p1,p2;
    scanf("%d %d",&p1,&p2);
    char x[20];
    scanf("%s",x);
    int *a = malloc(p1*4+4);
    int *b = malloc(p2*4+4);
    for (int i = 0 ;i <= p1;i++) {
        scanf("%d",a+i);
    }
    for (int i = 0 ;i <= p2;i++) {
        scanf("%d",b+i);
    }
    int max = p1 > p2? p1 : p2;
    int first = 1;
    //P1+P2
    for (int i = 0;i <= max; i++) {
        int ca;
        if (max - i >p1) ca = 0;
        else ca = a[p1 - max + i];
        int cb = (max - i) <= p2 ? b[p2 - max + i] : 0;
        int c = ca + cb;
        if (c == 0) continue;
        if (first) {
            if (c == -1) printf("-");
            else if (c != 1) printf("%d",c);
            first = 0;
        }
        else {
            if (c > 1) printf("+%d",c);
            else if (c == 1) printf("+");
            else if (c == -1) printf("-");
            else printf("%d",c);
        }
        if (max - i > 0) printf("%s",x);
        if (max - i > 1) printf("^%d",max - i);
        if (max == i && (c == 1 || c == -1)) printf("1");
    }
    if (first) printf("0");
    printf("\n");
    //P1-P2
    first = 1;
    for (int i = 0;i <= max; i++) {
        int ca;
        if (max - i >p1) ca = 0;
        else ca = a[p1 - max + i];
        int cb = (max - i) <= p2 ? b[p2 - max + i] : 0;
        int c = ca - cb;
        if (c == 0) continue;
        if (first) {
            if (c == -1) printf("-");
            else if (c != 1) printf("%d",c);
            first = 0;
        }
        else {
            if (c > 1) printf("+%d",c);
            else if (c == 1) printf("+");
            else if (c == -1) printf("-");
            else printf("%d",c);
        }
        if (max - i > 0) printf("%s",x);
        if (max - i > 1) printf("^%d",max - i);
        if (max == i && (c == 1 || c == -1)) printf("1");
    }
    if (first) printf("0");
    printf("\n");
    //P1*P2
    first = 1;
    for (int i=0;i<=p1;i++) {
        for (int j=0;j<=p2;j++) {
            X[p1-i+p2-j] += a[i]*b[j];
        }
    }
    for (int i=p1+p2;i>=0;i--) {
        if (X[i]==0) continue;
        if (first) {
            if (X[i] == -1) printf("-");
            else if (X[i] != 1) printf("%d",X[i]);
            first = 0;
        }
        else {
            if (X[i]>1) printf("+%d",X[i]);
            else if (X[i]==1) printf("+");
            else if (X[i]==-1) printf("-");
            else printf("%d",X[i]);
        }
        if (i>0) printf("%s",x);
        if (i>1) printf("^%d",i);
        if (i == 0 &&(X[0] == 1 || X[i] == -1)) printf("1");
    }
    if (first) printf("0");
    free(a);
    free(b);
    return 0;
}*/