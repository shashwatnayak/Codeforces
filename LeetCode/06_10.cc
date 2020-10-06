#include<iostream>
using namespace std;
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

//Merge Sorted List
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* ans;
        
        if(l1->val <= l2->val){
            ans = l1;
            ans->next = mergeTwoLists(l1->next,l2); 
        }else{
            ans = l2;
            ans->next = mergeTwoLists(l1,l2->next);
        }
        
        return ans;
    }
// Reverse List
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        while(cur!=NULL){
            ListNode* ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
            
        }
        return prev;
    }

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

//Invert Tree
class Solution {
public:
    void check(TreeNode* a){
        if(a==NULL){
            return;
        }
        TreeNode* temp = NULL;
        check(a->left);
        check(a->right);
        
        temp = a->left;
        a->left = a->right;
        a->right = temp;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        check(root);
        return root;
    }
};

// Same Tree
class Solution {
public:
    bool check(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL){
            return true;
        }
        if(a!=NULL && b!=NULL && a->val == b->val){
            return check(a->left,b->left) && check(a->right,b->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q!=NULL){
            return false;
        }else if(p!=NULL && q==NULL){
            return false;
        }
        return check(p,q);
    }
};
//Symmetric Tree
class Solution {
public:
    bool check(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL){
            return true;
        }
        if(a!=NULL && b!=NULL && a->val == b->val){
            return check(a->left,b->right) && check(a->right,b->left); 
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
    bool a = check(root,root);
        if(a){
            return true;
        }else{
            return false;
        }
    }
};
// Path Sum
class Solution {
public:
    bool check(TreeNode* root,int sum){
        if(root == NULL){
            return (sum == 0);
        }else{
        bool a = false;
            int d = sum - root->val;
            if(d == 0 && root->left == NULL && root->right == NULL){
                return true;
            }
            
            if(root->left){
                a = a || check(root->left,d);
            }
            if(root->right){
                a = a || check(root->right,d);
            }
            
            return a;
    }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        return check(root,sum);
    }
};