//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V]; //father node

// Find set of vertex i
int find(int i)
{
	while(parent[i] != i){
		i = parent[i];
	}
	return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
	int mincost = 0;// Cost of min MST.
	for(int i = 0; i < V; i++){ // Initialize sets of disjoint sets.
		parent[i];
	}

	int edge_count = 0;

	while(edge_count < V - 1){//每回合挑出成本最小邊
		int a, b, min = INT_MAX;//用來storage最小邊的行列與cost
		for(int i = 0; i < V; i++){//讀取每個邊
			for(int j = 0; j < V; j++){
				if(find(i) != find(j) && cost[i][j] < min){//檢查是否在同一集合
					a = i;//設定行
					b = j;//設定列
					min = cost[i][j];//紀錄目前之最小cost
				}
			}
		}
		mincost += min;
		union1(a,b);//union找到之兩點
		printf("Edge %d:(%d, %d) cost:%d \n",
		               edge_count++, a, b, min);
	}
	printf("\n Minimum cost= %d \n", mincost);
}

// driver program to test above function
int main()
{
	/* Let us create the following graph
		2     3
	(0)---(1)---(2)
	 |   /   \   |
    6| 8/     \5 |7
	 | /	   \ |
	(3)---------(4)
		   9		 */
	int cost[][V] = {
		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
		{ 2, INT_MAX, 3, 8, 5 },
		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
		{ 6, 8, INT_MAX, INT_MAX, 9 },
		{ INT_MAX, 5, 7, 9, INT_MAX },
	};

	// Print the solution
	kruskalMST(cost);
	for(auto x : parent)
		cout << x << endl;

	return 0;
}

