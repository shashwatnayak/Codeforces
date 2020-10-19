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
     
    int count(ListNode* head){
        int c = 0;
        while(head){
            c++;
            head = head->next;
        }
        return c;
    }
    int getDecimalValue(ListNode* head) {
        int ans = 0 ;
        int n = count(head);
        //cout<<n;
       
        while(head!=NULL){
            ans = (head->val)*(1<<(n-1)) + ans;
            n--;
            head = head->next;
        }
        
        return ans;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        //ListNode* prev;
        
        while(cur!=NULL && cur->next!=NULL){
            ListNode* ah = cur->next;
            
            if(ah->val == cur->val){
                cur->next = ah->next;
            }else{
                cur = cur->next;
            }
         }
        
        return head;

    }
};

class Solution {
public:
    
    int count(ListNode* h){
        int c = 0;
        while(h){
            c++;
            h = h->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = count(headA);
        int c2 = count(headB);
        cout<<c1 << c2;
        int k;
        if(c1>c2){
            k = c1-c2;
            cout<<k;
            while(k--){
                  headA=headA->next;
            }
        }else{
            k = c2-c1;
            while(k--){
                headB=headB->next;
            }
        }
        
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        
        return NULL;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
 
        ListNode *temp = head;

        while (temp && temp->next) {
            if(temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        if (head && head->val == val) return head->next;
        return head;
    }
};