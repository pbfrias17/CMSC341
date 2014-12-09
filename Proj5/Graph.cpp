#include "Graph.h"


Graph::Graph() {

}

Graph::Graph(string inputFile) {
	this->init(inputFile);
	
}

void Graph::init(string inputFile) {
	//initialize adjacency matrix
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
		for (int i = 0; i < m_cities; ++i)
			m_Matrix[i] = new int[m_cities];

		for (unsigned int from = 0; from < m_cities; from++) {
			for (unsigned int to = 0; to < m_cities; to++) {
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
			cout << "From " << start << " to " << end << " holds " << weight << " (+ Mr.T)" << endl;
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
	start--;
	end--;

	m_startCity = start;
	m_endCity = end;
	
	//indicate starting city
	m_Known[start] = true;
	m_Parent[start] = -1;
	m_Weight[start] = 0;
	
	traverse(start);

	m_Matrix[end]

	return 1;
}

void Graph::traverse(int city) {
	cout << "Finding the next neighbor of city " << city + 1 << endl;
	for(int i = 0; i < m_cities; i++) {
		int neighbor = i;
		int weight = m_Matrix[city][neighbor];
		if(weight != 0) {
			cout << "\tChecking neighbor of " << city + 1 << ": " << neighbor + 1 << endl;
			if(m_Known[neighbor] != true) {
				cout << "\tIt is NOT KNOWN\n";
				if(weight > m_Weight[neighbor]) {
					cout << "\t" << weight << " > " << m_Weight[neighbor] << " ...updating\n";
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
	cout << "Now finding the next largest unknown weighted city\n";
	int max = 0;
	int maxCity = -1;
	for(int i = 0; i < m_cities; i++) {
		if(m_Known[i] != true && m_Weight[i] > max) {
			max = m_Weight[i];
			maxCity = i;
		}
	}
	cout << "\tCity " << maxCity + 1 << " with a weight of " << max << " seems to be next\n";

	int stopper;
	cin >> stopper;

	return maxCity;
}

int Graph::trace(int end) {

}






