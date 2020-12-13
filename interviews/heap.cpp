#include<iostream>
using namespace std;


class Heap {
    vector<int> v;
    int sze;

    int parent(int i) { return i / 2;}
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    void heapify(int i){

        // left child comparison
        int posOfLargest = i;
        if (left(i) <= sze && v[left(i)] > v[i]){
            posOfLargest = left(i);
        }

        if (right(i) <= sze && v[right(i)] > v[posOfLargest]){
            posOfLargest = right(i);
        }

        if (i != posOfLargest){
            // I HAVE to swap
            swap(v[i], v[posOfLargest]);
            heapify(posOfLargest);
        }
    }

public:
    Heap() {
        sze = 0;
        v.push_back(-1);    // empty position
    }

    int top() {
        if (empty()) return -1;
        return v[1];
    }

    bool empty() {
        return sze == 0;
    }

    void pop() {
        if (empty()) return;

        swap(v[1], v[sze]);
        v.pop_back();
        --sze;

        heapify(1);
    }

    void push(int d) {
        // push and compare with the parent
        v.push_back(d);
        ++sze;

        int i = v.size() - 1;
        while(i > 1 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 1; i <= sze; ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
void heapify(int arr[],int n,int i){

int largest = i;
int l = 2*i + 1;
int r = 2*i + 2;

if(l<n && arr[l] > arr[largest]){
    largest = l;
}

if(r<n && arr[r] > arr[largest]){
    largest = r;
}
if(largest != i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
}
}

// Max heap
void kthLargest(int arr[],int n){
    // Build Heap
    for(int i = n/2 - 1;i>=0;i--){
        heapify(arr,n,i);
    }

    while(k!=0){
        // Extract Min/Max k times
        heapify();
    }
}
void heapsort(){
    // Build Heap
    for(int i = n/2 -1;i>=0 ;i--){
        heapify(arr,n,i);
    }
    // Extract one element from heap and move to end;
    // Max Heap - ascending order;
    for(int i = n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        // Call heapify on reduced heap 
        heapify(arr,i,0);
    }
}
int main(){

}