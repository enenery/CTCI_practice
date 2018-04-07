/*  Author: Erii Sugimoto
	Date: 12/14/2016
	Professor: Anna Salvati
	Assignment: Project #3
	Class: CSC 430
	School: Borough of Manhattan Community College
	File Name: Graph.h
	Description Of the Program: A graph class using adjacency matrix that lets the user to add/delete a vertex and an edge. 
								It also provides helper functions for the client to implement DFS/BFS/Shortest Path algorithms.
*/
#pragma once
#ifndef Graph_hpp
#define Graph_hpp
#include <queue>
using namespace std;

template <class x>
class Graph
{
private:
	x vertices[100]; //array of x type which contains vertices in a graph
	double edges[100][100]; //adjacency matrix which represents edges in a graph
	bool visitedVertices[100];//array of boolean type that keeps track of visited vertices in a graph for DFS/BFS/Shortest Path functions
	int numVertices = 0; //initial number of vertex in a graph
	int maxVertices = 100;//maximum number of vertices a graph is capable of carrying
	double p_infinity = 2147483600; 
	
public:
	Graph();	//constructor
	~Graph();	//destructor

	void addVertex(x vertex);	//a function to add a vertex to a graph
	void removeVertex(x vertex); // a function to remove a vertex as well as its associated eges from a graph 

	void addEdge(x vertex1, x vertex2, int weight); // a function to add a weighted edge to a graph
	void removeEdge(x vertex1, x vertex2); // a function to remove an edge from a graph

	bool doesThisVertexExist(x vertex);// a function that returns true if the paramter has an associated index in the int "vertices" array.

	// a function that returns the index of a parameter in the int "vertices" array; if a parameter is not found in the array, -1 is returned.
	int getIndexOfVertex(x vertex); 
	// a function that returns the vertex of a parameter in the int "vertices" array.
	x getVertexOfIndex(int index);

	//a function that returns true if the index associated with the parameter in the boolean "visitedVertices" array is true; otherwise returns false;
	bool isVisited(x vertex);
	//a function that sets false to all indeces of the boolean "visitedVertices" array.
	void cleanVisited();
	//a function that sets true to the index associated with the parameter of the boolean "visitedVertices" array.
	void markVisited(x vertex);
	//a function that sets true to the the parameter of the boolean "visitedVertices" array.
	void markVisited(int index);
	//a function that places all the adjacent vertices of the parameter "vertex" into the parameter q.
	void getVertices(x vertex, queue<x> &q);

	int getNumVertices();
	//a function that assgins one dimentional array with weights to get from the parameter index to all the other vertices.
	void createCostArray(int (&cost)[100], int index);
	//a function that returns the index of the smallest value in the cost array that has not been visited yet.
	int getCheapestIndex(int cost[]);
	//a function that returns the weight to get from a parameter index1 to a paramter index2.
	int getWeight(int index1, int index2);

	//a function that returns true if all indeces of the boolean "visitedVertices" array is true; otherwise false.
	bool isAllVerticesVisited();
	//a function that assigns the paramter a vertex that has not been visited yet.
	void getNextVertex(x &vertex);

	//a function that returns true if the int "numVertices" = int "maxVertices".
	bool isFull(); 
	//a function that returns true if the int "numVertices" = 0.
	bool isEmpty();

};
#endif // !Graph_hpp
