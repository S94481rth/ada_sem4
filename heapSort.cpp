#include<bits/stdc++.h>
using namespace std;

void swap(int *num1,int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";
}

int main(){
    int arr[] = {9,8,7,6,43,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    heapSort(arr,n);
    printArray(arr,n);
    return 0;
}
