#include<iostream>
#include<vector>
#include<string>
#include<map>
#define big 100000
using namespace std;

map <string, string> ss;

//the node type and elements
struct node
{
    node * leftChild;
    node * rightChild;
    double frequency;
    string content;
    string code;
};

vector<node> nodeArray;


//a function to extract minimum value node from heap
node  extractMin()
{
    double temp = (double) INT_MAX;
    vector<node>::iterator i1,pos;
    for(i1 = nodeArray.begin(); i1!=nodeArray.end(); i1++)
    {
        if(temp>(*i1).frequency)
        {
            pos = i1;
            temp = (*i1).frequency;
        }
    }

    node tempNode = (*pos);
    nodeArray.erase(pos);

    return tempNode;
}

//makes huffman tree
node getHuffmanTree()
{
    while(!nodeArray.empty())
    {
        node * tempNode = new node;
        node * tempNode1 = new node;
        node * tempNode2 = new node;
        *tempNode1 = extractMin();
        *tempNode2 = extractMin();

        tempNode->leftChild = tempNode1;
        tempNode->rightChild = tempNode2;
        tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
        nodeArray.push_back(*tempNode);
        if(nodeArray.size() == 1)
            break;
    }
    return nodeArray[0];
}



// bfs traversal and stores the codes on the map
void BFS(node * temproot,string s)
{
    node * root1 = new node;
    root1 = temproot;

    root1->code = s;
    if(root1 == NULL)
    {
        return;
    }
    else if(root1->leftChild == NULL && root1->rightChild == NULL)
    {
        ss[root1->content]=root1->code;
    }
    else
    {
        root1->leftChild->code = s.append("0");
        s.erase(s.end()-1);
        root1->rightChild->code = s.append("1");
        s.erase(s.end()-1);

        BFS(root1->leftChild,s.append("0"));
        s.erase(s.end()-1);
        BFS(root1->rightChild,s.append("1"));
        s.erase(s.end()-1);
    }
}

//takes the input and starts the process
void Huffman()
{
    int size,i;
    double tempDouble;
    string tempString = "";
    cin>>size;

    for(i = 0; i<size; i++)
    {
        node tempNode;
        cin>>tempString;
        cin>>tempDouble;

        tempNode.frequency = tempDouble;
        tempNode.content = tempString;
        tempNode.leftChild = NULL;
        tempNode.rightChild = NULL;
        nodeArray.push_back(tempNode);
    }

    node root = getHuffmanTree();

    BFS(&root,"");
}


int main()
{

    //calls the huffman  function
    Huffman();

    map <string,string>:: iterator it;

    for(it=ss.begin(); it!=ss.end(); it++)
        cout<< it->first <<" "<< it->second <<endl;

    ss.clear();

    return 0;
}
