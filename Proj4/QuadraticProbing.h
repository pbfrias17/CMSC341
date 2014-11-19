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
	  explicit HashTable(int type, int size = 101) : array(size), currentSize(size), totalInserts(0)
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
        for( int i = 0; i < array.size( ); i++ )
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
	int totalInserts;
	int successfulInserts;
	int failedInserts;


    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
	{

		int currentPos = myhash(x);

        return currentPos;
    }
	/*
    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                insert( oldArray[ i ].element );
    }*/
    int myhash( const HashedObj & x ) const
    {
		int hashed = x % array.size();
		int i = 0;
		int finalHashed = (hashed + hash(i)) % array.size();
		while (array[finalHashed].info == ACTIVE) {
			i++;
			cout << "-- Collision at index " << finalHashed << endl;
			finalHashed = (hashed + hash(i)) % array.size();
		}

        //if( hashVal < 0 )
        //    hashVal += array.size( );

        return finalHashed;
    }
	int hash(int probe) const {
		switch (m_ProbeType) {
		case LINEAR:
			return probe;
		case QUADRATIC:
			return probe * probe;
		case DOUBLE:
			return probe * probe;
		default:
			return probe;
		}
	}	
	
	int hash2(const HashedObj &x) const {
		int R = m_largestPrime;
		return R - x % array.size();
	}
	
	int linearProbe(const HashedObj &x) const {
		int pos = x;
		while(array[pos].info == ACTIVE) {
			pos++;
			if(pos >= array.size()) {
				cout << pos << " >= " << array.size() << endl;
				pos -= array.size();
			}
			cout << "--Looking at index " << pos << endl;
		}
		return pos;
	}
	int quadraticProbe(const HashedObj &x) const {
		int pos = x;
		int offset = 1;
		while(array[pos].info == ACTIVE) {
			cout << "index " << pos << " is active, moving on\n";
			pos += offset;
			offset += 2;
			while(pos >= array.size()) {
				cout << pos << " >= " << array.size() << endl;
				pos -= array.size();
				//char stopper;
				//cin >> stopper;
			}
			//cout << "--Looking at index " << pos << endl;
		}
		return pos;
	}

	int doubleHashProbe(const HashedObj &x) const {
		int pos = x;
		int offset = 1;

		return pos;
	}
};


#endif
