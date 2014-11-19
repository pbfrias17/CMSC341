#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <string>
using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
  public:
	  explicit HashTable(int type, int size = 101, int largestPrime = 11) : array(size), currentSize(size), totalInserts(0), m_largestPrime(largestPrime)
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
		int stopper;
		if(totalInserts >= array.size()) {
			cout << "Table is full: " << totalInserts << " = " << array.size() << "\n";
			cin >> stopper;
			return true;
		}
		return false;
	}

    bool insert( const HashedObj & x )
    {
		totalInserts++;

        int currentPos = findPos( x );

		cout << "Inserting " << x << " into index " << currentPos << endl;
        array[ currentPos ] = HashEntry( x, ACTIVE );

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

    enum EntryType { ACTIVE, EMPTY, DELETED };
	enum ProbeType { LINEAR, QUADRATIC, DOUBLE};

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
	unsigned int totalInserts;
	unsigned int successfulInserts;
	unsigned int failedInserts;
	unsigned int m_largestPrime;


    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
	{

		int currentPos = myhash(x);

        return currentPos;
    }

    int myhash( const HashedObj & x ) const
    {
		int hashed = x % array.size();
		int i = 0;
		int finalHashed = (hashed + hash(x, i)) % array.size();
		while (array[finalHashed].info == ACTIVE) {
			i++;
			cout << "-- Collision at index " << finalHashed << endl;
			finalHashed = (hashed + hash(x, i)) % array.size();
		}

        return finalHashed;
    }
	int hash(const HashedObj &x, int probe) const {
		switch (m_ProbeType) {
		case LINEAR:
			return probe;
		case QUADRATIC:
			return probe * probe;
		case DOUBLE:
			return probe * hash2(x, probe);
		default:
			return probe;
		}
	}	
	
	int hash2(const HashedObj &x, int probe) const {
		int R = m_largestPrime;
		return R - (x % R);
	}

};


#endif
