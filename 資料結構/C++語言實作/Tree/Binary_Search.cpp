//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int BS_R(int arr[], int key, int r, int l) {
	if (r > l)
		return -1;
	else {
		int mid = (l - r) / 2;

		if (arr[mid] == key)
			return mid;
		if (arr[mid] < mid)
			return BS_R(arr, key, r, mid - 1);
		else
			return BS_R(arr, key, mid + 1, l);
	}
}

int BS_I(int arr[], int key, int n) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (r - l) / 2;

		if (arr[mid] == key)
			return mid;
		if (arr[mid] < mid)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int main() {
	int arr[10] = { 1, 6, 12, 19, 22, 38, 49, 59, 78, 96 };
	cout << BS_R(arr, 12, 0, 9) << endl;
	cout << BS_I(arr, 12, 10) << endl;
}
