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

//Merge Binary Trees
class Solution {
public:
    //TreeNode* t3;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
       if(t1==NULL){
           return t2;
       }
       if(t2==NULL){
           return t1;
       }
        
        TreeNode* t3 = new TreeNode(t2->val + t1->val);
        
        t3->left = mergeTrees(t1->left,t2->left);
        t3->right = mergeTrees(t1->right,t2->right);
        
        return t3;
        
        
    }
};
//Remove OuterMost Paranthesis
class Solution {
public:
    string removeOuterParentheses(string S) {
       int count = 0;
        std::string str;
        for (char c : S) {
            if (c == '(') {
                if (count++) {
                    str += '(';
                }
            } else {
                if (--count) {
                    str += ')';
                }
            }
        }
        return str;
    
    }
};

// Print DAG Graph
// All path from source to node
class Solution {
public:
    vector<int>tmp;
    vector<vector<int>>res;
    int tg;
   void dfs(vector<vector<int>>& graph,int curNode = 0){
       tmp.push_back(curNode);
       
       if(curNode==tg){
         res.push_back(tmp);
       }
       else{
           for(int x : graph[curNode]){
               dfs(graph,x);
           }
       }
       
       tmp.pop_back();
       
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       tg = graph.size()-1;
        dfs(graph);
        return res;
    }
};

// Find Town Judge
// in-out degree
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N+1);
        
        for(auto x:trust){
            count[x[0]]--;
            count[x[1]]++;
        }
        for(int i = 1;i<=N;i++){
            if(count[i] == N-1){
                return i;
            }
        }
        return -1;
    }
};
