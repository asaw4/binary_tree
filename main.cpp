#include<bits/stdc++.h>
#include"tree.cpp"

using namespace std;

vector<int> emptyTree{};
vector<int> postiveTree{2,5,6,23,8,9};
vector<int> negativeTree{-9,-5,-7,-4,-6};
vector<int> tree{0,3,-3,54,2,-4};
vector<int> singleEle{1};
vector<int> test{4,2,5,432,-1,34,-1,65,45};

void printVector(vector<int> a){
    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void process(vector<int> treeData, int val) {

    cout<<"\nInput: ";
    
    printVector(treeData);

    TreeNode* t = new TreeNode();

    t->createTree(treeData);

    t->printTree();

    t->preProcessData();

    std::vector<int> res = t->deleteNode(val);

    cout<<"\ndeletion result ";
    printVector(res);

    cout<<"End\n";
}

void testing(){
    process(emptyTree, 0);
    process(postiveTree, 2);
    process(negativeTree,-9);
    process(tree, 0);  
    process(singleEle,1);
    process(test,2);  
}

int main() {
    testing();
    return 0;
}
