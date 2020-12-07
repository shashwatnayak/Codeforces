#include<iostream>
using namespace std;
/*
can we reverse LL in less than O(n) ? No;
possible when doubly linked list. Traverse in reverse direction

why mergesort in LL and quicksort in array ?
time and space efficiency better for MS in LL and QS in array
*/
class Node{
public:
int val;
Node* next;

Node(int d){
    val = d;
    next = NULL;
}
};

Node* reverse_rec(Node* head){
if(head == NULL && head->next == NULL){
    return head;
}
Node* temphead = reverse_rec(head->next);
head->next->next = head->next;
head->next = NULL;

return temphead;
}
Node* reverse_iter(Node* head){
Node* cur = head;
Node* prev = NULL;

while(cur && cur->next){
    Node* ah = cur->next;
    cur->next = prev;
    prev = cur;
    cur = ah;
}
return prev;
}
Node* middle_element(Node* head){
Node* slow = head;
Node* fast = head;
fast = fast->next;

while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
}
return slow;
}
Node* merge(Node* a,Node* b){
if(a==NULL){
    return b;
}
if(b==NULL){
    return b;
}
Node* res;
if(a->val < b->val){
res = a;
a->next = merge(a->next,b);
}else{
res = b;
b->next = merge(a,b->next);
}

return res;
}
Node* mergesort(Node* head){
if(head==NULL)return head;

Node* a = head;
Node* tmp = middle_element(head);
Node* b = tmp->next;
tmp->next = NULL;

a = mergesort(a);
b = mergesort(b);
Node* c = merge(a,b);
return c; 
}
bool detect_loop(Node* head){
Node* slow = head;
Node* fast = head;
bool s = false;
while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        s = true;
        break;
    }
}
return s;
}

Node* reverse_inkgroup(Node* head,int k){
if(head == NULL){
    return;
}
Node* cur = head;
Node* ah = NULL;
Node* prev = NULL;
int count = 0;
while(cur!=NULL && count < k){
ah = cur->next;
cur->next = prev;
prev = cur;
cur = ah;
count++;
}
if(ah!=NULL){
    head->next = reverse_inkgroup(ah,k);
}

return prev;
}
void test_cases(){
    Node* a;
    a = reverse_rec(a);
    a = reverse_iter(a);
    cout << detect_loop(a);
    //break_loop(a);
     a = mergesort(a);
    cout << middle_element(a)->val;

}

// To be tested other wise go recursive;
class CNode{
public:
int val;
CNode* right;
CNode* down;
CNode(int d){
    val = d;
    right = NULL;
    down = NULL;
}
};
CNode* downmerge(CNode* a,CNode* b){
if(a == NULL){
    return b;
}else if(b== NULL){
    return a;
}

CNode* res = NULL;

if(a->val < b->val){
res = a;
a->down = downmerge(a->down,b);
}else{
b->down = downmerge(a,b->down);
}

return res;
}
void flatten(CNode* root){
if(root==NULL || root->right == NULL)return;

while(root->down!=NULL){
if(root->right!=NULL){
CNode* b = root->right;
root = downmerge(root,b);
root->right = NULL;
}
root = root->down;
}
}

void inplace_sort(Node* head){
    int count_zero = 0;
    int count_one = 1;
    int count_two = 2;
    Node* cur = head;
    while(cur!=NULL){
        if(cur->val == 0){
            count_zero++;
        }else if(cur->val == 1){
            count_one++;
        }else if(cur->val == 2){
            count_two++;
        }
        cur = cur->next;
    }
    cur = head;
    while(cur!=NULL){
        if(count_zero!=0){
            cur->val = 0;
            count_zero--;
        }else if(count_one!=0){
            cur->val = 1;
            count_one--;
        }else if(count_two!=0){
            cur->val = 2;
            count_zero--;
        }
        cur = cur->next;
    }
}
int main(){

    test_cases();
}