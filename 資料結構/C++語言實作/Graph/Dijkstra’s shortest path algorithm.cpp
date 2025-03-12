//============================================================================
// Name        : C++_for_DSA_pratice.cpp
// Author      : G.D Yu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Reference   : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
//============================================================================
#include <limits.h>
#include <stdio.h>
#define V 9

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for(int i = 0; i < V; i++){//從所有結點中，選出未被拜訪且目前dist距離最小者
		if(sptSet[i] == false && min > dist[i])
			min = dist[i], min_index = i;
	}

	return min_index;//回傳結點index
}

void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	bool sptSet[V];//判斷是否被選過
	int dist[V];//最短距離

	for(int i = 0; i < V; i++){//初始化
		dist[i] = INT_MAX, sptSet[i] = false;
	}

	dist[src] = 0;//將src的dist設為0

	for(int i = 0; i < V; i++){//總共要跑v次
		int u = minDistance(dist, sptSet);//選出目前dist最小的v
		sptSet[u] = true;//設為已拜訪

		for(int j = 0; j < V; j++){//其他點與u之關係，相連或是不相連
			//如果dist為INT_MAX的話，
			//未被拜訪且有此路徑且dist不為無限大且經由u到j的距離比目前的dist[j]小
			if(!sptSet[j] && graph[u][j] && dist[u] != INT_MAX && dist[j] > dist[u] + graph[u][j])
				dist[j] = dist[u] + graph[u][j];
		}
	}
	printSolution(dist);

}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}



