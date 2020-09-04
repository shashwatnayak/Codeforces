#include<iostream>
#include<queue>
#include<vector>
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

void bfs_tree(TreeNode *root){

  queue<TreeNode* > q;
  q.push(root);
  q.push(NULL);
while(q.size() > 1){
  TreeNode *cur = q.front();
  q.pop();
if(cur==NULL){
  q.push(NULL);
  cout<<"\n";
}else{
  if(cur->left){
    q.push(cur->left);
  }
  if(cur->right){
    q.push(cur->right);
  }
  cout<<cur->data << " ";
}
}
}
int main(){
TreeNode *root = createTree();
// preorder(root);
// cout<<"\n";
// inorder(root);
// cout<<"\n";
// postorder(root);
// cout<<"\n";

bfs_tree(root);

}
