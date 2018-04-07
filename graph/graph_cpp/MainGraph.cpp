/*  Author: Erii Sugimoto
Date: 12/14/2016
Professor: Anna Salvati
Assignment: Project #3
Class: CSC 430
School: Borough of Manhattan Community College
File Name: MainGraph.cpp
Description Of the Program: A main class for the Graph.h. Through a menu-driven output,
                            it allows user to add/delete vertices and add/delete edges and 
							to perform DFS/BFS/Shortest Path algorithms.
*/
#include "Graph.cpp"
#include <string>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void DFS(Graph<string> &graph, string start)
{
	queue<string> q;
	stack<string> s;
	graph.cleanVisited();
	string vertex;
	s.push(start);

	do {
		vertex = s.top();
		s.pop();

		if (!graph.isVisited(vertex))
		{
			cout << vertex << " ";
			graph.markVisited(vertex);
			graph.getVertices(vertex, q);

			while (!q.empty())
			{
				vertex = q.front();
				q.pop();
				if (!graph.isVisited(vertex))
					s.push(vertex);
			}
		}

		if (s.empty() && !graph.isAllVerticesVisited())
		{
			graph.getNextVertex(vertex);
			s.push(vertex);
		}
	} while (!s.empty());

}

void BFS(Graph<string> &graph, string start)
{
	queue<string> q1;
	queue<string> q2;
	graph.cleanVisited();
	string vertex1, vertex2;
	q1.push(start);
	do {
		vertex1 = q1.front();
		q1.pop();

		if (!graph.isVisited(vertex1))
		{
			std::cout << vertex1 << " ";
			graph.markVisited(vertex1);
			graph.getVertices(vertex1, q2);

			while (!q2.empty())
			{
				vertex2 = q2.front();
				q2.pop();
				if (!graph.isVisited(vertex2))
					q1.push(vertex2);
			}
		}

		if (q1.empty() && !graph.isAllVerticesVisited())
		{
			graph.getNextVertex(vertex1);
			q1.push(vertex1);
		}

	} while (!q1.empty());
}

void shortestPath(Graph<string> &graph, string start)
{
	graph.cleanVisited();
	int index;
	index = graph.getIndexOfVertex(start);
	if (index == -1)
		std::cout << "\nThe vertex you entered is not in the graph.";
	else
	{
		int cost[100];
		graph.createCostArray(cost, index);
		graph.markVisited(index);
		cost[index] = 0;
		int cheapestIndex;

		std::cout << "\nOriginal cost array: ";
		for (int k = 0; k < graph.getNumVertices(); k++)
			std::cout << cost[k] << " ";

		for (int i = 0; i < graph.getNumVertices() - 1; i++)
		{
			cheapestIndex = graph.getCheapestIndex(cost);
			graph.markVisited(cheapestIndex);

			if (cost[cheapestIndex] < 2147483600)
			{
				for (int j = 0; j < graph.getNumVertices(); j++)
				{
					if (!graph.isVisited(graph.getVertexOfIndex(j)))
					{
						if (cost[j] > (cost[cheapestIndex] + graph.getWeight(cheapestIndex, j)))						
							cost[j] = cost[cheapestIndex] + graph.getWeight(cheapestIndex, j);
					}

				}
			}
		}

		cout << "\nFinal cost array: ";
		for (int k = 0; k < graph.getNumVertices(); k++)
			cout << cost[k] << " ";

		cout << endl;
	}
}
void menu(Graph<string> &graph)
{
	int input;
	string vertex1;
	string vertex2;
	int weight;
	cout << "\n---------------------Welcome to a Graph Factory-----------------------";
	cout << "\n1. Add a vertex";
	cout << "\n2. Add an edge";
	cout << "\n3. Remove a vertex";
	cout << "\n4. Remove an edge";
	cout << "\n5. DFS";
	cout << "\n6. BFS";
	cout << "\n7. Shortest Path";
	cout << "\nEnter a number associated with your choice of operation (Enter 0 to end): ";
	cin >> input;

	if (input != 0)
	{
		do {
			switch (input)
			{
			case 1:
				cout << "\nEnter a name of your vertex in string: ";
				cin >> vertex1;
				graph.addVertex(vertex1);
				break;
			case 2:
				cout << "\nEnter the name of the vertex the edge is going out from: ";
				cin >> vertex1;
				cout << "\nEnter the name of the vertex the edge is going in to: ";
				cin >> vertex2;
				cout << "\nEnter the weight of the edge in integer: ";
				cin >> weight;
				graph.addEdge(vertex1, vertex2, weight);
				break;
			case 3:
				cout << "\nEnter a name of your vertex in string: ";
				cin >> vertex1;
				graph.removeVertex(vertex1);
				break;
			case 4:
				cout << "\nEnter the name of the vertex the edge is going out from: ";
				cin >> vertex1;
				cout << "\nEnter the name of the vertex the edge is going in to: ";
				cin >> vertex2;
				graph.removeEdge(vertex1, vertex2);
				break;
			case 5:
				cout << "\nEnter the name of the vertex to start with DFS: ";
				cin >> vertex1;
				DFS(graph, vertex1);
				break;
			case 6:
				cout << "\nEnter the name of the vertex to start with BFS: ";
				cin >> vertex1;
				BFS(graph, vertex1);
				break;
			case 7:
				cout << "\nEnter the name of the vertex to start with Shortest Path: ";
				cin >> vertex1;
				shortestPath(graph, vertex1);
				break;
			default:
				cout << "\nYour input is invalid: ";
				break;
			}

			cout << "\n1. Add a vertex";
			cout << "\n2. Add an edge";
			cout << "\n3. Remove a vertex";
			cout << "\n4. Remove an edge";
			cout << "\n5. DFS";
			cout << "\n6. BFS";
			cout << "\n7. Shortest Path";
			cout << "\nEnter a number associated with your choice of operation (Enter 0 to end): ";
			cin >> input;
		} while (input != 0);
	}
}
int main()
{
	Graph<string> friends;
	menu(friends);

	return 0;
}