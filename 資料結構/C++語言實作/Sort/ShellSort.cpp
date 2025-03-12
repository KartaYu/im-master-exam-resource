//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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

void ShellSort(int *arr, int n) {
	int gap = n/2;
	while(gap > 0){
		bool flag = false;
		do{//每組內部做交換直到沒有交換發生為止
			flag = false;
			for(int i = 0; i < n - gap; i++){ //n - gap為最後一組倒數第二個index(邊際條件)，因為還會加gap到最後一個
				if(arr[i] > arr[i + gap]){
					swap(arr[i], arr[i+gap]);
					flag = true;
				}
			}
		}while(flag == true);
		gap /= 2;
	}
}

int main() {
	int n = 9;
	int arr[] = { 9, 4, 1, 6, 0, 3, 8, 2, 5 };
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 10, 11};
	std::cout << "original:\n";
	PrintArray(arr, n);

	ShellSort(arr, n);

	std::cout << "sorted:\n";
	PrintArray(arr, n);
	return 0;

}
