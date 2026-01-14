#include <stdio.h>
int A[100][100];
int B[100][100];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    double num=n*m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&A[i][j]);//i for row;j for line
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&B[i][j]);//i for row;j for line
        }
    }
    double p=0.00;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==B[i][j])
                p++;
        }
    }
    double y=p/num;
    printf("%.2f",y*100);

    return 0;

}