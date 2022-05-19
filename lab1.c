#include<stdio.h>

int search(int *array, int n, int key){
    int flag = 0 , index;
    for(int i=0;i<n;i++){
        if(key == array[i]){
            flag = 1;
            index = i;
            printf("found in position %d\n",i+1);
            break;
        }
    }
    return flag;
}



void bubble_sort(int *arr, int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array is : \n");
        
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
}



void lin(int * arr,int n){
    int key;
    printf("enter element to search : ");
    scanf("%d",&key);
    int found = search(arr, n ,key);
    if(found){
        printf("Element found\n");
    }else{
        printf("Not found!!\n");
    }
}

void accept(int *array, int n){
    printf("Enter elements : \n");
    for(int i=0;i<n;i++){
        printf("Element %d : ",(i+1));
        scanf("%d",&array[i]);
    }
}

void display(int *array, int n){
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(){
    int choice,n;    
    
    int arr[n];
    printf("Enter choice : \n1-enter\n2-display\n3-search\n4-sort\n");
    do{
        printf("Enter choice : ");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
            printf("Enter number of elements : ");
            scanf("%d",&n);
            accept(arr,n);
            break;
            
            case 2:
            display(arr,n);
            break;
            
            case 3:
            lin(arr,n);
            break;
            
            case 4:
            bubble_sort(arr,n);
            break;
        }
    }while(choice != 0);
}
