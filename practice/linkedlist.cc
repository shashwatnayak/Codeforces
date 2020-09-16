#include<iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int d){
        val = d;
        next = NULL;
    }
};

Node* createLL(){
    int x;
    Node* head = NULL;
    Node* tail = NULL;

    while(cin>>x && x!=-1){
        Node* temp = new Node(x);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}
void printLL(Node* a){
    while(a){
        cout<<a->val<<" ";
        a = a->next;
    }
    cout<<endl;
}

//Palindrome List
//Remove Duplicates I and II
//Merge Lists
//Remove Nth Node from end
//Reverse List
//K Reverse List
//Swap List Nodes in pairs
//Rotate List
//Add two numbers in List
//Cycle Detection in List
//Merge sort
//Partition List
//Insertion Sort
//Bubble Sort
//Reorder List
//Reverse Linked List 2
//Circular List
//Double Linked List
//Intersection List
//Sort Binary Linked List
//Kth Node from Middle
//Even Reverse
int main(){
    Node* a = createLL();
    printLL(a);
    }