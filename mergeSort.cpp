#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int first,int last, int mid){
    int n1 = mid-first + 1;
    int n2 = last - mid;
    
    int a[n1];
    int b[n2];
    
    for(int i=0;i<n1;i++){
        a[i] = arr[first+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }
    
    int i=0,j=0,k=first;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    
    while(i < n1){
        arr[k++] = a[i++];
    }
    while(j < n2){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[],int first,int last){
    if(first < last){
        int mid = (first + last) / 2;
        mergeSort(arr,first,mid);
        mergeSort(arr,mid+1,last);
        
        merge(arr,first,last,mid);
    }
}

int main(){
    int arr[] = {5,4,1,3,2,1};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}
