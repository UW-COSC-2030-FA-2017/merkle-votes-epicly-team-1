/**
 * bTREE.cpp
 * Corey Hoven
 * Homework 4-6
 * implementation of the bTREE class
 * @note The nodePrint function does not like non-full trees, cannot comprehend what is causing it
 *
 */

#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
    : rootNode_(NULL)
{

}

bTREE::~bTREE()
{
    delete rootNode_;
}

int bTREE::dataInserted()
{
    return dataInserted(rootNode_);
}

int bTREE::dataInserted(Node * root)
{
    int dataCount=0;
    if (root!=NULL)
    {
        dataCount=root->leaf_;
        dataCount += dataInserted(root->left_);
        dataCount += dataInserted(root->right_);
    }
    return dataCount;

}

int bTREE::numberOfNodes()
{
    return numberOfNodes(rootNode_);
}

int bTREE::numberOfNodes(Node * root)
{
    int nodeCount=0;
    if (root!=NULL)
    {
        nodeCount++;
        nodeCount += numberOfNodes(root->left_);
        nodeCount += numberOfNodes(root->right_);
    }
    return nodeCount;
}

int bTREE::insert(string data, int time)
{
    int ops=1;
    Node * nodePtr;
    nodePtr = createLeaf(rootNode_, ops);
    nodePtr->data_=data;
    nodePtr->time_=time;
    return ops;
}

int bTREE::find(string hasheded)
{
    bool found=false;
    int ops=1;
    find(hasheded,rootNode_,found,ops);
    if (!found)
    {
        return 0;
    }
    return ops;
}

void bTREE::find(string hashed, Node* root, bool& found, int& ops)
{
    ops++;
    if (root!=NULL)
    {
        if (((root->dHashed_)==hashed)||(found==true))
        {
            found = true;
            return;
        }
        find(hashed, root->left_,found,ops);
        if (((root->dHashed_)==hashed)||(found==true))
        {
            found = true;
            return;
        }
        find(hashed, root->right_,found,ops);
        return;
    }
    return;
}

string bTREE::locate(string data)
{
    string Directions;
    stack<char> tempD;
    bool found=false;
    locate(data,rootNode_,found,tempD);
    if (tempD.size()==0)
    {
        Directions.push_back('.');
    }
    while (tempD.size()>0)
    {
        Directions.push_back(tempD.top());
        tempD.pop();
    }
    return Directions;
}

void bTREE::locate(string data, Node * root, bool& found, stack<char>& tempD)
{
    if (root!=NULL)
    {
        if (root->dHashed_==data||root->data_==data||found==true)
        {
            found=true;
            return;
        }
        locate(data,root->left_,found,tempD);
        if (root->dHashed_==data||root->data_==data||found==true)
        {
            tempD.push('L');
            found=true;
            return;
        }
        locate(data,root->right_,found,tempD);
        if (root->dHashed_==data||root->data_==data||found==true)
        {
            tempD.push('R');
            found=true;
            return;
        }
        return;
    }
    return;
}

bool bTREE::operator ==(/*const bTREE& lhs, */const bTREE& rhs)
{
    return (rootNode_->dHashed_==rhs.rootNode_->dHashed_);
}

bool bTREE::operator !=(/*const bTREE& lhs, */const bTREE& rhs)
{
    return (rootNode_->dHashed_!=rhs.rootNode_->dHashed_);
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
    int i=0;
    if (p.rootNode_!=NULL)
    {
        p.nodePrint(p.rootNode_);
        return out;
    }
    else
    {
        cout << "Tree is empty.";
    }
}

Node* bTREE::createLeaf(Node * root, int& ops)
{
    ops++;
    Node* newNode = new Node();
    if (root!=NULL)
    {
        queue<Node*> treeQueue;
        treeQueue.push(root);
        do
        {
            ops++;
            treeQueue.push(treeQueue.front()->left_);
            treeQueue.push(treeQueue.front()->right_);
            if (treeQueue.front()->left_==NULL)
            {
                //treeQueue.front()->left_=newNode;
                treeQueue.front()->left_=new Node(treeQueue.front()->time_, treeQueue.front()->data_);
                treeQueue.front()->leaf_=false;
                treeQueue.front()->data_="";
                //break;
            }
            if (treeQueue.front()->right_==NULL)
            {
                treeQueue.front()->right_=newNode;
                break;
            }
            treeQueue.pop();
        } while (!treeQueue.empty());
    }
    else
    {
        rootNode_=newNode;
    }
    return newNode;
}

void bTREE::nodePrint(Node* root) const
{
    if (root!= NULL)
    {
        int level=0;
        queue<Node*> printQueue, printQueue2;
        printQueue.push(root);
        levelCount(root,level);
        cout << "level: " << level << '\n';

        while (printQueue.front()!=NULL)
        {
            printQueue2.push(printQueue.front());
            printQueue.push(printQueue.front()->left_);
            printQueue.push(printQueue.front()->right_);
            printQueue.pop();

        }

        for (int i=1; i<=level; i++ )
        {
            //cout << i;
            //cout << ((pow(2,level-i)-1)*2);
            for (int j=((pow(2,level-i)-1)*2); j>0; j--)
            {
                //cout << j;
                //cout << " ";
            }

            //cout << pow(2,i-1);
            for (int k=0; k<(pow(2,i-1)); k++)
            {
                /** @note program breaks inside this loop when trying to print out non-full trees
                 */

                //cout << 'k';
                if ((printQueue2.front())!= NULL)
                {
                    //cout << i << ' ' << k << endl;
                    cout << "[" << setw(2) << printQueue2.front()->dHashed_ << "]";
                    printQueue2.pop();
                    for (int l=((pow(2,level-i)-1)*2); l>0; l--)
                    {
                        //cout << 'l';
                        //cout << "  ";
                    }
                    }
                }
            cout << '\n';
        }
    }
}

void bTREE::levelCount(Node* root, int& level) const
{
    if (root!= NULL)
    {
        level++;
        levelCount(root->left_,level);
        return;
    }
    return;
}

//test code used to test function before tree building was functional
/*void bTREE::testTree1()
{
    if (rootNode_==NULL)
    {
        (rootNode_)=new Node(1,"a","A");
        (rootNode_->left_)=new Node(2,"b","B");
        (rootNode_->right_)=new Node(3,"c","C");
        (rootNode_->left_->left_)=new Node(4,"d","D");
        (rootNode_->left_->right_)=new Node(5,"e","E");

    }
}

void bTREE::testTree2()
{
    if (rootNode_==NULL)
    {
        rootNode_=new Node(1,"a","AA");
        rootNode_->left_=new Node(2,"b","BB");
        rootNode_->right_=new Node(3,"c","CC");
        rootNode_->left_->left_=new Node(4,"d","DD");
        rootNode_->left_->right_=new Node(5,"e","EE");

    }
}

*/
