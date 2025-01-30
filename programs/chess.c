#include<stdio.h>

int main(){
    char first,second;
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i%2==0){
                first='B';
                second='W';
            }else{
                 first='W';
                second='B';
            }
            if(j%2==0) printf(" %c   ",first);
            else printf(" %c  ",second);
        }
        printf("\n\n");
    }

}