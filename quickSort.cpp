#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int index1,int index2){
    int temp;
    temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void quickSort(int arr[],int first,int last){
    if(first >= last){
        return;
    }
    int num = arr[last];
    int ptr1 = first;
    int ptr2 = last;
    while(ptr1 < ptr2){
        while(arr[ptr1] <=  arr[last] && ptr1 < ptr2){
            ptr1++;
        }
        while(arr[ptr2] >= arr[last] && ptr1 < ptr2){
            ptr2--;
        }
        swap(arr,ptr1,ptr2);
    }
    swap(arr,ptr1,last);
    quickSort(arr,first,ptr1-1);
    quickSort(arr,ptr1+1,last);
}


void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
    cout<<"\n";
}

int main(){
    int arr[] = {5,4,3,2,1};
    printArray(arr,5);
    quickSort(arr,0,4);
    printArray(arr,5);
}
