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
//Construction and conversion

//Check if

//Summation

//LCA

//Extra
int main(){

    TreeNode *root = MakeTree();
    //inorder(root); // recursion
    //inorder2(root); // 1 stack
    //preorder(root); //recursion
    //preorder2(root); // 1 stack
    //postorder(root); // recursion
    //postorder2(root); //2 stack
    inorder3(root); // no stack and no recursion
    //postorder3(root); // 1 stack
    //levelorder(root) // 1 queue
    //verticalorder(root); // map

    // What's Morris Traversal ? 
    // if left child of cur node exist, Point rightmost node of left subtree towards right subtree(handle right node cases as well)
    // and start processing left nodes
    // Other wise print left node and start processing right nodes   

}
