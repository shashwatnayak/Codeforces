/* 1.Given an integer array and a constant number X, print all pair of number in the array whose product is equal to X.
follow ups: how will you do in O(n)? how will you handle duplicate pairs?
2.He asked do I know level order traversal of binary tree. He ask me to code then, he changed the question and asked about spiral order traversal of binary Tree and asked me to code it.
3.In a BST two nodes were swapped. Given the pointer to root node find the two nodes and rectify the tree. He asked the approach then asked me to code the same in collabedit.
4.Given an integer array, find and print three element in the array whose product is maximum. Code was required.
5.Given a sorted array of n integers, count and display number of triplets such that a[i] < a[j] < a[k] 0(n) time. Code was required.
6.In a given string some of the characters are replaced by question mark, and you can replace question mark with any character. Given such a string find total number of palindrome that can created. String contains only [a-z] characters and question marks can also be only replaced by [a-z]. Example: Input String: String str=”a??a” Output: 26<F10>
7.Given a binary tree all the left leaf nodes in the form of a doubly linked list. Find the height of the tree.
8.Given N sorted LinkList of different length, merge them into a single sorted link list. Pseudo code was required.
9.Given a number d and size of array N. Print all combination of element in the array such that first element of array is d and next element in the array can be +1 or -1 the previous element in the array. Code was required.
*/
#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<stack>
using namespace std;
typedef vector<int> vi;

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

TreeNode* createTree(){
int x;
cin>>x;
if(x==-1)return NULL;

TreeNode* root = new TreeNode(x);
root->left = createTree();
root->right = createTree();

return root;
}

void printpair(vi A,int X){
int sz = A.size();
set<int> s;
// handle zero case with if-else
for(auto a : A){
    s.insert(a);
}
for(auto p : A){
    int c = X/p;
    if(s.find(c)==s.end()){
        cout << c << " " << p;
    }
}
}

void spiralorder(TreeNode* root){
//LevelOrder Print
stack<TreeNode*> s1;
stack<TreeNode*> s2;
s1.push(root);
while(!s1.empty() || !s2.empty()){
while(!s1.empty()){
    TreeNode* cur = s1.top();
    cout << cur->val << " ";
    s1.pop();
    if(cur->left){
        s2.push(cur->left);
    }
    if(cur->right){
        s2.push(cur->right);   
    }
}

while(!s2.empty()){

    TreeNode* cur = s2.top();
    cout << cur->val << " ";
    s2.pop();
    if(cur->left){
        s1.push(cur->left);
    }
    if(cur->right){
        s1.push(cur->right);   
    }
}

}

}
int main(){
vi A;

return 0;
}
