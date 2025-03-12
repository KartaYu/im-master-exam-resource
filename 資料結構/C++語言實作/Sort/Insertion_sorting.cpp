//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/comparison-sort-insertion-sortcha-ru-pai-xu-fa.html
// 應用        : Kruskal演算法的最佳化，判斷是否有無cycle
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void PrintArray(int arr[], int size){
    for(int x = 0; x < size; x++)
    	cout << arr[x] << " ";
    cout << endl;
}

void InsertionSort(int *arr, int size){
	for(int i = 1; i < size; i++){//從index = 1 開始比
		int temp = arr [i];
		int j = i - 1;//從 i - 1 開始往前比較
		while(arr[j] > temp && j >= 0){ // 如果比目前的大則往後挪
			arr[j + 1] = arr[j]; // j 挪到 j + 1
			j--;// index 往前
		}
		arr[j + 1] = temp;// 第j個比欲插入之值小所以插入j + 1 位置
	}
}
int main() {
    int array[6] = { 5, 3, 1, 2, 6, 4 };
    std::cout << "original:\n";
    PrintArray(array, 6);

    InsertionSort(array, 6);

    std::cout << "sorted:\n";
    PrintArray(array, 6);
    return 0;

}
