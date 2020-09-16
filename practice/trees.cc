#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        val = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* MakeTree(){

int x;
cin>> x;
if(x==-1){return NULL;}

TreeNode* root = new TreeNode(x);
root->left = MakeTree();
root->right = MakeTree();
return root;
}

//Traversals
void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void inorder2(TreeNode* root){

    bool flag = true;
    stack<TreeNode *> s;
    TreeNode* cur = root;

    while(flag){
        if(cur!=NULL){
            s.push(cur);
            cur = cur->left;
        }else if(cur == NULL && s.empty() == false){
            cur = s.top();
            s.pop();
            cout<<cur->val<<" ";
            cur = cur->right;
        }else{
            flag = false;
        }
    }
}

void inorder3(TreeNode* root){

    TreeNode* cur = root;
    TreeNode* prev;

    while(cur!=NULL){

        if(cur->left==NULL){
            cout<<cur->val<<" ";
            cur = cur->right;
        }else{
            prev = cur->left;
            while(prev->right!=NULL && prev->right!=cur){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }else{
                prev->right = NULL;
                cout<<cur->val << " ";
                cur = cur->right;
            }
        }
    }
}

void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorder2(TreeNode* root){
    
    stack<TreeNode *> s;
    TreeNode* cur = root;
    s.push(cur);
    while(cur!=NULL && s.empty()==false){
        cur = s.top();
        s.pop();
        cout<<cur->val << " ";

        if(cur->right){
            s.push(cur->right);
        }
        if(cur->left){
            s.push(cur->left);
        }
    }
}
void postorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void postorder2(TreeNode *root){
    stack<TreeNode *>s,ss;
    TreeNode* cur;
    s.push(cur);

    while(!s.empty()){
        cur = s.top();
        ss.push(s.top());
        s.pop();

        if(cur->left){
            s.push(cur->left);
        }  
        if(cur->right){
            s.push(cur->right);
        }

    }
    TreeNode *s2;
    while(!ss.empty()){
        s2 = ss.top();
        ss.pop();
        cout<<s2->val << " ";
    }
}

void levelorder(TreeNode *root){
    queue<TreeNode*> q;
    TreeNode* cur = root;
    q.push(cur);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

    }
}

void verticalorder(TreeNode* root){
TreeNode* cur = root;
map<int,vector<TreeNode*> > m;
queue<pair<int,TreeNode*> >q;
q.push(make_pair(0,cur));

while(!q.empty()){
    TreeNode* a = q.front().second;
    int hd = q.front().first;
    m[hd].push_back(a);

    if(a->left){
        q.push(make_pair(hd-1,a->left));
    }
    if(a->right){
        q.push(make_pair(hd+1,a->right));
    }
}

map<int,vector<TreeNode*> > :: iterator it = m.begin();
while(it!=m.end()){
    cout<<it->first << ":";
    for(int i = 0;i<it->second.size();++i){
        cout<<it->second[i]->val << " ";
    }
    cout<<endl;
}

}

bool symmetryTree(TreeNode* r1,TreeNode* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if( r1 && r2 &&r1->val == r2->val){
        return symmetryTree(r1->left,r2->right) && symmetryTree(r1->right,r2->left);
    }

    return false;
}

void boundaryprint(){

    //print left boundary;
    //print left subtree right to left;
    //print right subtree right to left;
    //print right boundary;
}
//Construction and conversion

int SumTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int old_val = root->val;

    root->val = SumTree(root->left) + SumTree(root->right);

    return root->val + old_val;
}
//Check if
bool isMirror(TreeNode* r1,TreeNode* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    // if(r1 == NULL || r2 == NULL){
    //     return false;
    // }
    if(r1 && r2 && r1->val == r2->val){
        return isMirror(r1->left,r2->right) && isMirror(r1->right,r2->left); 
    }
    return false;
}

bool isIdentical(TreeNode* r1,TreeNode* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 && r2 && r1->val == r2->val){
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
}
//Summation

//LCA
TreeNode* LCA(TreeNode* root,int key1,int key){
if(root==NULL){
    return NULL;  // base case
}
if(root->val == key1 || root->val == key2){  // if 1 key match return root.
    return root;
}
TreeNode* left_subTree = LCA(root->left,key1,key2); //check left subtree
TreeNode* right_subTree = LCA(root->right,key1,key2); // check right subtree

if(left_subTree && right_subTree) return root; // if left and right subtree has key in left and right trees respectively return common node
return  (left_subTree == NULL) ? right_subTree:left_subTree; // otherwise check in left or right sub tree
}
//Extra
int main(){

    TreeNode *root = MakeTree();
    TreeNode *root1 = MakeTree();
    TreeNode *root2 = MakeTree();
    //inorder(root); // recursion
    //inorder2(root); // 1 stack
    //preorder(root); //recursion
    //preorder2(root); // 1 stack
    //postorder(root); // recursion
    //postorder2(root); //2 stack
    //inorder3(root); // no stack and no recursion
    //postorder3(root); // 1 stack
    //levelorder(root) // 1 queue
    //verticalorder(root); // map
    

    // What's Morris Traversal ? 
    // if left child of cur node exist, Point rightmost node of left subtree towards right subtree(handle right node cases as well)
    // and start processing left nodes
    // Other wise print left node and start processing right nodes   

    cout<< symmetryTree(root,root);
    cout<< isMirror(root1,root2);
    cout<<SumTree(root);
    cout<<isIdentical(root,root);

}
