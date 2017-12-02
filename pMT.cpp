/**
 * pMT.cpp
 * Corey Hoven
 * Homework 4-6
 * implementation of the pMT class
 * @note
 *
 */

#include "pMT.h"

pMT::pMT(int hashSelect)
    : selectedHash(hashSelect)//, myMerkle(new bTREE)
/**
 * @brief
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return
 */
{
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
    //delete myMerkle;
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
    int ops=myMerkle.insert(vote, time);
    hashTree(myMerkle, selectedHash);
    return ops;
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of operations required to find the matching vote
 */
{
    switch (hashSelect)
    {
        case 1: return myMerkle.find(hash_1(vote));
                break;
        case 2: return myMerkle.find(hash_2(vote));
                break;
        case 3: return myMerkle.find(hash_3(vote));
                break;
        default: cout << "invalid hash function number.";
                break;
    }
    return 0;

}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of operations required to find the matching hash
 */
{
    return myMerkle.find(mhash);
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
 * @param vote, the data to search for
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
    return myMerkle.locate(vote);
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
 * @param mhash, the hash to search for
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
    return myMerkle.locate(mhash);
}



string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    string tempHash="";
    string Base="0123456789ABCDEF";
    tempHash.push_back(key.at(key.length()/2));
    tempHash.push_back(key.at(key.length()/4));
    tempHash.push_back(key.at(key.length()*(3/4)));
    //tempHash.push_back(key.length());
    for (int i=tempHash.length();i<=16;i++)
    {
        tempHash.push_back(Base[(key.at((i)*1/3)%16)]);
    }
    return tempHash;
}

string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    string tempHash="";
    string Base="0123456789ABCDEF";
    string keyCopy=key;
    for (int i=tempHash.length();i<=16;i++)
    {
        if (!keyCopy.empty())
        {
            tempHash.push_back(keyCopy[(443*i)%keyCopy.length()]);
            keyCopy.erase((i%keyCopy.length()),1);
        }
        else
        {
            tempHash.push_back('0');
        }
    }
    return tempHash;
}

string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    string tempHash="";
    string Base="0123456789ABCDEF";
    string keyCopy=key;

    for (int i=tempHash.length();i<=16;i++)
    {
        if (!keyCopy.empty())
        {
            tempHash.push_back(Base.at(keyCopy[(443*i)%keyCopy.length()]%16));
            keyCopy.erase((i%keyCopy.length()),1);
        }
        else
        {
            tempHash.push_back('0');
        }
    }
    return tempHash;
}

bool pMT::operator ==(/*const pMT& lhs, */const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
    return (myMerkle==rhs.myMerkle);
}

bool pMT::operator !=(/*const pMT& lhs, */const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
    return (myMerkle!=rhs.myMerkle);
}

//pMT pMT::operator ^(/*const pMT& lhs, */const pMT& rhs)
/**
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 *
{

}
*/

std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{
    cout << p.myMerkle;
    return out;
}


void pMT::hashTree(bTREE& myMerk, int hashSelect)
{
        switch (hashSelect)
    {
        case 1:  hashTree1(myMerk.rootNode_);
                break;
        case 2:  hashTree2(myMerk.rootNode_);
                break;
        case 3:  hashTree3(myMerk.rootNode_);
                break;
        default: cout << "invalid hash function number.";
                break;
    }

}

void pMT::hashTree1(Node* root)
{
    if (root!= NULL)
    {
        hashTree1(root->left_);
        hashTree1(root->right_);
        if (root->left_!=NULL)
        {
            root->data_+=root->left_->dHashed_;
        }
        if (root->right_!=NULL)
        {
            root->data_+=root->right_->dHashed_;
        }
        root->dHashed_=hash_1(root->data_);

    }

}

void pMT::hashTree2(Node* root)
{
    if (root!= NULL)
    {
        hashTree2(root->left_);
        hashTree2(root->right_);
        if (root->left_!=NULL)
        {
            root->data_+=root->left_->dHashed_;
        }
        if (root->right_!=NULL)
        {
            root->data_+=root->right_->dHashed_;
        }
        root->dHashed_=hash_2(root->data_);

    }
}

void pMT::hashTree3(Node* root)
{
    if (root!= NULL)
    {
        hashTree3(root->left_);
        hashTree3(root->right_);
        if (root->left_!=NULL)
        {
            root->data_+=root->left_->dHashed_;
        }
        if (root->right_!=NULL)
        {
            root->data_+=root->right_->dHashed_;
        }
        root->dHashed_=hash_3(root->data_);

    }
}

