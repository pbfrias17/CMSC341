#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	void PrintTable();
	void LinearProbe(int randInts[]);
	void QuadraticProbe(int randInts[]);
	void DoubleHashProbe(int randInts[]);
	//friend int hash(int x);


private:
	//statistics?
	int* m_HashTable;
	int m_size;
	int m_totalInserts;
	int m_successfulInserts;
	int m_failedInserts;

	bool findPos(int entry);
	friend int hash(int x);
};


#endif

