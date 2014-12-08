#include "Graph.h"

int main(int argc, char *argv[])
{
	//read the command line argument and generate a graph
	string filename = argv[1];
	Graph mygraph(filename);
	int s, d, t;
	//take user input on the source city, destination city, and the number of tourists
	cin>> s >> d >> t;
	//print the minimum number of trips
	cout<<"Minimum Number of Trip: "<<mygraph.trips(s,d,t) <<endl;
}
