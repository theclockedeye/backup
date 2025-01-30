#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n;
    scanf("%d",&n);
    if(n<=2){
        printf("false");
        exit(1);
    }
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            printf("false");
            exit(1);
        }
    }
    printf("true");
}
