#include<bits/stdc++.h>
#include"node.cpp"

using namespace std;

class TreeNode {

    public:
    Node* root;

    TreeNode(){
        root = nullptr;
    }

    void printTree(){
        cout<<"Printing tree: ";

        inorderTraversal(this->root);

        cout<<"\n";
    }

    Node* createTree(vector<int> nodes) {
        if(nodes.size() == 0) {
            return nullptr;
        }

        vector<Node*> parents;
        vector<int> nullCount;

        initializeNullCount(nullCount, nodes);

        Node* root = nullptr;

        int nextChild = 0;

        while(nextChild < nodes.size()) {
            if(nodes[nextChild] == -1) {
                nextChild++;
                parents.push_back(nullptr);
                continue;
            }

            Node* n = new Node(nodes[nextChild]);
            
            if(root == nullptr){
                root = n;
                parents.push_back(n);
                nextChild++;
                continue;
            }

            int index = getParentIndex(nextChild);
            int parentIndex = index + nullCount[index];

            if(nextChild%2 == 0){
                Node* parent = parents[parentIndex];
                parent->right = n;
            }
            else {
                Node* parent = parents[parentIndex];
                parent->left = n;
            }

            nextChild++;
            parents.push_back(n);
        }

        this->root = root;

        return root;
    } 

    vector<int> deleteNode(int val){

        Node* root = this->root;

        vector<int> res;

        Node* n = nullptr;
        
        if(preprocessedData.find(val) == preprocessedData.end()) {
            cout<<"Node Not Found\n";
            return res;
        } 
        
        n = preprocessedData[val];
        if(n != root){
            res.push_back(root->data);
        }

        if(n->left != nullptr){
            res.push_back(n->left->data);
        }

        if(n->right != nullptr){
            res.push_back(n->right->data);
        }

        return res;
    }

    void preProcessData() {
        inorderTraversal(this->root);
    }

    private:

    map<int, Node*> preprocessedData;

    int getParentIndex(int n){
        if(n%2 == 0){
            return (n-1)/2;
        }
        return n/2;
    }
    
    void inorderTraversal(Node* root) {
        if(root == nullptr){
            return;
        }

        this->preprocessedData[root->data] = root;

        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }

    void initializeNullCount(vector<int>& nullCount, vector<int>& nodes){
        if(nodes.size() == 0){
            return ;
        }

        if(nodes[0] == -1){
            nullCount.push_back(1);
        }
        else {
            nullCount.push_back(0);
        }

        for(int i = 1; i < nodes.size(); i++){
            int n = (nodes[i] == -1) ? (nullCount[i - 1] + 1) : (nullCount[i - 1]);
            nullCount.push_back(n); 
        }
    }
};