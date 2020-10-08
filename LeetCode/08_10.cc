//Binary Search

class Solution {
public:
    
    int foo(vector<int> arr, int l,int r,int target){
        
           while(l<=r){
               int mid = (l+r)/2;
               
               if(arr[mid]==target){
                   return mid;
               }
               
               if(arr[mid]<=target){
                   l = mid+1;
               }else{
                   r = mid-1;
               }
           }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int a = foo(nums,0,nums.size()-1,target);
        
        return a;
    }
};
 
// Product of array except Self (poor Version) in python and not C++
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        
        L,R,ans = [0]*length,[0]*length,[0]*length
        
        L[0] = 1
        
        for i in range(1,length):
            L[i] = L[i-1] * nums[i-1]
            
        R[length-1] = 1;
        for i in reversed(range(length-1)):
            R[i] = R[i+1] * nums[i+1]
            
        for i in range(length):
            ans[i] = L[i]*R[i]
            
            
        return ans
//Reverse string
        class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l = 0;
        int r = s.size();
        
        while(l<=r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }           
};

//Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = ((n+1)*(n))/2;
        int sum2 = 0;
        for(auto a : nums){
            sum2 += a;
        }
        
        return sum1-sum2;
    }
};


// Odd Even Linked List. Better Version Maybe ?? 
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
         int sum = 0;
         while(head){
             sum++;
             head = head->next;
         }
         return sum;
     }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next==NULL){
            return head;
        }
        int c = count(head);
        ListNode* cur = head;
        ListNode* b = head->next;
        if(c%2 == 0){
        while(cur && cur->next && cur->next->next){
            ListNode* ah = cur->next;
            cur->next = cur->next->next;
            cout<<cur->val << " ";
            cur = ah;
        }
            cur->next = b;
        }else{
            while(cur && cur->next){
            ListNode* ah = cur->next;
            cur->next = cur->next->next;
            cout<<cur->val << " ";
            cur = ah;
        }
            cur->next = b;
        }
        //cur = cur->next;
        
        return head;
    }
};

//Palindrome List

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
    
    ListNode* reverse(ListNode* a){
        
        ListNode* prev = NULL;
        ListNode* cur = a;
        
        while(cur){
            ListNode* ah = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ah;
            
        }
        return prev;
    }
    ListNode* midpoint(ListNode* a){
        ListNode* slow = a;
        ListNode* fast = a->next;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        bool flag = true;;
        ListNode* a = head;
        ListNode* mid = midpoint(head);
        ListNode* b = mid->next;
        b = reverse(b);
        mid->next = NULL;
        
        while(a!=NULL && b!=NULL){
            if(a->val != b->val){
                flag = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        return flag;
    }
};