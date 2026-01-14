#include <stdio.h>
/*
int A[10086];//value
int B[10086];//amount

int locate(int C[10086],int n) {
    int max=0;int x=0;
    for (int i=0;i<n;i++) {
        if (max<C[i]) {
            max=C[i];
            x=i;
        }
    }
    return x;
}

int main() {
    int n,L;
    scanf("%d%d",&n,&L);
    for (int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&B[i]);
    }

    int price=0;int V=0;
    while (V<L) {
        int x=locate(A,n);
        V +=B[x];
        if (V>L) {
            V=V-B[x];
            B[x]=L-V;
            V=L;
        }
        price +=A[x]*B[x];
        A[x]=0;B[x]=0;
    }

    printf("%d",price);

    return 0;
}*//*
#include <string.h>

char A[1145];
int top=0;
char s1[]="pop";
char s2[]="push";
char s3[]="top";
char s4[]="print";


int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        char str[9]="";
        scanf("%s",str);
        if (strcmp(str,s1)==0) {
            if (A[0]=='\0') {
                printf("Empty\n");
            }
            else {
                A[top-1]='\0';
                top--;
            }
        }
        else if (strcmp(str,s2)==0) {
            char input;
            scanf(" %c",&input);
            A[top]=input;
            top++;
        }
        else if (strcmp(str,s3)==0) {
            if (A[0]=='\0') {
                printf("Empty\n");
            }
            else {
                printf("%c\n",A[top-1]);
            }
        }
        else if (strcmp(str,s4)==0) {
            for (int k=top-1;k>=0;k--) {
                printf("| %c |\n",A[k]);
            }
            printf("|===|\n");
        }
    }
    return 0;
}*/
//单个%c是一个字符，使用&
//未定义长度的数组，比如A[]，你读入多少就是多长!!!!!!!!!!
#include <stdio.h>/*
char A[114514];
char B[114514];
int main() {
    int T;
    scanf("%d",&T);
    int flag=0;
    for (int i=0;i<=T;i++) {
        scanf("%[^\n]",A);getchar();
        if (flag) {
            int j=0;int k=0;
            while (A[j]!='\0') {
                if (A[j]=='('||A[j]=='['||A[j]=='{') {
                    B[k]=A[j];
                    k++;
                }
                else if (A[j]==')') {
                    if (B[k-1]=='(') {
                        B[k-1]='\0';
                        k--;
                    }
                }
                else if (A[j]==']') {
                    if (B[k-1]=='[') {
                        B[k-1]='\0';
                        k--;
                    }
                }
                else if (A[j]=='}') {
                    if (B[k-1]=='{') {
                        B[k-1]='\0';
                        k--;
                    }
                }
                j++;
            }
            if (B[0]=='\0')
                printf("True\n");
            else
                printf("False\n");
        }
        flag++;
    }

    return 0;
}*///scores:92 ,haven't AC
//记住，分数离满分不远时想想极端样例，比如只有某种东西的情况
/*
char A[514][114];
int boundary(char B[514][114],int i,int j,int R,int C) {
    int k=0;
    int p=i;int q=j;
    while (j-k>=0&&j+k<C&&i+k<R) {
        if (A[p+1][q-1]=='/'&&A[p+1][2*j-q+2]=='\\') {
            p++;q--;
            k++;
        }
        else
            break;
    }
    return k;
}
int main() {
    int R,C;
    scanf("%d%d",&R,&C);
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            scanf(" %c",&A[i][j]);
        }
    }
    long long ans=0;
    for (int i=0;i<R-1;i++) {
        for (int j=0;j<C-1;j++) {
            if(A[i][j] == '/' && A[i][j + 1] == '\\') {
                int k=boundary(A,i,j,R,C);
                for (int r=0;r<=k;r++) {
                    int f=0;int p=0;
                    while (p<=r) {
                        if (A[i+r+p+1][j-r+p]!='\\'||A[i+r+p+1][j+r-p+1]!='/'||i+r+p+1>=R) {
                            f=1;
                            break;
                        }
                        p++;
                    }
                    if (!f)
                        ans++;
                }
            }
        }
    }
    printf("%lld",ans);

    return 0;
}*/
/*for(int k = 1; ; k++) {
                    int bl = j - (k - 1);
                    if(bl < 0 || bl + 1 >= C || i + k >= R) break;
                    if(A[i + k][bl] != '\\' || A[i + k][bl + 1] != '/') break;
                    int ok = 1;
                    for(int p = 1; p < k; p++) {
                        int lc = j - (p - 1);
                        int rc = (j + 1) - (p - 1);
                        if(lc < 0 || rc >= C || A[i + p][lc] != '\\' || A[i + p][rc] != '/') {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok) ans++;
                    else break;
                }
                */
/*
int A[114514];
int B[114154];
int store(int x) {
    int i=1;
    while (x>i)
        i *=2;
    return i;
}
int main() {
    int n;int q;
    scanf("%d%d",&n,&q);
    A[0]=1;
    for (int i=0;i<n;i++)
        A[0] *=2;
    long long max=0;
    for (int i=0;i<q;i++) {
        char a;
        scanf(" %c",&a);
        if (a=='A') {
            int id,m;
            scanf("%d%d",&id,&m);
            int x=store(m);int f=1;
            while (f) {
                for (int p=max;p>=0;p--) {
                    if (A[p]==x&&B[p]==0) {
                        B[p]=id;f=0;
                        break;
                    }
                }//put it into A
                if (f) {
                    for (int p=max;p>=0;p--) {
                        if (A[p]>x&&B[p]==0) {
                            for (int j=max+1;j>p+1;j--) {
                                A[j]=A[j-1];
                                B[j]=B[j-1];
                            }
                            A[p] /=2;
                            A[p+1]=A[p];
                            B[p]=0;B[p+1]=0;
                            max++;
                            break;
                        }
                    }
                }//expand volume
            }
        }
        else if (a=='Q') {
            printf("%lld\n",max+1);
            for (int r=max;r>=0;r--) {
                printf("%d ",B[r]);
            }
            printf("\n");
        }
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int N, R, M, d[1000005];
long long D;

signed cmp(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

signed main() {
    scanf("%d%d%d%lld", &N, &R, &M, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
        if (d[i] >= R) N--, i--;  // remove useless data
    }
    qsort(d, N, sizeof(int), cmp);
    long long sum = 0;
    int L = -1;
    for (int i = N - 1; i >= 0; i--) {
        int cnt = N - i;
        sum += d[i];
        if (cnt < M) continue;
        L = max(L, min(d[i] - 1, (sum - D) / cnt));
    }
    printf("%d", L);
    return 0;
}

