//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintArray(vector<int> &array) {
	for (auto x : array)
		cout << x << " ";
	cout << endl;
}

void MaxHeapify_R(vector<int> &array, int root, int n) {//n為總node數
	int largest = root; //先假設傳進來的root節點為最大值的index
	int l = root * 2 + 1;//左子點的index
	int r = root * 2 + 2;//右子點的index

	if (l < n && array[largest] < array[l])//確認有左子點(不超過總node數) 且 largest之值小於l之值
		largest = l;//largest存l的index
	if (r < n && array[largest] < array[r])//確認有右子點(不超過總node數) 且 largest之值小於r之值
		largest = r;//largest存r的index
	if(largest != root){//判斷目前最大值之index是否為node，不是表示還需需調整
		swap(array[largest], array[root]);//交換largest之值與root之值
		MaxHeapify_R(array, largest, n);//以交換完的largest index繼續向下調整
	}
}
void MaxHeapify_I(vector<int> &array, int root, int n) {//n為總node數
	int largest = array[root]; //先假設傳進來的root節點為最大值
	int j = root * 2 + 1;//左子點的index
	while(j < n){//確認子點是否存在
		if(j+1 < n){//確認有無右子點
			if(array[j] < array[j+1])//如果右子比左子大則換右子當j
				j = j + 1;
		}
		if(largest >= array[j])//如果root之值也比右子大，卻確定root為目前最大之值
			break;
		else{
			array[(j-1)/2] = array[j];//與j的值往上
			j = j * 2 + 1;//j換到j之左子點
		}
	}
	array[(j-1)/2] = largest;//有預先乘所以除回去就是欲放的index
}

void HeapSort(vector<int> &array) {
	for (int i = array.size() / 2 - 1; i >= 0; i--) {//從有子樹的節點中index最大之開始調整
		MaxHeapify_R(array, i, array.size());//調整目前的heap(遞迴版)
	}

	for(int i = array.size() - 1; i > 0; i--){
		swap(array[0], array[i]);//把目前最大值換到最後
		MaxHeapify_I(array, 0, i);//調整目前的heap(迭代版)
	}
}

int main() {
	//heap從0開始
	vector<int> arr = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };

	cout << "original:\n";
	PrintArray(arr);

	HeapSort(arr);

	cout << "sorted:\n";
	PrintArray(arr);

	return 0;

}
