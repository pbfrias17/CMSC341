#ifndef GRAPH_H
#define GRAPH_H

#include "Route.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
public:
	Graph();
	Graph(string inputFile);
	void init(string inputFile);
	void createMatrix(string inputFile);
	void printMatrix();
	int trips(int start, int end, int tourists);
private:
	int m_cities;
	int m_roads;
	int **m_Matrix;	
	
	bool *m_Known;
	int *m_Parent;
	int *m_Weight;


};

#endif //GRAPH_H