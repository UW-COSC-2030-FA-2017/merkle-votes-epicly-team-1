// Node.h

// tom bailey   0755  05 oct 2010
// Declare the Node class.

// Node uses public access to simplify code in the
// container classes that use Nodes.  Client access is
// controlled by the container classes.

// The constructors and destructor are verbose to facilitate
// tracking of memory leaks.

// The default constructor and assignment operator are
// declared private so they cannot be called.

// MODIFIED: by rafe cooley 11/13/2017
// change entry type to string for hashing lab

// MODIFIED: by Corey Hoven 11/26/2017
// adjusted for windows

/**
 * Node.cpp
 * Corey Hoven
 * Homework 4-6
 * definition of the Node class
 * @note MODIFIED again for use with binary merkle tree use
 *
 */


#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


class Node
{
public:
    int time_;
    string dHashed_;
	string data_;
	Node * left_=NULL;
	Node * right_=NULL;
	bool leaf_=true;

public:
	// Constructors

	// post: this Node contains entry and a NULL pointer
	explicit Node(string data);

	// post: this Node contains entry and next
	Node(int time, string data);

	Node(int time, string data, string dHash);

	Node(int time, string data, Node * left);

	Node(int time, string data, Node * left, Node * right);

	//Node(string data, Node * left);

	//Node(string data, Node * left, Node * right);



	// Destructor

	~Node();

//private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

#endif
