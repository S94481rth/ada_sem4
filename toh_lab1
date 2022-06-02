#include<stdio.h>
void toh(int n,char start,char aux,char dest){
    if( n == 0){
        return;
    }    
    else{
        toh(n-1,start,dest,aux);
        printf("%c -> %c \n",start ,dest);
        toh(n-1,aux,start,dest);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    toh(n,'A','B','C');
}
