#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;


int mountain(vi arr){
 int largest = INT_MIN;
 int count = 0;
//cout << "anything" ;
for(int i = 1;i<=arr.size()-1;i++){
    if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
        //cout << arr[i] << endl;
    int j = i;
    int k = i;
    while(arr[j] > arr[j-1]){
        //cout << arr[k] << " " << arr[j-1] << " ";
        count++;
        j--;
    }     
    while(arr[k] > arr[k+1]){
        count++;
        k++;
    }  
    }
    if(count>largest){
        largest = count;
        count = 0;
    }
}
return largest;
}
int main(){
vi arr {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
int res = mountain(arr);
cout << res;

}