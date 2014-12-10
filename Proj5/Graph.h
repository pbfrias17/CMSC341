/**************************************************************
* File:    Graph.h
* Project  CMSC 341 - Project 5 - Graph Traversals
* Author   Paolo B. Frias
* Due Date 09-December-2014
* Section  Lecture-02
* E-mail   pfrias2@umbc.edu
*
* Graph class definition
*************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Graph {
public:
	/**********************************************************************
	* Name: Graph - Default constructor
	* PreCondition: None
	*
	* PostCondition: Creates Graph object with default "input.txt"
	*********************************************************************/
	Graph();

	/**********************************************************************
	* Name: Graph - Alternate constructor
	* PreCondition: None
	*
	* PostCondition: Creates Graph object with given filename
	*********************************************************************/
	Graph(string inputFile);

	/**********************************************************************
	* Name: init
	* PreCondition: Called within class constructor
	*
	* PostCondition: Initializes all data for the graph given the filename
	*********************************************************************/
	void init(string inputFile);

	/**********************************************************************
	* Name: trips
	* PreCondition: start and end vertices must be connected
	*
	* PostCondition: Returns the minimum number of trips that the tourist
	*instructor must take given the values of vertices and tourists
	*********************************************************************/
	int trips(int start, int end, int tourists);
private:
	int m_cities;
	int m_roads;
	int m_startCity;
	int m_endCity;
	
	int **m_Matrix;	
	bool *m_Known;
	int *m_Parent;
	int *m_Weight;

	/**********************************************************************
	* Name: traverse
	* PreCondition: None
	*
	* PostCondition: Uses Dijkstra's search method to traverse the graph
	*in the most weighted way
	*********************************************************************/
	void traverse(int city);

	/**********************************************************************
	* Name: getNext
	* PreCondition: None
	*
	* PostCondition: Returns the next vertex(city) that has the highest
	*weight of all the unknown vertices
	*********************************************************************/
	int getNext();

	/**********************************************************************
	* Name: getMinimum
	* PreCondition: None
	*
	* PostCondition: Calculates the smallest cost included in the path
	*from the start to the end city
	*********************************************************************/
	int getMinimum(int parent, int &currMin);


};

#endif //GRAPH_H
