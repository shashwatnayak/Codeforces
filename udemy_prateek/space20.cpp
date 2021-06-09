#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void replace(char *str){
// Calculate spaces
int spaces = 0;
for(int i=0;str[i]!='\0';i++){
    if(str[i]== ' '){
    spaces++;
    }
}
//cout << spaces << endl;
// Shift the string right/modify to accomodate the characaters in single pass
int idx = strlen(str) + 2*spaces;
//cout<<idx << endl;
str[idx] = '\0';
for(int i=strlen(str)-1;i>=0;i--){
    if(str[i]==' '){
        str[idx-1] = '0';
        str[idx-2] = '2';
        str[idx-3] = '%';
        idx = idx-3;
    }else{
        str[idx-1] = str[i];
        idx = idx - 1;
    }
}
}
int main(){
char input[10000];
cin.getline(input,1000);
//cout<<input<< endl;
replace(input);
cout << input << endl;
return 0;    
}