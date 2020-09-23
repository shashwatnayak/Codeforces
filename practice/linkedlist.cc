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

int Length(Node* a){
    int c = 0;
    while(a!=NULL){
        c++;
        a = a->next;
    }
    return c;
}
//Reverse List
Node* ReverseList(Node* a){
    Node* cur = a;
    Node* prev = NULL;
    while(cur!=NULL){
        Node* ahead = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ahead;
    }

    return prev;
}

Node* getMiddle(Node* cur){
//Fixed
Node* slow = cur;
Node* fast = cur->next;
// fast = fast->next;

while(fast!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;
}
return slow;
}
//Palindrome List
bool isPalindrome(Node* a){
    Node* cur = a;
    Node* cur2 = getMiddle(a);
    Node* cur3 = cur2->next;
    cur2->next = NULL;
    cur3 = ReverseList(cur3);

    while(cur3!=NULL && cur!=NULL){
        if(cur3->val!=cur->val){
            return false;
        }
        cur3 = cur->next;
        cur = cur->next;
    }
    return true;
}
//Remove Duplicates I and II
// Some problem with this question
Node* remove_Duplicates(Node* head,int key){
    if(head==NULL)return NULL;
    
    while(head->val == key){
        head = head->next;
    }

    Node* prev = NULL;
    Node* cur = head;
    while(cur!=NULL && cur->next!=NULL){
        Node* ahd = cur->next;
        
        while(cur->val == key){
            if(cur->next!=NULL){
            cur = cur->next;
            }else{
                cur->next = NULL;
            }
            prev->next = ahd;
        }
        prev = cur;
        cur = ahd;
    }
    return head;
}
//Merge Lists
//Fixed

Node* merge(Node*a,Node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	//Otherwise !
	Node* c;
	if(a->val < b->val){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}
//Remove Nth Node from end
//K Reverse List
//Swap List Nodes in pairs
//Rotate List
//Add two numbers in List
//Cycle Detection in List
//Merge sort

Node* mergeSort(Node *head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	//Rec Case
	Node *mid = getMiddle(head);
	Node *a = head;
	Node *b = mid->next;
	mid->next = NULL;

	//Sort the two halves
	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);

}
//Partition List
//Insertion Sort
//Bubble Sort
//Reorder List
//Reverse Linked List 2
//Circular List
//Double Linked List
//Intersection List

Node* IntersectList(Node* a,Node* b){
    int l1,l2,l3;
    l1 = l2 = l3 = 0;
    //Node* slow = NULL;
    //Node* fast = NULL:
    l1 = Length(a);
    l2 = Length(b);

    if(l2>l1){
        l3 = l2-l1;
        while(l3!=0){
            l3--;
            b = b->next;
        }
    }else{
        l3 = l1-l2;
        while(l3!=0){
            l3--;
            a = a->next;
        }
    }

    while(a!=NULL && b!=NULL){
        a = a->next;
        b = b->next;
    }
    return a;

}
//Sort Binary Linked List

void sortBinaryList(Node* a){
    Node* cur = a;
    Node* fix = a;
    int n0,n1;
    n0 = n1 = 0;

    while(cur!=NULL){
        if(cur->val == 0){
            n0++;
        }
        if(cur->val == 1){
            n1++;
        }
        cur = cur->next;
    }

    while(fix!=NULL && n0!=0){
        n0--;
        fix->val = 0;
        fix = fix->next;
    }
    while(fix!=NULL && n1!=0){
        n1--;
        fix->val = 1;
        fix = fix->next;
    }

    printLL(a);
}
//Kth Node from Middle
//Even Reverse
int main(){
    Node* a = createLL();
    //Node* b = createLL();

    //printLL(a);
    //a = ReverseList(a);  <! works 
    //printLL(a);

    //cout<<isPalindrome(a);  ?? check
    // a = IntersectList(a,b); ??check 
    // cout<<a->val;

    //sortBinaryList(a);  ?? check 
    // a = getMiddle(a);   <! works
    // cout<<a->val;
    
    printLL(mergeSort(a)); 
    // printLL(a);
    }