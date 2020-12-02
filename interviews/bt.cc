#include<iostream>
#include<queue>
#include<map>
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
TreeNode* createTree(){
    int x;
    cin>>x;
    if(x==-1)return NULL;

    TreeNode* root = new TreeNode(x);
    root->left = createTree();
    root->right = createTree();

    return root;
}
void levelorder(TreeNode* root){
queue<TreeNode*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    TreeNode* cur = q.front();
    q.pop();
    cout<< cur->val << " ";
    if(q.size()!=0 && cur == NULL){
        cout<<endl;
        q.push(NULL);
    }
    if(cur->left){
        q.push(cur->left);
    }
    if(cur->right){
        q.push(cur->right);
    }

}
}

void reverseLevelOrder(TreeNode* root){
    
}
int heightTree(TreeNode* root){
if(root==NULL){
    return 0;
}
int left = heightTree(root->left);
int right = heightTree(root->right);

return 1 + max(left,right);
}

// max height in left subtree, max height in right subtree, then max of left diamater and right diamater
// O(n^2) solution - where height and diameter calculated separately 
// O(n) where height and diameter solved simulataneously 
int diameter(TreeNode* root,int ans){
if(root==NULL){
    return 0;
}

int leftdia = diameter(root->left,ans);
int rightdia = diameter(root->right,ans);

ans = max(ans,1+leftdia+rightdia);

return 1 + max(leftdia,rightdia);
}

void makeMirror(TreeNode* root,TreeNode* &mirror){
if(root==NULL){
return;
}

mirror = new TreeNode(root->val);
makeMirror(root->right,mirror->left);
makeMirror(root->left,mirror->right);

return;
}
bool isMirror(TreeNode* a,TreeNode* b){
if(a == NULL && b == NULL){
    return true;
}
if(a->val == b->val && isMirror(a->left,b->right) && isMirror(a->right,b->left)){
    return true;
}
return false;
}

void inorder(TreeNode* root){
if(root == NULL)return ;

inorder(root->left);
cout << root->val << " ";
inorder(root->right);
}
void preorder(TreeNode* root){
if(root == NULL)return ;

cout<<root->val << " ";
preorder(root->left);
preorder(root->right);
}
void postorder(TreeNode* root){
if(root==NULL)return ;

postorder(root->left);
postorder(root->right);
cout << root->val << " ";
}

// Morris traversal or Stack implementation later
void inorder_Iter(){

}
void preorder_Iter(){

}
void postorder_Iter(){

}

TreeNode* LCAHelp(TreeNode* a,TreeNode* b){

}
TreeNode* LCA(){
TreeNode* lcaroot = LCAHelp();
}
void test_cases(){
    TreeNode* root = createTree();
    int ans = -1e9;
    int x = diameter(root,ans);
}
int main(){
    test_cases();
}