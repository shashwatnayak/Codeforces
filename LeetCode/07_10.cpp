#include<iostream>
#include<vector>
using namespace std;

// Counting total set bits
class Solution {
public:
    
    
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
      
        ans[0] = 0;
        for(int i = 1;i<=num;i++){
           if((i&1) == 0){
               ans[i] = ans[i/2];
           }else{
               ans[i] = ans[i-1] + 1;
           }
        }
        return ans;
    }
};
// Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

//Tribonacci Numbers
class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1||n==2){
            return 1;
        }
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        
        
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-3]+ dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


//Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0||n==1){
            return 1;
        }
        int dp[n+1];
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//Range Sum of BST
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
    vector<int> vi;
    void build(TreeNode* root){
        if(root==NULL){
            vi.push_back(0);
            return;
        }
        build(root->left);
        vi.push_back(root->val);
        build(root->right);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
       
        build(root);
        int sum = 0;
        int l,r;
        for(int i = 0;i<vi.size();i++){
            if(vi[i] == L){
                l = i;
            }
            if(vi[i] == R){
                r = i;
            }
        }
        
        while(l<=r){
            sum+=vi[l];
            l++;
        }
        return sum;
    }
};