/**
 * bTREE.h
 * Corey Hoven
 * Homework 4-6
 * definition of the bTREE class
 * @note
 *
 */

#pragma once
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>
#include "Node.h"
using namespace std;

class bTREE
{

/*    struct treeNode
    {
        string data;
        int time;
    };
*/
public:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    Node * rootNode_=NULL;

public:
    bTREE();
    ~bTREE();

    int dataInserted();

    int numberOfNodes();

    int insert(string, int);

    int find(string);


    string locate(string);


    Node* createLeaf(Node *, int&);


    void nodePrint(Node*) const;
    void levelCount(Node*, int&) const;

    void testTree1();
    void testTree2();





    bool operator==(/*const bTREE& lhs, */const bTREE& rhs);
    bool operator!=(/*const bTREE& lhs, */const bTREE& rhs);

    friend std::ostream& operator <<(std::ostream& out, const bTREE& p);

private:
    void find(string hashed, Node* root, bool& found, int& ops);

    int numberOfNodes(Node * root);

    void locate(string , Node * , bool& , stack<char>& );

    int dataInserted(Node * root);


};

