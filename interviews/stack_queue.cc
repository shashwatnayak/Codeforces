#include<iostream>
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