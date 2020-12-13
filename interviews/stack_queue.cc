#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Stack{
class Node{
    public:
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};

Node* head;
Node* tail;
Stack(){
head = tail = NULL;
}
void push(int val){
Node* tmp = new Node(val);
if(head == NULL){
    head = tail = tmp;
}else{
 tail->next = tmp;
 tail = tail->next;  
}
}
int top(){
return tail->val;
}
void pop(){
Node* tmp = head;

while(tmp->next->next!=NULL){
    tmp = tmp->next;
}
tail = tmp;
tmp = tmp->next;
tail->next = NULL;
delete(tmp);

}
int size(){
int count = 0;
Node* tmp = head;
while(tmp!=NULL){
count++;
tmp = tmp->next;
}
return count;
}
~Stack(){
Node* tmp = head;

while(head!=NULL){
    tmp = head->next;
    delete(head);
    head = tmp;
}
}
};

//TB Verify from actualy behavior
class queue{
class Node{
    public:
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};

Node* front;
Node* rear;
queue(){
front = rear = NULL;
}
void push(int val){
Node* tmp = new Node(val);
if(front == NULL){
    front = rear = tmp;
}else{
 rear->next = tmp;
 rear = rear->next;  
}
}
int top(){
return front->val;
}
void pop(){
Node* tmp = front->next;
delete(front);
front = tmp;
}
int size(){
int count = 0;
Node* tmp = front;
while(tmp!=NULL){
count++;
tmp = tmp->next;
}
return count;
}
~queue(){
Node* tmp = front;

while(front!=NULL){
    tmp = front->next;
    delete(front);
    front = tmp;
}
}
};

void reverse_Str(string a){
    stack<char> s;
    for(int i = 0;i<a.size();i++){
        s.push(a[i]);
    }
    for(int i = 0;i<a.size();i++){
        a[i] = s.top();
        s.pop();
    }
}

stack<char> st;
string s;
void insert_at_bottom(char x){
    if(st.size()==0){
        st.push(x);
    }else{
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}
void stack_reverse(){
while(st.size()>0){
    char x = st.top();
    st.pop();
    stack_reverse();
    insert_at_bottom(x);
}
}
void insert_sortstack(stack<int> s,int x){
if(s.size()==0 || x > s.top()){
s.push(x);
return;
}
int tmp = s.top();
s.pop();
insert_sortstack(s,x); 
s.push(tmp);
}
void sortStack(stack<int> s){
if(s.size()!=0){
int x = s.top();
s.pop();
sortStack(s);
insert_sortstack(s,x);
}
}
int main(){

}