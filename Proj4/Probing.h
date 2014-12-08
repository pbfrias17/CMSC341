/**************************************************************
* File:     Probing.h
* Project:  CMSC 341 - Project 4
* Author:   Paolo Frias
* Due Date: 18-November-2014
* Section:  Lecture-02
* E-mail:   pfrias2@umbc.edu
*
* Probing class definition
*************************************************************/

#ifndef PROBING_H
#define PROBING_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************

// bool contains( x )     --> Return true if x is present
// void makeType( type)   --> Classifies hashtable accordingly
// void makeEmpty( )      --> Remove all items
// bool isFull()          --> Verifies if array/vector is full
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// 

template <typename HashedObj>
class HashTable
{
  public:
	  explicit HashTable(int type, int size = 101, int largestPrime = 11) : array(size), currentSize(size), totalInserts(0), m_largestPrime(largestPrime), N(0), currentMaxProbes(0)
    { 
		makeType(type);
		makeEmpty( ); 
	}

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }
	void makeType(int type) {
		switch(type) {
		case 1:
			m_ProbeType = LINEAR;
			break;
		case 2:
			m_ProbeType = QUADRATIC;
			break;
		case 3:
			m_ProbeType = DOUBLE;
			break;
		}
	}
    void makeEmpty( )
    {
        currentSize = 0;
        for( unsigned int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
    }

	bool isFull() {
		if(successfulInserts >= array.size())
			return true;

		return false;
	}

    bool insert( const HashedObj & x )
    {
		totalInserts++;

        unsigned int currentPos = findPos( x );

		if(currentPos > array.size()) {
			unsuccessfulInserts++;
		} else {
			successfulInserts++;
			array[ currentPos ] = HashEntry( x, ACTIVE );
		}

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

	/********************************
	// Various incrementers, accessors
	//
	********************************/
	void incrementN() {
		N++;
	}

	void incrementProbes() {
		totalProbes++;
	}

	int getProbes() const {
		return totalProbes;
	}

	float getProbeAvg() const {
		return (float)totalProbes / (float)totalInserts;
	}

	int getMaxProbes() const {
		return currentMaxProbes;
	}

	int getCurrentN() const {
		return N;
	}
	int getTotalInserts() const 
	{	return successfulInserts + unsuccessfulInserts; }

	int getSuccessfulInserts() const
	{
		return successfulInserts;
	}

	int getUnsuccessfulInserts() const
	{
		return unsuccessfulInserts;
	}

	int getTotalClusters() const {
		return totalClusterAmount;
	}
	
	float getClusterAvg() const {
		return (float)sumOfClusters / (float)getTotalClusters();
	}
	
	int getMaxCluster() const {
		return maxClusterLength;
	}

	/**********************************************************************
	* Name: getClusterStatistics
	* PreCondition: None
	*
	* PostCondition: Goes through the hashtable and counts clusters and
	*records the largest cluster size
	*********************************************************************/
	void getClusterStatistics() {
		int clusterLength = 0;
		int maxLength = 0;
		int clusterAmount = 0;
		int clusterSum = 0;

		for(unsigned int i = 0; i < array.size(); i++) {
			if(array[i].info == ACTIVE) {
				clusterLength++;
				
				if(i == array.size() - 1) {
					clusterAmount++;
					clusterSum += clusterLength;
					if (clusterLength > maxLength)
						maxLength = clusterLength;
				}

			} else {
				if (clusterLength > maxLength)
					maxLength = clusterLength;
			
				clusterSum += clusterLength;
				clusterLength = 0;
				if(maxLength != 0 && array[i - 1].info != EMPTY)
					clusterAmount++;
			}
		}
		maxClusterLength = maxLength;
		totalClusterAmount = clusterAmount;
		sumOfClusters = clusterSum;

	}

	/**********************************************************************
	* Name: printStatistics
	* PreCondition: None
	*
	* PostCondition: Prints out all desired statistics of Hashtable efficiency
	*********************************************************************/
	void printStatistics() {
		cout.precision(2);
		cout << getTotalInserts() << "    ";
		
		if(getTotalInserts() < 10)
			cout << " ";
		cout << fixed << getSuccessfulInserts() / array.size() << "        " << getSuccessfulInserts() << "      ";
		
		if(getSuccessfulInserts() < 10)
			cout << " ";
		cout << getUnsuccessfulInserts() << "        ";
		
		if(getUnsuccessfulInserts() < 10)
			cout << " ";

		cout << getProbes() << "       ";
		if(getProbes() < 10)
			cout << " ";
		cout << fixed << getProbeAvg() << "    " << getMaxProbes() << "        ";
		if(getMaxProbes() < 10)
			cout << " ";


		getClusterStatistics();
		cout << getTotalClusters() << "   " << fixed << getClusterAvg() << "       ";
		if(getClusterAvg() < 10)
			cout << " ";
		cout << getMaxCluster() << endl;

	}

    enum EntryType { ACTIVE, EMPTY, DELETED };
	
	//For classifying probe method
	enum ProbeType { LINEAR, QUADRATIC, DOUBLE };

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };
    
    vector<HashEntry> array;
    int currentSize;
	ProbeType m_ProbeType;
	unsigned int N;
	unsigned int totalInserts;
	unsigned int successfulInserts;
	unsigned int unsuccessfulInserts;
	unsigned int totalProbes;
	unsigned int m_largestPrime;
	unsigned int currentMaxProbes;
	unsigned int maxClusterLength;
	unsigned int totalClusterAmount;
	unsigned int sumOfClusters;


    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x )
	{
		int currentPos = myhash(x);

        return currentPos;
    }

	/**********************************************************************
	* Name: myhash
	* PreCondition: None
	*
	* PostCondition: Returns the position of the next available index
	*according to the probing method, or returns an invalid index to signify
	*a failed insertion
	*********************************************************************/
    int myhash( const HashedObj & x )
    {
		int hashed = x % array.size();
		int i = 0;
		int finalHashed = (hashed + hash(x, i)) % array.size();
		
		int *allKeys;
		int keyNum = 0;
		allKeys = new int[array.size()];

		int maxProbes = 0;

		maxProbes++;
		while (array[finalHashed].info == ACTIVE) {
			i++;
			maxProbes++;
			
			if(match(allKeys, finalHashed)) 
				return array.size() + 1;
			else 
				allKeys[keyNum] = finalHashed;
			
			keyNum++;

			finalHashed = (hashed + hash(x, i)) % array.size();
		}
		totalProbes += maxProbes;
		if(currentMaxProbes < maxProbes)
			currentMaxProbes = maxProbes;


		delete allKeys;
		allKeys = NULL;

        return finalHashed;
    }

	/**********************************************************************
	* Name: match
	* PreCondition: None
	*
	* PostCondition: Verifies whether or not the provided array contains
	*the desired key
	*********************************************************************/
	bool match(int keys[], int key) {

		for(int i = 0; i < array.size(); i++) {
			if(keys[i] == key)
				return true;
		}
		return false;
	}

	/**********************************************************************
	* Name: hash
	* PreCondition: None
	*
	* PostCondition: Hashes the object according to the probe type
	*********************************************************************/
	int hash(const HashedObj &x, int probe) const {
		switch (m_ProbeType) {
		case LINEAR:
			return probe;
		case QUADRATIC:
			return probe * probe;
		case DOUBLE:
			return probe * hash2(x, probe);
		default:
			//choose linear probing by default
			return probe;
		}
	}	
	
	int hash2(const HashedObj &x, int probe) const {
		int R = m_largestPrime;
		return R - (x % R);
	}

};


#endif
