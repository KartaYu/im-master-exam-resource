//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/comparison-sort-heap-sortdui-ji-pai-xu-fa.html
// Reference   : https://www.geeksforgeeks.org/heap-sort/
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void Merge(int Array[], int front, int mid, int end) {
	int n1 = mid - front + 1;
	int n2 = end - mid;
	int LeftSub[n1], RightSub[n2];

	for(int i = 0; i < n1; i++){
		LeftSub[i] = Array[front + i];
	}
	for(int i = 0; i < n2; i++){
		RightSub[i] = Array[mid+1+i];
	}

	int i = 0, j = 0, k = front;

	while (i < n1 && j < n2) {
		if (LeftSub[i] <= RightSub[j]) {
			Array[k] = LeftSub[i];
			i++;
		} else {
			Array[k] = RightSub[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		Array[k] = LeftSub[i];
		i++;
		k++;
	}

	while (j < n2) {
		Array[k] = RightSub[j];
		j++;
		k++;
	}
}

void MergeSort(int array[], int front, int end) {
	// front與end為矩陣範圍
	if (front < end) {                   // 表示目前的矩陣範圍是有效的
		int mid = (front + end) / 2;         // mid即是將矩陣對半分的index
		MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
		MergeSort(array, mid + 1, end);    // 繼續divide矩陣的後半段subarray
		Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << std::endl;
}

int main() {
	int arr[] = { 9, 9, 1, 6, 0, 3, 8, 2, 5 };
	//int arr[] = { 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0 };
	//int arr[] = { 11, 1, 2, 3, 4, 5, 6, 7, 8, 12, 10, 0};
	//int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "original:\n";
	PrintArray(arr, arr_size);

	MergeSort(arr, 0, arr_size - 1);
	cout << "sorted:\n";
	PrintArray(arr, arr_size);

	return 0;
}
