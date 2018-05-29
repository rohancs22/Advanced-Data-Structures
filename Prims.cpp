//============================================================================
// Name        : Prims.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Graph
{
public:
	int GraphArray[10][10];
	int NoOfVertices;
	void readGraph();
	void printGraph();
	int Prims(Graph &);
};

void Graph::readGraph()
{
	cout<<"\nEnter no of vertices\n";
	cin>>NoOfVertices;
	cout<<"\nEnter Adjancy Matrix:\n";
	for(int i=0;i<NoOfVertices;i++)
	{
		for(int j=0;j<NoOfVertices;j++)
		{
			cin>>GraphArray[i][j];
		}
	}
}

void Graph::printGraph()
{
	for(int i=0;i<NoOfVertices;i++)
	{
		cout<<"\n";
		for(int j=0;j<NoOfVertices;j++)
		{
			cout<<" "<<GraphArray[i][j];
		}
	}
}

int Graph::Prims(Graph &spanning)
{
	int cost[10][10],distance[10],from[10],visited[10];
	int min_cost,min_distance,NoOfEdges;
	int u,v;
	for(int i=0;i<NoOfVertices;i++)
	{
		for(int j=0;j<NoOfVertices;j++)
		{
			if(GraphArray[i][j]==0)
			{
				cost[i][j]=1000;
			}
			else
			{
				cost[i][j]=GraphArray[i][j];
			}
			spanning.GraphArray[i][j]=0;
		}
	}

	distance[0]=0,visited[0]=1;
	for(int i=1;i<NoOfVertices;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}

	min_cost=0;
	NoOfEdges=NoOfVertices-1;

	while(NoOfEdges>0)
	{
		min_distance=1000;

			for(int i=1;i<NoOfVertices;i++)
			{
				if(visited[i]==0 && distance[i]<min_distance)
				{
					v=i;
					min_distance=distance[i];
				}
			}

			u=from[v];
			spanning.GraphArray[u][v]=distance[v];
			spanning.GraphArray[v][u]=distance[v];
			NoOfEdges--;

			visited[v]=1;

			for(int i=1;i<NoOfVertices;i++)
			{
				if(visited[i]==0 && cost[i][v]<distance[i])
				{
					distance[i]=cost[i][v];
					from[i]=v;
				}
			}

			min_cost=min_cost+cost[u][v];
	}
	spanning.NoOfVertices=NoOfVertices;
	return min_cost;
}


int main()
{
	Graph g,spanning;
	g.readGraph();
	int total_cost=g.Prims(spanning);
	cout<<"\nSpanning Matrix\n";
	spanning.printGraph();
	cout<<"\nTotal cost:"<<total_cost;
	return 0;
}
