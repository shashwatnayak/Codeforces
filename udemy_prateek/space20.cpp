#include<iostream>
#include<vector>

using namespace std;

void replace(char *str){
// Calculate spaces
int spaces = 0;
for(int i=0;str[i]!='\0';i++){
    if(str[i]== ' '){
    spaces++;
    }
}
// Shift the string right/modify to accomodate the characaters in single pass
int idx = strlen(str) + 2*spaces;
str[idx] = '\0';
for(int i=strlen(str)-1;i>=0;i--){
    if(str[i]==' '){
        str[i-1] = '0';
        str[i-2] = '2';
        str[i-3] = '%';
    }else{
        str[i-1] = str[i];
    }
}
}
int main(){
char input[10000];
getline(cin,input);
replace(input);
cout << input;
return 0;    
}