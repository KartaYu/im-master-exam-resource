//============================================================================
// Name        : c++.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <array>
using namespace std;

void PrintArray(int arr[], int size) {
	for (int x = 0; x < size; x++)
		cout << arr[x] << " ";
	cout << endl;
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int arr[], int front, int end) {
	if (front < end) {
		int pivot = arr[front]; //end當pivot
		int i = front; // 可交換的index起始位置
		for(int j = front + 1; j <= end; j++){
			if(arr[j] <= pivot){//遇到比pivot小
			i++;//移動到下一個可交換的位置
				swap(&arr[i], &arr[j]);//交換
				
			}
		}
		swap(arr[i], arr[front]);//與pivot交換
		QuickSort(arr, front, i - 1);
		QuickSort(arr, i + 1, end);
	}

}

int main() {
	//int arr[] = { 9, 9, 1, 6, 0, 3, 8, 2, 5 };
	int arr[] = { 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0 };
	//int arr[] = { 11, 1, 2, 3, 4, 5, 6, 7, 8, 12, 10, 0};
	cout << "original:\n";
	PrintArray(arr,  sizeof(arr)/sizeof(arr[0]));


	QuickSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);

	cout << "sorted:\n";
	PrintArray(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;

}


