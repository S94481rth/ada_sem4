/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int left_right = 1;
int right_left = 0;

void swap(int* num1,int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int getPostion(int a[],int dir[],int mobile,int n){
    for(int i=0;i<n;i++){
        if(a[i] == mobile){
            return i+1;
        }
    }
    return -1;
}

int getMobile(int a[],int dir[],int n){
    int mobile=0;
    int prev_mobile =0 ;
    for(int i=0;i<n;i++){
        if(dir[a[i]-1] == right_left && i!=0){
            if(a[i] > a[i-1]){
                mobile = a[i];
                prev_mobile = mobile;
            }
        }
        
        if(dir[a[i]-1] == left_right && i!= n-1){
            if(a[i] > a[i+1]){
                mobile = a[i];
                prev_mobile = mobile;
            }
        }
    }
    
    return mobile;
    
}

void printNextPermutations(int a[],int dir[],int n){
    int mobile = getMobile(a,dir,n);
    int pos = getPostion(a,dir,mobile,n);
    
    if(dir[a[pos-1]-1] == right_left ) swap(&a[pos-1],&a[pos-2]);
    if(dir[a[pos-1]-1] == left_right) swap(&a[pos-1],&a[pos]);
    
    for(int i=0;i<n;i++){
        if(a[i] > mobile){
            if(dir[a[i]-1] == right_left){
                dir[a[i]-1] = left_right;
            }
            else if(dir[a[i]-1] == left_right){
                dir[a[i]-1] = right_left;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }cout<<"\n";
}
int fact(int n){
    int fact = 1;
    for(int i=n;i>0;i--){
        fact = fact*i;
    }return fact;
}
void permute(int n){
    int a[n];
    int dir[n];
    for(int i=0;i<n;i++){
        a[i] = i+1;
        cout<<a[i];
    }cout<<"\n";
    
    for(int i=0;i<n;i++){
        dir[i] = right_left;
    }
    
    for(int i=1;i<fact(n);i++){
        printNextPermutations(a,dir,n);
    }
}

int main()
{
    permute(4);
    
    return 0;
}
