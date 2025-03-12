//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort_1(int *arr, int n){ //左到右，先固定右邊(大->小)
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void bubble_sort_2(int *arr, int n){//右到左，先固定左邊(小->大)
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--){
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
		}
	}
}
void print(int arr[], int n) {
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[5] = { 64, 25, 12, 22, 11 };
	bubble_sort_1(arr, 5);
	int arr1[5] = { 64, 25, 12, 22, 11 };
	bubble_sort_2(arr1, 5);
	print(arr, 5);
	print(arr1, 5);
}
