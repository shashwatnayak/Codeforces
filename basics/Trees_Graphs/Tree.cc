#include<iostream>
using namespace std;

class TreeNode{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

//DFS Based Tree Parsing
TreeNode *createTree(){
  int x;
  cin>>x;
  if(x==-1)return NULL;

  TreeNode *temp = new TreeNode(x);
  temp->left = createTree();
  temp->right = createTree();

  return temp;
}

void preorder(TreeNode *root){
  if(root == NULL){
    return;
  }
  cout<<root->data<< " ";
  preorder(root->left);
  preorder(root->right);

}

void inorder(TreeNode *root){
  if(root ==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data << " ";
  inorder(root->right);

}

void postorder(TreeNode *root){
if(root == NULL){
  return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data << " ";
}

//BFS Based Tree Parsing

int main(){
TreeNode *root = createTree();
preorder(root);
cout<<"\n";
inorder(root);
cout<<"\n";
postorder(root);
cout<<"\n";

}
