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
void test_cases(){
    Node* a;
    a = reverse_rec(a);
    a = reverse_iter(a);
    cout << detect_loop(a);
    //break_loop(a);
     a = mergesort(a);
    cout << middle_element(a)->val;

}
int main(){

    test_cases();
}