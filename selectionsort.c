#include<stdio.h>
#include<time.h>
void selection_sort(int array[],int num){
    
    for(int i=0;i<num;i++){
        int smallest = 2147483647;
        for(int j=i;j<num;j++){
            if(array[j] < smallest){
                smallest = array[j];
            }
            array[i] = smallest;
        }
    }
}

int main(){
    int number_elements = 10; 
    while(number_elements < 100){
        int array[number_elements];
        for(int i=0;i<number_elements;i++){
            array[i] = number_elements -i;
        }
        clock_t start,end;
        start = clock();
        selection_sort(array,number_elements);
        end = clock();
        for(int i=0;i<number_elements;i++){
            printf("%d ",array[i]);
        }
        printf("\n");
        printf("%f \n",(double)(end-start)/(CLOCKS_PER_SEC));
        number_elements+=10;
    }
}
