#include<stdio.h>

int main(){
    int val;char c;
    printf("Enter the height of pattern: ");
    scanf("%d",&val);
    printf("Enter a single charachter: ");
    scanf(" %c",&c);
    
    for(int i=0;i<=val;i++){
        for(int j=0;j<val-1;j++){
            if(i==0 || i==val) {
                printf(" %c  ",c);
            }else{
                if(j==val-i-1){
                    printf(" %c  ",c);
                }else{
                    printf("    ");
                }
            }
        }
        printf("\n");
    }
}