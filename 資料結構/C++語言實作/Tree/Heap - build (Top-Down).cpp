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
#include <math.h>
using namespace std;

void heapify_r(int arr[], int curr, int n) { //Recursive
	int par = curr/2;
	if(par > 0){
		if(arr[curr] > arr[par]){
			swap(arr[curr], arr[par]);
			heapify_r(arr, par, n);
		}
	}
}

void heapify_i(int arr[], int curr, int n) { //Iteration
	int par = curr/2, key = arr[curr];
	while(arr[par] < key && par > 0){ //記住要用key當比較基準
		if(key > arr[par]){
			arr[curr] = arr[par];
			curr = par;
			par = par/2;
		}
	}
	arr[curr] = key;
}

void buildheap(int arr[], int n) {
	for(int i = 1; i <= n; i++){
		heapify_i(arr, i, n);
		//heapify_r(arr, i, n);
	}
}
int main() {
	int arr[6] = { 0, 1, 3, 5, 7, 9 };
	buildheap(arr, 5);

	for (auto x : arr)
		cout << x << " ";
}


