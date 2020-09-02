#include<iostream>
using namespace std;

//More to be practicsed in Interview Bit Linked List
class Node{
public:
  int data;
  Node *next;

  Node(int d){
    data = d;
    next = NULL;
  }
};

void printlist(Node *tmp){
  while(tmp!=NULL){
    cout << tmp->data << "-> " ;
    tmp = tmp->next;
  }
}

Node* MakeList(){
  Node *head = NULL;
  Node *tail = NULL;
  int x;

  while(x!=-1 && cin>>x){
    if(x==-1)break;
    Node *tmp = new Node(x);
    if(head == NULL){
      head = tmp;
      tail = tmp;
    }else{
      tail->next = tmp;
      tail = tail->next;
    }
  }
  return head;
}

Node* reverseiterll(Node *a){
Node *tmp = a;
Node *prev = NULL;
Node *ahead;

while(tmp!=NULL){
  ahead = tmp->next;
  tmp->next = prev;
  prev = tmp;
  tmp = ahead;
}
return prev;
}

Node* reverserecursive(Node *a){
  if(a == NULL || a->next == NULL){
    return a;
  }
  Node *curhead = reverserecursive(a->next);
  a->next->next = a;
  a->next = NULL;
  return curhead;
}
int main(){
  Node *a = MakeList();
  //printlist(a);
  //a = reverseiterll(a);
  //printlist(a);

  // a = reverserecursive(a);
  // printlist(a);
}
