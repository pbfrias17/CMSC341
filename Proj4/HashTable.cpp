#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {}

HashTable::HashTable(int size) 
: m_size(size), m_totalInserts(0), m_successfulInserts(0), m_failedInserts(0) {
	m_HashTable = new int[size];
	for(int i = 0; i < size; i++) {
		m_HashTable[i] = NULL;
	}
}

HashTable::~HashTable() {
	delete m_HashTable;
}
void HashTable::LinearProbe(int randInts[]) {
	for(int i = 0; i < m_size; i++) {
		int hashVal = 0;
		hashVal = randInts[i] % m_size;
		if(m_HashTable[hashVal] != NULL) {
			m_failedInserts++;
			cout << "-- Handling collision at index " << hashVal << endl;
			bool success = false;
			int probeNum = 1;
			while(!success) {
				if((hashVal + probeNum) == m_size) {
					hashVal -= m_size;
				}
				if(m_HashTable[hashVal + probeNum] == NULL) {
					cout << "\tPlacing " << randInts[i] << " into index " << hashVal + probeNum << endl;
					m_HashTable[hashVal + probeNum] = randInts[i];
					success = true;
				} else {
					cout << "\tIndex " << hashVal + probeNum << " is filled" << endl;
					m_failedInserts++;
				}
				probeNum++;
			}
		} else {
			cout << "Inserting " << randInts[i] << " into index " << hashVal << endl;
			m_HashTable[hashVal] = randInts[i];
			m_successfulInserts++;
		}

		if(++m_totalInserts >= m_size) {
			cout << "~HashTable is now completely filled\n";
			break;
		}
	}
}

void HashTable::QuadraticProbe(int randInts[]) {
	for(int i = 0; i < m_size; i++) {
		int hashVal = 0;
		hashVal = randInts[i] % m_size;
		if(m_HashTable[hashVal] != NULL) {
			m_failedInserts++;
			cout << "-- Handling collision at index " << hashVal << endl;
			bool success = false;
			int probeNum = 1;
			while(!success) {
				if((hashVal + probeNum) == m_size) {
					hashVal -= m_size;
				}
				if(m_HashTable[hashVal + probeNum] == NULL) {
					cout << "\tPlacing " << randInts[i] << " into index " << hashVal + probeNum << endl;
					m_HashTable[hashVal + probeNum] = randInts[i];
					success = true;
				} else {
					cout << "\tIndex " << hashVal + probeNum << " is filled" << endl;
					m_failedInserts++;
				}
				probeNum++;
			}
		} else {
			cout << "Inserting " << randInts[i] << " into index " << hashVal << endl;
			m_HashTable[hashVal] = randInts[i];
			m_successfulInserts++;
		}

		if(++m_totalInserts >= m_size) {
			cout << "~HashTable is now completely filled\n";
			break;
		}
	}
}