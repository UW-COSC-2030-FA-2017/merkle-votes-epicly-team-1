/**
 * pMT.h
 * Corey Hoven
 * Homework 4-6
 * definition of the MerkleTree class
 * @note
 *
 */

#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
public:
    int selectedHash;
    bTREE myMerkle;

    string hash_1(string);
    string hash_2(string);
    string hash_3(string);

public:
    pMT(int);
    ~pMT();


    int insert(string, int);

    int find(string vote, int time, int hashSelect);
    int findHash(string);

    string locateData(string);
    string locateHash(string);

    bool operator==(/*const pMT& lhs, */const pMT& rhs);

    bool operator!=(/*const pMT& lhs, */const pMT& rhs);

    friend std::ostream& operator<<(std::ostream& out, const pMT& p);

    //pMT operator ^(/*const pMT& lhs, */const pMT& rhs);

    void hashTree(bTREE& myMerk, int hashSelect);

    void hashTree1(Node* root);
    void hashTree2(Node* root);
    void hashTree3(Node* root);


};

