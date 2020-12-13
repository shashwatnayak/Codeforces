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
class Queue{
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
Queue(){
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
~Queue(){
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

class Stack_using_queue{
queue<int> q1,q2;
public:
Stack_using_queue(){}
void push(int x){
q2.push(x);
while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
}
queue<int>tmp = q1;
q1 = q2;
q2 = tmp;
}
void pop(){
q2.pop();
}
void size(){
cout << q1.size();
}
void top(){
cout << q2.front();
}
};

// Easy - using STL
/*class Stack_using_deque{
deque<int> q;
public:
void push(int x){
q.push_back(x);
}
void pop(){
q.pop_back();
}
void top(){
cout << q.back();
}
void size(){
cout << q.size();
}
};
*/

class DEQUE{
private:
    class dqNode{
        public:
        int val;
        dqNode* next;
        dqNode* prev;
        dqNode(int x){
            val = x;
            prev = NULL;
            next = NULL;
        }
        // dqNode(){
        //     next = NULL;
        //     prev = NULL;
        // }
};
dqNode *head;
dqNode *tail;
public:
DEQUE(){
    head = tail = NULL;
}
bool isEmpty(){
    if(head == NULL){
        return true;
    }
    return false;
}

int size(){
if(!isEmpty()){
    return 0;
}else{
    int len = 0;
    dqNode* tmp = head;
    while(tmp!=NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}
}
void insert_first(int x){
dqNode* tmp = new dqNode(x);
if(head==NULL){
head = tail = tmp;
//tmp->next = tmp->prev = NULL;
}else{
head->prev = tmp;
tmp->next = head;
tmp->prev = NULL;
head = tmp;
}
}
void insert_back(int x){
dqNode* tmp = new dqNode(x);
if(head==NULL){
head = tail = tmp;
//tmp->next = tmp->prev = NULL;
}else{
tail->next = tmp;
tmp->next = NULL;
tmp->prev = tail;
tail = tmp;
}
}
void remove_first(){
if(!isEmpty()){
    dqNode *tmp = head;
    head = head->next;
    head->prev = NULL;
    delete(tmp);
    return;
}
}
void remove_back(){
if(!isEmpty()){
    dqNode *tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete(tmp);
    return;
}
}

void display(){

}
};

class STACK_DQ : public DEQUE {
DEQUE s;

public:

void push(int x){
s.insert_back(x);
}
void pop(){
s.remove_back();
}
};
class QUEUE_DQ : public DEQUE {
DEQUE q;
public:
void push(int x){
q.insert_back(x);
}
void pop(){
q.remove_first();
}
};

int main(){

}