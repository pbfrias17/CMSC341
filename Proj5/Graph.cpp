/**************************************************************
* File:    Graph.cpp
* Project  CMSC 341 - Project 5 - Graph Traversals
* Author   Paolo B. Frias
* Due Date 09-December-2014
* Section  Lecture-02
* E-mail   pfrias2@umbc.edu
*
* Graph class implementation
*************************************************************/

#include "Graph.h"


Graph::Graph() {
	this->init("input.txt");
}

Graph::Graph(string inputFile) {
	this->init(inputFile);
	
}

void Graph::init(string inputFile) {
	ifstream file;
	file.open(inputFile.c_str(), ios_base::in);

	if (file.fail()) {
		cout << "Cannot open file: " << inputFile << endl;
	} else {
		int num;

		file >> num;
		m_cities = num;
		file >> num;
		m_roads = num;

		//initialize matrix
		m_Matrix = new int*[m_cities];
		for (int i = 0; i < m_cities; ++i)
			m_Matrix[i] = new int[m_cities];

		for (int from = 0; from < m_cities; from++) {
			for (int to = 0; to < m_cities; to++) {
				m_Matrix[from][to] = 0;
			}
		}

		//fill matrix
		while (file >> num) {
			
			int start = num - 1;
			file >> num;
			int end = num - 1;
			file >> num;
			int weight = num - 1;

			m_Matrix[start][end] = weight;
			m_Matrix[end][start] = weight;

		}

		//create search tables
		m_Known = new bool[m_cities];
		for(int i = 0; i < m_cities; i++)
			m_Known[i] = false;

		m_Parent = new int[m_cities];
		for(int i = 0; i < m_cities; i++)
			m_Parent[i] = 0;

		m_Weight = new int[m_cities];
		for(int i = 0; i < m_cities; i++)
			m_Weight[i] = 0;

	}

}

int Graph::trips(int start, int end, int tourists) {
	//adjust for index
	start--;
	end--;

	m_startCity = start;
	m_endCity = end;
	
	//indicate starting city
	m_Known[start] = true;
	m_Parent[start] = -1;
	m_Weight[start] = 0;
	
	traverse(start);

	int minWeight = 0;
	minWeight = getMinimum(m_endCity, minWeight);

	delete m_Known;
	delete m_Parent;
	delete m_Weight;

	return ceil((float)tourists / (float)minWeight);
}

void Graph::traverse(int city) {

	for(int i = 0; i < m_cities; i++) {
		int neighbor = i;
		int weight = m_Matrix[city][neighbor];
		if(weight != 0) {
			if(m_Known[neighbor] != true) {
				if(weight > m_Weight[neighbor]) {
					m_Weight[neighbor] = weight;
					m_Parent[neighbor] = city;
				}
			}
		}
	}

	int next = getNext();
	if(next != -1) {
		m_Known[next] = true;
		if(next != m_endCity)
			traverse(next);
	}
}

int Graph::getNext() {
	
	int max = 0;
	int maxCity = -1;
	for(int i = 0; i < m_cities; i++) {
		if(m_Known[i] != true && m_Weight[i] > max) {
			max = m_Weight[i];
			maxCity = i;
		}
	}

	return maxCity;
}

int Graph::getMinimum(int parent, int &currMin) {
	if(parent == m_endCity)
		currMin = m_Weight[parent];

	if(parent == m_startCity) {
		return currMin;
	} else {
		if(0 < m_Weight[parent] && m_Weight[parent] < currMin)
			currMin = m_Weight[parent];

		return(getMinimum(m_Parent[parent], currMin));
	}
}






