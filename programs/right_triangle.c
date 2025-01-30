#include<stdio.h>

int main(){
    int val;char c;
    printf("Enter the height for pyramid: ");
    scanf("%d",&val);
    printf("Enter a single charachter: ");
    scanf(" %c",&c);
    for(int i=0;i<val;i++){
        for(int j=0;j<i+1;j++){
            printf(" %c",c);
        }
        printf("\n");
    }

}