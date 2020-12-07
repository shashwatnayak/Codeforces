#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<utility>
using namespace std;

typedef pair<int,TreeNode* > PAIR;
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
TreeNode* a;
TreeNode* b;
TreeNode* lcaroot = LCAHelp(a,b);
}

void bottom_view(TreeNode* root){
queue<pair<int,TreeNode*> > q;
map<int,TreeNode* > m;
q.push(make_pair(0,root));

while(!q.empty()){
    int hd = q.front().first;
    TreeNode* cur = q.front().second;
    q.pop();
    m[hd] = cur;
    if(cur->left){
        q.push(make_pair(hd-1,cur->left));
    }
    if(cur->right){
        q.push(make_pair(hd+1,cur->right));
    }
}
map<int,TreeNode*> :: iterator it = m.begin();
while(it!=m.end()){
    cout << it->second->val;
    it++;
}
}

void left_view(TreeNode* root){
queue<TreeNode* > q;
q.push(root);

while(!q.empty()){
    int n = q.size();
    for(int i = 1;i<=n;i++){
        TreeNode* cur = q.front();
        q.pop();

        if(i==1){
            cout << cur->val << " ";
        }
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
    }
}
}
void right_view(TreeNode* root){
queue<TreeNode* > q;
q.push(root);

while(!q.empty()){
    int n = q.size();
    for(int i = 1;i<=n;i++){
        TreeNode* cur = q.front();
        q.pop();

        if(i==n){
            cout << cur->val << " ";
        }
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
    }
}
}
void top_view(TreeNode* root){
queue<pair<int,TreeNode*> > q;
map<int,vector<TreeNode*> > m;
q.push(make_pair(0,root));

while(!q.empty()){
    int hd = q.front().first;
    TreeNode* cur = q.front().second;
    q.pop();
    m[hd].push_back(cur);
    if(cur->left){
        q.push(make_pair(hd-1,cur->left));
    }
    if(cur->right){
        q.push(make_pair(hd+1,cur->right));
    }
}
for(auto it = m.begin();it!=m.end();it++){
    cout << it->second[0]->val;
}
}
void test_cases(){
    TreeNode* root = createTree();
    int ans = -1e9;
    int x = diameter(root,ans);
}
int main(){
    test_cases();
}