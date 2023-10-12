#include<bits/stdc++.h>
using namespace std;

class Node {

    public:

    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data = val;
        // Left and right child for node
        // will be initialized to null
        left = nullptr;
        right = nullptr;
    }

    Node()
    {
        data = -1;
        // Left and right child for node
        // will be initialized to null
        left = nullptr;
        right = nullptr;
    }
};

