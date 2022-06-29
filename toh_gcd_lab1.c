//tower of hanoi
#include<stdio.h>

void toh(char A,char B,char C,int n){
    if(n == 1){
        printf("Move from disk %c to %c\n",A,C);
    }
    else{
        toh(A,C,B,n-1);
        printf("Move from disk %c to %c \n",A,C);
        toh(B,A,C,n-1);
    }
}

int main(){
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    toh('S','A','D',n);
}



//GCD


#include<stdio.h>

int gcd(int num1,int num2){
    if(num2 == 0) return num1;
    gcd(num2,num1%num2);
}

int main(){
    int a,b;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    printf("GCD of these numbers is : %d",gcd(a,b));
}
