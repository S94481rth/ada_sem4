#include<stdio.h>
#include<time.h>

void delay(){
    for(int i=0;i<10000;i++){}
}

//returns index of found element//
int binary_search(int array[],int key,int first,int last){
    delay();
    if(first < last){
        int middle = (first + last)/2;
        if(array[middle] == key){
            return middle;
        }
        else if(array[middle] > key){
            return binary_search(array,key,first,middle-1);
        }
        else{
            return binary_search(array,key,middle+1,last);
        }
        return -1;
    }
}

int main(){
    int number_of_elements=1000;//log1000=9.966
    clock_t start,end;
    while(number_of_elements < 1000000){//log1000000=19.93
        int array[number_of_elements];     
        for(int i=0;i<number_of_elements;i++){
            array[i] = i;
        }
        int key = number_of_elements+1;
        start = clock();
        int index = binary_search(array,key,0,number_of_elements-1);
        end = clock();
        number_of_elements+=1000;
        printf("%f \n",(double)(end-start)/CLOCKS_PER_SEC);
    }
    //expected ratio : ratio of time of first and last trial = 19.93/9.966 =2;
    //observed ratio : 0.000411/0.000235
}
