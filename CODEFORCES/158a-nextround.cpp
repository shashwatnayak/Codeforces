#include<iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];

	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	// for(int i = 0;i<n;i++){
	// 	cout<<arr[i];
	// }
	int score = arr[k-1];
	int count = 0;
	for(int j = 0;j<n;j++){
		if(arr[j]>=score && (score!=0 || arr[j]!=0)){
			count++;
		}else if(arr[j]<score){
			break;
		}
	}
	cout<<count;
	return 0;
}