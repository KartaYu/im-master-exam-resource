//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : http://alrightchiu.github.io/SecondRound/setyi-arraybiao-shi.html#set
// Application : Kruskal演算法的最佳化，判斷是否有無cycle
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int FindSetCollapsing(int *array, int i) { //先 Find 後Collapsing
	int root;
	for (root = i; array[root] >= 0; root = array[root]); //找root

	while (i != root) { //把i的所有parent做collapsing
		int parent = array[i]; //暫存i的parent index
		array[i] = root; //將i的parent設定為root
		i = parent; //把i換成i的parent 繼續collapsing
	}

	return root;

}

void UnionSet(int *array, int x, int y) {
	int x_root = FindSetCollapsing(array, x);
	int y_root = FindSetCollapsing(array, y);

	if (array[x_root] <= array[y_root]) {//先加在變換被併之root的值，因為原本的負值紀錄有多少個node
		array[x_root] += array[y_root];
		array[y_root] = x_root;
	} else {
		array[y_root] += array[x_root];
		array[x_root] = y_root;
	}
}

void PrintArray(int *array, int size){

    for (int i = 0; i < size; i++){
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;
}


int main() {
	const int size = 6;
	int array[size] = { -1, -1, -1, -1, -1, -1 };
	PrintArray(array, size);

	UnionSet(array, 1, 2);
	std::cout << "After union(1,2):\n";
	PrintArray(array, size);

	UnionSet(array, 0, 2);
	std::cout << "After union(0,2):\n";
	PrintArray(array, size);

	UnionSet(array, 3, 5);
	std::cout << "After union(3,5):\n";
	PrintArray(array, size);

	UnionSet(array, 2, 5);
	std::cout << "After union(2,5):\n";
	PrintArray(array, size);

	std::cout << "element(5) belongs to Set(" << FindSetCollapsing(array, 5)
			<< ").\n";
	std::cout << "After collapsing:\n";
	PrintArray(array, size);

	return 0;
}
