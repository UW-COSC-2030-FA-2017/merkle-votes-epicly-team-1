/**
 * vote.cpp
 * Corey Hoven
 * Homework 4-6
 * test driver of the program
 * @note program refuses to print out non-full trees, see bTREE.cpp for details
 */

#include <stdio.h>
#include "pMT.h"
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    pMT Merk1(1);
    string inFileName/*="mv_test.txt"*/, inTempData="";
    int inTempTime=0;
    cout << "Enter file name including file extension: ";
    cin >> inFileName;
    ifstream inFile(inFileName);
    if (!inFile.is_open())
    {
        cout << "File failed to open, terminating program.";
        return 1;
    }
    else
    {
        while (!inFile.eof()&&inFile.good())
        {
            inFile >> inTempData;
            inFile >> inTempTime;
            Merk1.insert(inTempData,inTempTime);
        }
        inFile.close();
    }

        pMT Merk2(2);
    string inFileName2="mv_test.txt", inTempData2="";
    int inTempTime2=0;
    cout << "Enter file name including file extension: ";
    cin >> inFileName2;
    ifstream inFile2(inFileName2);
    if (!inFile2.is_open())
    {
        cout << "File failed to open, terminating program.";
        return 1;
    }
    else
    {
        while (!inFile2.eof()&&inFile2.good())
        {
            inFile2 >> inTempData2;
            inFile2 >> inTempTime2;
            Merk2.insert(inTempData2,inTempTime2);
        }
        inFile2.close();
    }

    //Compare Hashes at each level/node in a preorder pattern to locate where a variance occurs
    /**
     * @brief place code to compare hashes here
     *
     *
     */

    //cout << (Merk1==Merk2);
    //cout << Merk2;
    //cout << Merk2.find("asdfgqertadvqaewr",1,1);

    //misc testing code used while writing the program
    /*
    pMT tree1(3);
    //tree1.testTree1();
    //bTREE tree1;
    //tree2.testTree2();

    //cout << (tree1!=tree2);

    //cout << tree1.locate("C")<<endl;
    //cout << tree2.locate("DD")<<endl;

    /*cout << tree1.find("A");
    cout << tree1.find("B");
    cout << tree1.find("C");
    cout << tree1.find("D");
    cout << tree1.find("E");

    //cout << tree1 << endl;

    cout << "insert took " << tree1.insert("alskjcneqpweifac",1) << " operations.\n";
    cout << "insert took " << tree1.insert("awleqwefqwerurhf",2) << " operations.\n";
    cout << "insert took " << tree1.insert("aclkgterbjwehfal",3) << " operations.\n";
    cout << "insert took " << tree1.insert("awertcwjkehqtwer",4) << " operations.\n";
    cout << "insert took " << tree1.insert("5",5) << " operations.\n";
    cout << "insert took " << tree1.insert("6",6) << " operations.\n";
    cout << "insert took " << tree1.insert("7",7) << " operations.\n";
    cout << "insert took " << tree1.insert("8",8) << " operations.\n";
    cout << "insert took " << tree1.insert("9",9) << " operations.\n";
    cout << "insert took " << tree1.insert("10",10) << " operations.\n";
    cout << "insert took " << tree1.insert("11",11) << " operations.\n";
    cout << "insert took " << tree1.insert("12",12) << " operations.\n";
    cout << "insert took " << tree1.insert("13",13) << " operations.\n";
    cout << "insert took " << tree1.insert("14",14) << " operations.\n";
    cout << "insert took " << tree1.insert("15",15) << " operations.\n";
    cout << "insert took " << tree1.insert("16",16) << " operations.\n";
    cout << "insert took " << tree1.insert("17",17) << " operations.\n";
    cout << "insert took " << tree1.insert("18",18) << " operations.\n";
    cout << "insert took " << tree1.insert("19",19) << " operations.\n";
    cout << "insert took " << tree1.insert("20",20) << " operations.\n";
    cout << "insert took " << tree1.insert("21",21) << " operations.\n";
    cout << "insert took " << tree1.insert("22",22) << " operations.\n";
    cout << "insert took " << tree1.insert("23",23) << " operations.\n";
    cout << "insert took " << tree1.insert("24",24) << " operations.\n";
    cout << "insert took " << tree1.insert("25",25) << " operations.\n";
    cout << "insert took " << tree1.insert("26",26) << " operations.\n";
    cout << "insert took " << tree1.insert("27",27) << " operations.\n";
    cout << "insert took " << tree1.insert("28",28) << " operations.\n";
    cout << "insert took " << tree1.insert("29",29) << " operations.\n";
    cout << "insert took " << tree1.insert("30",30) << " operations.\n";
    cout << "insert took " << tree1.insert("31",31) << " operations.\n";

    cout << tree1.myMerkle.dataInserted();

    cout << tree1 << endl;


    //cout << "Performed: " << tree1.find("F") << " operations during seek.\n";

    //cout << tree1.dataInserted() << " # of data\n";
    //cout << tree1.numberOfNodes() << " nodes\n";
    */
	return 0;
}
