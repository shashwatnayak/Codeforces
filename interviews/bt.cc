#include<iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};