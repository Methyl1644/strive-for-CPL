#include <stdio.h>
/*
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a&b);
    printf("%d\n",a|b);
    printf("%d\n",a^b);
    printf("%d\n",~a);
    printf("%d\n",a<<b);
    printf("%d\n",a>>b);
    printf("%d\n",(a<<(b-1))%2);
    int x=0;
    while (a!=0) {
        if (a%2==1)
            x++;
        a /=2;
    }
    printf("%d\n",x);

    return 0;
}*//*
int main() {
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    int A[m][n];
    int B[n][p];
    int C[m][p];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&A[i][j]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<p;j++) {
            scanf("%d",&B[i][j]);
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<p;j++) {
            int s=0;
            for (int k=0;k<n;k++) {
                s +=A[i][k]*B[k][j];
            }
            printf("%d ",s);
        }
        printf("\n");
    }
    return 0;
}*//*
int main() {
    int a[9][9];
    int N=0,N1=0,N2=0,N3=0,P=1;
    for (int i=0;i<9;i++) {
        int used[10]={0};
        for (int j=0;j<9;j++) {
            if (used[a[i][j]]!=0)
                printf("NO");P=0;
            used[a[i][j]]=1;
        }
    }
    while (P){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            scanf("%d",&a[i][j]);
            if (a[i][j]>9||a[i][j]<0)
                N++;break;
        }
    }
    if (N)
        printf("NO");
    else {
        for (int i=0;i<9;i++) {
            int s=0;int c=1;
            for (int j=0;j<9;j++) {
                s +=a[i][j];
                c *=a[i][j];

                if (s!=45||c!=362880)
                    N1++;break;
            }
        }
        if (N1!=0)
            printf("NO");
        else {
            for (int i=0;i<9;i++) {
                int s=0;int c=1;
                for (int j=0;j<9;j++) {
                    s +=a[j][i];
                    c *=a[j][i];
                }
                if (s!=45||c!=362880)
                    N2++;break;
            }
            if (N2!=0)
                printf("NO");
            else{
                for (int i=0;i<9;i +=3) {
                    int s=0;int c=1;
                    for (int j=0;j<9;j +=3) {
                        s=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                        c=a[i][j]*a[i][j+1]*a[i][j+2]*a[i+1][j]*a[i+1][j+1]*a[i+1][j+2]*a[i+2][j]*a[i+2][j+1]*a[i+2][j+2];
                        if (s!=45||c!=362880)
                            N3++;break;
                    }
                }
                if (N3!=0)
                    printf("NO");
                else
                    printf("YES");
            }
        }
    }
    }
    return 0;
}*//*
int main() {
    int S[18]={0,0,3,4,0,0,0,0,0,0,0,0,0,14,15,16,0,18};
    int n=0;
    scanf("%d",&n);
    for (int i=n;i>0;i--) {
        int A=-1;
        int B=0;
        int C=0;
        int k=0;
        scanf("%d",&k);
        A=A&k;B=B|k;C=C^k;
        printf("%d %d %d\n",A,B,C);

    }
    return 0;
}*//*
#include <stdio.h>
#include <stdlib.h>

int main() {
    char res[10];
    long long low=1;
    long long high=4294967295;
    long long unsigned int guess;

    while (1) {
        guess=(high+low)/2;
        printf("%llu\n", guess);
        fflush(stdout);
        scanf("%s", res);

        switch (res[0]) {
            case 'G': {
                low=guess+1;
                break;
            }
            case 'L': {
                high=guess-1;
                break;
            }
            case 'E': return 0;
            case 'O': return 0;
        }
    }
    return 0;
}*//*
#include <stdio.h>
int main() {
    int n=0;
    scanf("%d",&n);
    char A[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf(" %c",&A[i][j]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (A[i][j]=='o') {
                int vectors[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{1,1},{1,-1},{-1,1},{-1,-1}};
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    if (A[newI][newJ] == '*')
                        count++;
                }
                printf("%d",count);
            }
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}*//*
int main() {
    int n;
    scanf("%d",&n);
    int A[n][n];
    int used[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            used[i][j]=0;
        }
    }
    int x=(n-1)/2;int y=0;int count=1;
    A[x][y]=1;used[x][y]=1;
    while (count<n*n) {
        count ++;
        int m=(x+1)%n;
        int t=y-1;
        if (t<0)
            t +=n;
        if (used[m][t]==1) {
            m -=1;t=(t+2)%n;
            if (m<0)
                m +=n;
        }
        A[m][t]=count;
        used[m][t]=1;
        x=m;y=t;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
/*
int A[502][502];
int C[130000];

int main() {
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            scanf(" %d",&A[i][j]);
        }
    }//n is row;m is line
    int N =(n*m)/2;
    int x1,x2,y1,y2;
    int X[130000][2];int Y[130000][2];

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                int k=A[i][j];
                    if (C[k]==0) {
                        X[k][0]=i;
                        Y[k][0]=j;
                        C[k]++;continue;
                    }
                    if (C[k]==1) {
                        X[k][1]=i;
                        Y[k][1]=j;
                        continue;
                    }
            }
        }


    for (int k=1;k<=N;k++) {
        x1=X[k][0];
        x2=X[k][1];
        y1=Y[k][0];
        y2=Y[k][1];
        //store the location
        int j1=y1;int j2=y2;
        bool p1=0;bool p2=0;
        while (j1>0) {
            if (A[x1][j1-1]!=0)
                break;
            else
                j1--;
        }
        if (j1==0)
            p1=1;
        if (p1) {
            while (j2>0) {
                if (A[x2][j2-1]!=0)
                    break;
                else
                    j2--;
            }
            if (j2==0)
                p2=1;
        }
        if (p2) {
            A[x1][y1]=0;A[x2][y2]=0;
            printf("%d ",k);
            continue;
        }//examine if left side is fluent
        j1 = y1;j2 = y2;
        p1=0;p2=0;
        while (j1<m) {
            if (A[x1][j1+1]!=0)
                break;
            else
                j1++;
        }
        if (j1==m)
            p1=1;
        if (p1) {
            while (j2<m) {
                if (A[x2][j2+1]!=0)
                    break;
                else
                    j2++;
            }
            if (j2==m)
                p2=1;
        }
        if (p2) {
            A[x1][y1]=0;A[x2][y2]=0;
            printf("%d ",k);
            continue;
        }//examine if right side is fluent
        int i1=x1;int i2=x2;
        p1 =0;p2= 0;
        while (i1>0) {
            if (A[i1-1][y1]!=0)
                break;
            else
                i1--;
        }
        if (i1==0)
            p1=1;
        if (p1) {
            while (i2>0) {
                if (A[i2-1][y2]!=0)
                    break;
                else
                    i2--;
            }
            if (i2==0)
                p2=1;
        }
        if (p2) {
            A[x1][y1]=0;A[x2][y2]=0;
            printf("%d ",k);
            continue;
        }//examine if high side is fluent
        i1 = x1;i2 = x2;
        p1 =0;p2= 0;
        while (i1<n) {
            if (A[i1+1][y1]!=0)
                break;
            else
                i1++;
        }
        if (i1==n)
            p1=1;
        if (p1) {
            while (i2<n) {
                if (A[i2+1][y2]!=0)
                    break;
                else
                    i2++;
            }
            if (i2==n)
                p2=1;
        }
        if (p2) {
            A[x1][y1]=0;A[x2][y2]=0;
            printf("%d ",k);
            continue;
        }//examine if low side is fluent

    }
    return 0;
}*/