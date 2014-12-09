#include "Graph.h"


Graph::Graph() {

}

Graph::Graph(string inputFile) {
	this->init();
	this->createMatrix(inputFile);
	
}

void Graph::init() {
	//initialize adjacency matrix


}

void Graph::createMatrix(string inputFile) {
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
		cout << "There are " << m_cities << " cities and " << m_roads << " roads\n";
		//initialize matrix
		m_Matrix = new int*[m_cities];
		for(int i = 0; i < m_cities; ++i)
			m_Matrix[i] = new int[m_cities];

		for(unsigned int from = 0; from < m_cities; from++) {
			for (unsigned int to = 0; to < m_cities; to++) {
				m_Matrix[from][to] = 0;
			}
		}

		//fill matrix
		while (file >> num) {
			int start = num;
			file >> num;
			int end = num;
			file >> num;
			int weight = num;
			cout << "From " << start << " to " << end << " holds " << weight << endl;
			m_Matrix[start-1][end-1] = weight;
			m_Matrix[end-1][start-1] = weight;

		}
	}
}

void Graph::printMatrix() {
	for(int i = 0; i < m_cities; i++) {
		for (int j = 0; j < m_cities; j++) {
			cout << m_Matrix[i][j] << " ";
		}
		cout << "\n";

	}
}

int Graph::trips(int start, int end, int tourists) {
	cout << "Calculating total number of trips\n";


	return 1;
}




