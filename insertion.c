
#include<time.h>
#include <stdio.h>


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);

	}    	printf("\n");
}


int main()
{
    int n = 100;


    while(n<10000){
        int arr[n];
        clock_t start,end;
        start = clock();
        for(int i=0;i<n;i++){
            arr[i] = n-i;
        }
        	insertionSort(arr, n);
        	//printArray(arr, n);
        	end = clock();
            printf("%f\n",(double)(end-start)/ CLOCKS_PER_SEC);
        	n = n +100;
    }
	



	return 0;
}
