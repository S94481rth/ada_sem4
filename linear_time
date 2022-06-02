#include<stdio.h>
#include<time.h>

void delay(){
    for(int i=0;i<1000;i++){
        
    }
}
int main(){
    int key=-1;
    int num = 1000;
    while(num < 100000){
        int array[num];
        clock_t start,end;
        
        for(int i=0;i<num;i++){
            array[i] = i;
        }
        start = clock();
        int k=0;
        while(key != array[k] && k < num){
            k++;
            delay();
        }
        end = clock();
        printf("%f\n",(double)(end-start)/ CLOCKS_PER_SEC); 
        num = num+1000;
    }
}
