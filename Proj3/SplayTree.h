/**************************************************************
* File:    SplayTree.h
* Project: CMSC 341 - Project 3 - Word Frequency
* Author : Paolo B. Frias
* Date   : 05-November-2014
* Section: Lecture-02
* E-mail:
*
* SplayTree Class Defintion.
*************************************************************/

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "dsexceptions.h"
#include <iostream>        // For NULL
#include "Node.h"
using namespace std;

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class SplayTree
{
  public:
    SplayTree( )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
    }

    SplayTree( const SplayTree & rhs )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
        *this = rhs;
    }

    ~SplayTree( )
    {
        makeEmpty( );
        delete nullNode;
    }

    /**
     * Find the smallest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     smaller than any item in the tree, then call findMin.
     * Return the smallest item or throw UnderflowException if empty.
     */
    const Comparable & findMin( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        BinaryNode *ptr = root;

        while( ptr->left != nullNode )
            ptr = ptr->left;

        splay( ptr->element, root );
        return ptr->element;
    }

    /**
     * Find the largest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     larger than any item in the tree, then call findMax.
     * Return the largest item or throw UnderflowException if empty.
     */
    const Comparable & findMax( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        BinaryNode *ptr = root;

        while( ptr->right != nullNode )
            ptr = ptr->right;

        splay( ptr->element, root );
        return ptr->element;
    }


    bool contains( const Comparable & x )
    {
        if( isEmpty( ) )
            return false;
        splay( x, root );
        return root->element == x;
    }

	const Comparable search(const Comparable & x)
	{
		if (isEmpty()) {
			cout << "Tree is empty" << endl;
			return Node("", 1);
		} else {
			//splayIgnoreCase(x, root);
			splay(x, root);
			return root->element;
		}
	}

	void printMatches(const Comparable &x) {
		while(!this->isEmpty()) {
			Comparable found = search(x);
			string comparedSubstring = Util::Lower(found.GetWord().substr(0, x.GetWord().size()));
			if(comparedSubstring == x.GetWord()) {
				cout << found << endl;
			}
			remove(found);
		}
	}

    bool isEmpty( ) const
    {
        return root == nullNode;
    }

	Node getRoot() const {
		return root->element;
	}

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );

		cout << "This tree had " << m_splayCount << " splays\n";
    }

	int getNodeCount() {
		return m_nodeCount;
	}

    void makeEmpty( )
    {
    /******************************
     * Comment this out, because it is prone to excessive
     * recursion on degenerate trees. Use alternate algorithm.
        
        reclaimMemory( root );
        root = nullNode;
     *******************************/
        while( !isEmpty( ) )
        {
            findMax( );        // Splay max item to root
            remove( root->element );
        }
    }

    void insert( const Comparable & x )
    {
        static BinaryNode *newNode = NULL;

        if( newNode == NULL )
            newNode = new BinaryNode;
        newNode->element = x;

        if( root == nullNode )
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay( x, root );
            if( x < root->element )
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else
            if( root->element < x )
            {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            }
            else
                return;
        }
        newNode = NULL;   // So next insert will call new
		m_nodeCount++;
    }

	void remove(const Comparable & x)
	{
		BinaryNode *newTree;

		// If x is found, it will be at the root
		if(!contains(x))
			return;   // Item not found; do nothing

		if(root->left == nullNode) {
			newTree = root->right;
		}
		else
		{
			// Find the maximum in the left subtree
			// Splay it to the root; and then attach right child
			newTree = root->left;
			splay(x, newTree);
			newTree->right = root->right;
		}
		
        delete root;
        root = newTree;
		m_nodeCount--;
    }

    const SplayTree & operator=( const SplayTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }

        return *this;
    }

private:
    struct BinaryNode
    {
        Comparable  element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( ) : left( NULL ), right( NULL ) { }
        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    BinaryNode *root;
    BinaryNode *nullNode;
	int m_splayCount = 0;
	int m_nodeCount = 0;

    /**
     * Internal method to reclaim internal nodes in subtree t.
     * WARNING: This is prone to running out of stack space.
     */
    void reclaimMemory( BinaryNode * t )
    {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }

    /**
     * Internal method to print a subtree t in sorted order.
     * WARNING: This is prone to running out of stack space.
     */
   void printTree( BinaryNode *t ) const
    {
        if( t != t->left )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     */
    BinaryNode * clone( BinaryNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }

        // Tree manipulations
    void rotateWithLeftChild( BinaryNode * & k2 )
    {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( BinaryNode * & k1 )
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }

    /**
     * Internal method to perform a top-down splay.
     * The last accessed node becomes the new root.
     * This method may be overridden to use a different
     * splaying algorithm, however, the splay tree code
     * depends on the accessed item going to the root.
     * x is the target item to splay around.
     * t is the root of the subtree to splay.
     */
    void splay( const Comparable & x, BinaryNode * & t )
    {
		m_splayCount++;
        BinaryNode *leftTreeMax, *rightTreeMin;
        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x;   // Guarantee a match

        for( ; ; )
            if( x < t->element )
            {
                if( x < t->left->element )
                    rotateWithLeftChild( t );
                if( t->left == nullNode )
                    break;
                // Link Right
                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if( t->element < x )
            {
                if( t->right->element < x )
                    rotateWithRightChild( t );
                if( t->right == nullNode )
                    break;
                // Link Left
                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
    }
	/*
	void splayIgnoreCase(const Comparable & x, BinaryNode * t)
	{
		splays++;
		BinaryNode *leftTreeMax, *rightTreeMin;
		static BinaryNode header;

		header.left = header.right = nullNode;
		leftTreeMax = rightTreeMin = &header;

		nullNode->element = x;   // Guarantee a match
		//this->printTree();
		//6cout << endl;

		for(;;)
		if(Util::Lower(x.GetWord()) < Util::Lower(t->element.GetWord()))
		{
			if(Util::Lower(x.GetWord()) < Util::Lower(t->left->element.GetWord()))
				rotateWithLeftChild(t);
			if(t->left == nullNode)
				break;
			// Link Right
			rightTreeMin->left = t;
			rightTreeMin = t;
			t = t->left;
		} 
		else if(Util::Lower(t->element.GetWord()) < Util::Lower(x.GetWord()))
		{
			if(Util::Lower(t->right->element.GetWord()) < Util::Lower(x.GetWord()))
				rotateWithRightChild(t);
			if(t->right == nullNode)
				break;
			// Link Left
			leftTreeMax->right = t;
			leftTreeMax = t;
			t = t->right;
		} else
			break;

		//cout << "++Root: ";
		//this->printRoot();
		//this->printTree();
		cout << endl;
		leftTreeMax->right = t->left;
		rightTreeMin->left = t->right;
		t->left = header.right;
		t->right = header.left;
	}
	*/
};

#endif
