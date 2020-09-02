#include<iostream>
using namespace std;

class Stack{

private:
class Node{
public:
  int data;
  Node *next;
  Node(int d){
    data = d;
    next = NULL;
  }
};
Node *head,*tail;

public:
  Stack(){
    head = NULL;
    tail = NULL;
  }
  bool is_empty(){
    if(head == tail == NULL){
      return true;
    }
    return false;
  }
  void push(int x){

    Node *tmp = new Node(x);
    if(head == NULL){
      head = tmp;
      tail = tmp;
    }else{
      tail->next = tmp;
      tail = tail->next;
    }
  }

// some problem with 1 element in Stack
// rest is fine
// debug it
  void pop(){
    if(head == NULL){
      cout<<"Stack Empty";
      exit(1);
    }
    if(head->next == NULL){
      delete(head);
      //head = NULL;
    }
    Node *tmp = head;
    Node *prev;
    Node *ahead;
    while(tmp->next!=NULL){
      prev = tmp;
      tmp = tmp->next;
    }
    ahead = prev->next;
    prev->next = NULL;
    delete(ahead);
  }

  int size(){
    int c = 0;
    Node *tmp = head;
    while(tmp!=NULL){
      c++;
      tmp = tmp->next;
    }
    return c;
  }

  int top(){
    if(head == NULL){
      return -1;
    }
    if(head->next == NULL){
      return head->data;
    }

      Node *tmp = head;
      while(tmp->next!=NULL){
        tmp = tmp->next;
      }
  return tmp->data;
  }

};

int main(){
Stack s;
s.push(1);
s.push(2);
s.push(3);
cout << s.size() <<endl;
cout << s.top() << endl;
s.pop();
cout<< s.top() <<endl;
s.pop();
cout<<s.size()<<endl;
cout<<s.top()<<endl;

s.pop();
cout<<s.top()<<endl;
cout<<s.size()<<endl;

}
