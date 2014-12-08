#ifndef GRAPH_H
#define GRAPH_H

#include "Route.h"
#include <string>
#include <iostream>


using namespace std;

class Graph {
public:
	Graph();
	Graph(string inputFile);
	int trips(int start, int end, int tourists);
private:
	Route *m_Graph;	


};

#endif //GRAPH_H