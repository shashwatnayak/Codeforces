
// Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        queue<int> level;
        //TreeNode* cur = root;
        vector<vector<int>> sol;
        vector<int> tmp;
        
        if(root==NULL){
            return sol;
        }
        
        q.push(root);
       level.push(0);
        
        while(!q.empty()){
            
            TreeNode* cur = q.front();
            int lev = level.front();
           
            
            if(sol.size()!=level.front()+1){
                sol.push_back(tmp);
            }
            sol[lev].push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
                level.push(lev+1);
            }
            if(cur->right){
                q.push(cur->right);
                level.push(lev+1);
            }
            q.pop();
            level.pop();
         
        }
        return sol;
    }
};
// Cycle Detection
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        bool flag = false;
        
        while(slow && fast && fast->next && fast->next->next){
             
            slow = slow->next;
            fast = fast->next->next;
            if(slow->val == fast->val){
                flag = true;
                break;
            }
        }
        
        return flag;
    }
};
// Minimum Depth of B-tree
class Solution {
public:
    

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        if(!root->left){
            return 1 + minDepth(root->right);
        }
        if(!root->right){
            return 1 + minDepth(root->left);
        }
    
        int lf = minDepth(root->left);
        int rg = minDepth(root->right);
        
        return 1 + min(lf,rg);
       
    }
};
//Maximum Level Sum of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q;
        queue<int> level;

        vector<vector<int>> sol;
        vector<int> tmp;
        
        if(root==NULL){
            return 0;
        }
        
       q.push(root);
       level.push(0);
        
        while(!q.empty()){
            
            TreeNode* cur = q.front();
            int lev = level.front();
           
            
            if(sol.size()!=level.front()+1){
                sol.push_back(tmp);
            }
            sol[lev].push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
                level.push(lev+1);
            }
            if(cur->right){
                q.push(cur->right);
                level.push(lev+1);
            }
            q.pop();
            level.pop();
         
        }
        int maxSum = -1e9;
        int s;
        vector<int> Sum;
        for(int i = 0;i<sol.size();i++){
            s = 0;
            for(int j = 0;j<sol[i].size();j++){
                s+=sol[i][j];
            }
            Sum.push_back(s);
        }
       // for(int i = 0;i<Sum.size();i++){
       //     cout << Sum[i] << " ";
       // }
        int m = -1e9;
        for(int i = 0;i<Sum.size();i++){
            m = max(m,Sum[i]);
        }
        
        
        for(int i = 0;i<Sum.size();i++){
           cout << Sum[i] << " ";
       }
        
        
        int lev = 1;
        
        for(int i = 0;i<Sum.size();i++){
            if(Sum[i] == m){
                if(i==0){
                    break;
                }
                lev = i + 1;
            }
        }
        
        
        return lev ;
    }
};

//Middle Node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;
        int c = 0;
        
        while(head!=NULL){
            c++;
            head = head->next;
        }
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(c%2==0){
            return slow->next;
        }
        return slow;
    }
};