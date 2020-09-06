#include<iostream>
using namespace std;


class TreeNode{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int d){
    val = d;
    left = right = NULL;
  }
};

TreeNode* MakeBSThelper(TreeNode *root,int key){

    if(root == NULL){
      return new TreeNode(key);
    }

    if(root->val >= key){
      root->left = MakeBSThelper(root->left,key);
    }else{
      root->right = MakeBSThelper(root->right,key);
    }
  return root;
}

TreeNode *MakeBST(){
  int c;
  TreeNode *root = NULL;
  cin>>c;
  while(c!=-1){
  root = MakeBSThelper(root,c);
  cin>>c;
  }
  return root;
}
void inorder(TreeNode *root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}
int main(){
  TreeNode *root = MakeBST();
  inorder(root);

}
