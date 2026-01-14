#include <stdio.h>
/*
int ans[1919810];

void find(int n,int min,int nFound) {
    if (n == 0) {
        for (int i = 0;i < nFound;i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    if (n < min) return;
    else {
        for (int i = min;i <= n;i++) {
            ans[nFound] = i;
            find(n - i, i ,nFound + 1);
        }
    }

}
int main() {
    int n;
    scanf("%d",&n);
    find(n,1,0);
    return 0;
}*/
#include <stdio.h>

int main(){
int n;
scanf("%d",&n);
if(n % 2 == 0){
int k = 1;
int m = n / 2;
for(int i = 0;i < m;i++){
k *= 2;
}
printf("%d",k);
}
else{
int k = 1;
int m = n / 2;
for(int i = 0;i <= m;i++){
k *= 2;
}
printf("%d",k);
}
return 0;
}