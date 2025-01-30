#include<stdio.h>

int main(){
    int val;char c;
    printf("Enter the length of square: ");
    scanf("%d",&val);
    printf("Enter a single charachter: ");
    scanf(" %c",&c);
    for(int i=0;i<val;i++){
        for(int j=0;j<val;j++){
            if(i==0 || i==val-1 || j==0 || j==val-1){
                printf("%c  ",c);
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }

}