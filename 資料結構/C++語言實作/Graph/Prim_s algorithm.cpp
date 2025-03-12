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

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)//還未被挑選且值小於min的index
            min = key[v], min_index = v;

    return min_index;
}


void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[V][V])
{
	int cost[V], parent[V];//cost記錄成本
	bool mstSet[V];

	for(int i = 0; i < V; i++){//初始化
		cost[i]= INT_MAX, mstSet[i] = false;
	}

	cost[0] = 0;
	parent[0] = -1;

	for(int count = 0; count < V - 1; count++){//扣掉起點總共要跑 V - 1次
		int u = minKey(cost, mstSet);
		mstSet[u] = true;

		//找出從u到與其他相連節點j最短的距離
		for(int j = 0; j < V; j++){
			if(graph[u][j] && mstSet[j] == false && graph[u][j] < cost[j])//有邊且還未被挑過且小於目前的cost
				cost[j] = graph[u][j], parent[j] = u;//更新與u相連且還沒被選過的頂點並更新最短距離

		}
	}
	printMST(parent, graph);
}

// Driver code
int main()
{
	/* Let us create the following graph
	   2     3
	(0)--(1)--(2)
	|    / \   |
   6|  8/   \5 |7
	|  /     \ |
	(3)-------(4)
			9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	primMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra


