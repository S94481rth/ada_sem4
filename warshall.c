#include<stdio.h>
#define v 4


void warshall(int arr[v][v]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
        
}

void display(int arr[v][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int arr[v][v] = {{0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0}};
    display(arr);
    warshall(arr);
    display(arr);
    return 0;
}
