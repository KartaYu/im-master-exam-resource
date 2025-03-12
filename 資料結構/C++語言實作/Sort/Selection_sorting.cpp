//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int (&arr)[5], int n){
	for(int i = 0; i < n; i++){
		int m = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[m])
				m = j;
		}
		swap(&arr[i], &arr[m]);
	}
}

int main() {
	int arr[5] = {64, 25, 12, 22, 11};
	selection_sort(arr, 5);
	for(auto x : arr)
		cout << x << " " ;
}
