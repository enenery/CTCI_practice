/*  Author: Erii Sugimoto
Date: 12/14/2016
Professor: Anna Salvati
Assignment: Project #3
Class: CSC 430
School: Borough of Manhattan Community College
File Name: Graph.cpp
Description Of the Program: An implementation file for Graph.h
*/
#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;

template <class x>
Graph<x>::Graph()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			edges[i][j] = p_infinity;
}

template <class x>
Graph<x>::~Graph()
{

	for (int i = 0; i < 100; i++)
	{
		vertices[i] = "";

		for (int j = 0; j < 100; j++)
			edges[i][j] = p_infinity;
	}

	numVertices = 0;
		
}

template <class x>
void Graph<x>::addVertex(x vertex)
{
	if(!isFull())
	vertices[numVertices++] = vertex;
	else
		cout << "\nYour graph is full.";
}


template <class x>
void Graph<x>::removeVertex(x vertex)
{
	if (!isEmpty())
	{
		int index;
		index = getIndexOfVertex(vertex);

		if (index != -1)
		{
			for (int i = 0; i < numVertices; i++)
			{
				edges[index][i] = p_infinity;

				for (int j = 0; j < numVertices; j++)
					edges[j][index] = p_infinity;
			}

			vertices[index] = "";
			numVertices--;
		}
		else
		{
			cout << "\nThe vertex you entered is not in your graph: ";
		}
	}
	else
	{
		cout << "\nYour graph is empty.";
	}
	
}

template <class x>
bool Graph<x>::doesThisVertexExist(x vertex)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (vertices[i] == vertex)
			return true;
	}

	return false;
}

template <class x>
void Graph<x>::addEdge(x vertex1, x vertex2, int weight)
{
	if (!doesThisVertexExist(vertex1) || !doesThisVertexExist(vertex2))
		cout << "\nError: one or more vertex you entered is not in your graph:";
	else
	{
		int row = getIndexOfVertex(vertex1);
		int column = getIndexOfVertex(vertex2);

		edges[row][column] = weight;
	}
}


template <class x>
void Graph<x>::removeEdge(x vertex1, x vertex2)
{
	int index1, index2;

	index1 = getIndexOfVertex(vertex1);
	index2 = getIndexOfVertex(vertex2);

	if (index1 == -1 || index2 == -2)
		cout << "\nOne or both vertices do not belong in the graph.";
	else
	{
		edges[index1][index2] = p_infinity;
	}
}

template <class x>
int Graph<x>::getIndexOfVertex(x vertex)
{
	for (int i = 0; i < numVertices; i++)
		if (vertices[i] == vertex)
			return i;

	return -1;
}

template <class x>
x Graph<x>::getVertexOfIndex(int index)
{
	x vertex;
	vertex = vertices[index];
	return vertex;
}

template <class x>
bool Graph<x>::isVisited(x vertex)
{
	int index = getIndexOfVertex(vertex);

	if (index == -1)
		cout << "\nThis vertex is not in the graph.";
	else
		return visitedVertices[index];

	return false;

}

template <class x>
void Graph<x>::cleanVisited()
{
	for (int i = 0; i < numVertices; i++)
		visitedVertices[i] = false;
}

template <class x>
void Graph<x>::markVisited(x vertex)
{
	int index;
	index = getIndexOfVertex(vertex);

	if (index == -1)
		cout << "\nThis vertex is not in the graph.";
	else
		visitedVertices[index] = true;
}

template <class x>
void Graph<x>::markVisited(int index)
{
	visitedVertices[index] = true;
}

template <class x>
void Graph<x>::getVertices(x vertex, queue<x> &q)
{
	int index = getIndexOfVertex(vertex);
	if(index == -1)
		cout << "\nThis vertex is not in the graph.";
	else
	{
		for (int i = 1; i < numVertices; i++)
			if (edges[index][i] < p_infinity)
				q.push(getVertexOfIndex(i));
	}
}

template <class x>
int Graph<x>::getNumVertices()
{
	return numVertices;
}

template <class x>
void Graph<x>::createCostArray(int(&cost)[100], int index)
{
	for (int i = 0; i < numVertices; i++)
		cost[i] = edges[index][i];
}

template <class x>
int Graph<x>::getCheapestIndex(int cost[])
{
	int initial = 0;
	bool found = false;
	int index = 0;
	while (index < numVertices && !found)
	{
		if (!visitedVertices[index])
		{
			found = true;
			initial = index;
		}
		index++;
	}

	for (int i = initial+1; i < numVertices; i++)
	{
		if (!visitedVertices[i])
			if(cost[initial] > cost[i])
			initial = i;
	}

	return initial;
}

template <class x>
int Graph<x>::getWeight(int index1, int index2)
{
	return edges[index1][index2];
}

template <class x>
bool Graph<x>::isAllVerticesVisited()
{
	for (int i = 0; i < numVertices; i++)
		if (visitedVertices[i] == false)
			return false;

	return true;
}

template <class x>
void Graph<x>::getNextVertex(x &vertex)
{
	int i = 0; bool found = false;

	while (i < numVertices && !found)
	{
		if (visitedVertices[i] == false)
		{
			found = true;
			vertex = getVertexOfIndex(i);
		}
		i++;
	}					
}

template <class x>
bool Graph<x>::isFull()
{
	return (numVertices == maxVertices);
}

template <class x>
bool Graph<x>::isEmpty()
{
	return (numVertices == 0);
}