#include<iostream>
using namespace std;


int main(){
int n;
cin>>n;
bool arr[n][3];
int c = 0;
int p = 0;
for(int i = 0;i<n;i++){
	for(int j = 0;j<3;j++){
		cin>>arr[i][j];
	}
}
// cout<<endl;
// for(int i = 0;i<n;i++){
// 	for(int j = 0;j<3;j++){
// 		cout<<arr[i][j]<<" ";
// 	}
// 	cout<<endl;
// }
for(int i = 0;i<n;i++){
	for(int j = 0;j<3;j++){
		if(arr[i][j]==1){
			c++;
		}
		if(c==2){
			p++;
			c=0;
			break;
		}
	}
}
cout<<p;
}

