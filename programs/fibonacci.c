#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(){
    int val;
    printf("Enter the numder of elements to generated: ");
    scanf("%d",&val);
        int count=0, a=0,b=1,c=1;
        while(count++<val){
            printf("%d ",b);
            a=b;
            b=c;
            c=a+b;
            
        }

    
}