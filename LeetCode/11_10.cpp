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