// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods
// MODIFIED: by rafe cooley 11/13/2017

// MODIFIED: by Corey Hoven 11/26/2017
// adjusted for windows

/**
 * Node.cpp
 * Corey Hoven
 * Homework 4-6
 * implementation of the Node class
 * @note MODIFIED again for use with binary merkle tree use
 *
 */


#include "Node.h"


/*Node::Node(string data)
	: time_(0), data_(data), left_(NULL), right_(NULL), dHashed_(""), leaf_(true)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) created at " << this << endl;
}
*/
Node::Node(int time, string data)
	: time_(time), data_(data), left_(NULL), right_(NULL), dHashed_(""), leaf_(true)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) created at " << this << endl;
}
/*
Node::Node(int time, string data, string dHash)
	: time_(time), data_(data), left_(NULL), right_(NULL), dHashed_(dHash), leaf_(true)
{
	//cout << "Node( " << time_ << ", " << data_ << ", " << dHashed_ <<
		//" ) created at " << this << endl;
}

Node::Node(int time, string data, Node * left)
	: time_(time), data_(data), left_(left), right_(NULL), dHashed_(""), leaf_(true)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) created at " << this << endl;
}

Node::Node(int time, string data, Node * left, Node * right)
	: time_(time), data_(data), left_(left), right_(right), dHashed_(""), leaf_(true)
{

}

*/
Node::~Node()
{
	//cout << "Node( " << time_ << ", " << data_ << ", " << dHashed_ <<
		//" ) at " << this << " destroyed" << endl;
    delete left_;
    delete right_;
}

Node::Node()
	: time_(0), data_(""), left_(NULL), right_(NULL), dHashed_(""), leaf_(true)
{
    //cout << "this happened at: " << this << endl;
}
/*
Node* Node::getLeft(Node* root)
{
    return root->left_;
}

Node* Node::getRight(Node* root)
{
    return root->right_;
}
*/
