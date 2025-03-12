//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

////////////////////////////////////////////// Insert Node
void heapify_insert(int arr[], int i) { //i : 插入之index
	int parent = (i - 1) / 2, key = arr[i];
	bool flag = true;
	while (i > 0 && flag) {//當大於0才需要插入
		if (key > arr[parent]) {//key值比parent大
			arr[i] = arr[parent];//parent值較小 往下放
			i = parent;//下一個調整i之parent
			parent = (i - 1) / 2;//parent為i之parent
		} else {
			flag = false;
		}
	}

	arr[i] = key;
}
void heapify_insert_r(int arr[], int i) { //i : 插入之index
	int parent = (i - 1) / 2;
	if (arr[parent] < arr[i] && i > parent) {//當parent == i時 兩值皆為0 即可停止不用調整
		swap(arr[parent], arr[i]);
		heapify_insert_r(arr, parent);
	}
}

void insertNode(int arr[], int &n, int Key) {
	n = n + 1;
	arr[n - 1] = Key;
	//heapify_insert(arr, n - 1); //n - 1 為最後一個node之index
	heapify_insert_r(arr, n - 1); //n - 1 為最後一個node之index
}
////////////////////////////////////////////// Delete Node
void heapify_delete_i(int arr[], int n) {
	int key = arr[0], i = 0, j = i * 2 + 1; //i為parent j為child
	bool flag = true;
	while (j < n && flag) {//有子點存在
		if (j + 1 < n) {//有右子點存在
			if (arr[j] < arr[j + 1])//右子點比左子點大
				j = j + 1;
		}
		if (key < arr[j]) {//child比parent大
			arr[i] = arr[j];//child上挪
			i = j;//下一個調整的點設為子點
			j = i * 2 + 1;//子點的子點
		} else
			flag = false;
	}

	arr[i] = key;
}

void heapify_delete_r(int arr[], int n, int i) {
	int child = i * 2 + 1;
	if (child < n) {
		if (child + 1 < n) {
			if (arr[child] < arr[child + 1])
				child = child + 1;
		}
		if (arr[i] < arr[child]) {
			swap(arr[i], arr[child]);
			heapify_delete_r(arr, n, child);
		}
	}
	return;

}

void deleteRoot(int arr[], int &n) {
	if (n > 0) {//無node須調整即停止
		int last = arr[n - 1];
		arr[0] = last;
		arr[n - 1] = { };
		n = n - 1;
		heapify_delete_i(arr, n);
		//heapify_delete_r(arr, n, 0);
	} else
		cout << "No node can't be deleted" << endl;

}

////////////////////////////////////////////// Build Heapify
void build_heapify(int arr[], int root, int n) {
	int j = root * 2 + 1, temp = arr[root];
	bool flag = true;
	while (j < n && flag) {
		if ((j + 1) < n) {
			if (arr[j] < arr[j + 1])
				j = j + 1;
		}
		if (arr[j] > temp) {//記住要用temp當比較基準
			arr[root] = arr[j];
			root = j;
			j = j * 2 + 1;
		} else
			flag = false;
	}

	arr[root] = temp;
}

void build_heapify_r(int arr[], int root, int n) {
	int j = root * 2 + 1;
	if (j < n) {
		if (j + 1 < n) {
			if (arr[j] < arr[j + 1])
				j = j + 1;
		}

		if (arr[j] > arr[root]) {
			swap(arr[j], arr[root]);
			build_heapify_r(arr, j, n);
		}
	}
}

void printArray(int arr[], int n) {
	if (n <= 0) {
		cout << "No node" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
// Array representation of Max-Heap
//     10
//    /  \
//   5    3
//  / \
// 2   4
	int arr[100] = { 3, 4, 10, 2, 5 }, n = 5;	//目前Node數

	for (int i = (n - 1) / 2; i >= 0; i--)//bottom-up建立
		build_heapify(arr, i, n);

	printArray(arr, n);
	insertNode(arr, n, 15);
	printArray(arr, n);
	insertNode(arr, n, 23);
	printArray(arr, n);
	insertNode(arr, n, 7);
	printArray(arr, n);
	insertNode(arr, n, 100);
	printArray(arr, n);
	insertNode(arr, n, 6);
	printArray(arr, n);
	insertNode(arr, n, -1);
	printArray(arr, n);
	deleteRoot(arr, n);
	printArray(arr, n);
	deleteRoot(arr, n);
	printArray(arr, n);
	deleteRoot(arr, n);
	printArray(arr, n);

	return 0;
}

