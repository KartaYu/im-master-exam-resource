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
		int pivot = arr[front];//front當pivot
		int i = front + 1;//頭從front的下一個開始
		int j = end;//尾從end開始
		while (i <= j){ //一定要大於等於
			while (arr[j] > pivot) j--;
			while (arr[i] <= pivot) i++;// j為交換的位置，一定要比pivot大，所以大於等於
			if (i < j)//還沒交錯
				swap(&arr[i], &arr[j]);
		}

		swap(&arr[front], &arr[j]); //j頂多到piovt(front)就會停，但i可能會超出array range，所以選j
		QuickSort(arr, front, j - 1);
		QuickSort(arr, j + 1, end);
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


