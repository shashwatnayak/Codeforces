#include<iostream>
#include<string>
using namespace std;

#define MAX 1000
// Not tested
class TrieNode{
    public:
        TrieNode *child[26];
        bool is_end;
    TrieNode(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
        is_end = false;
    }
};

void insert(TrieNode *root, string key){
TrieNode *tmp = root;
for(int i = 0;i<key.size();i++){
    int idx = key[i] - 'a';
    if(!tmp->child[idx]){
        tmp->child[i] = new TrieNode();
    }
    tmp = tmp->child[idx];
}
tmp->is_end = true;
}
bool search(TrieNode *root,string key){
 TrieNode *tmp = root;
for(int i = 0;i<key.size();i++){
    int idx = key[i] - 'a';
    if(!tmp->child[idx]){
        return false;
    }
    tmp = tmp->child[idx];
}
return (tmp !=NULL && tmp->is_end);
}

bool wordBreak(TrieNode* root,string s){
    if(s.size() == 0){
        return true;
    }

    for(int i = 0;i<=s.size();i++){
        string word = s.substr(0,i);
        string suffix = s.substr(i,s.size()-i);
        if(search(root,word) && wordBreak(root,suffix)){
            return true;
        }
    }
    return false;
}

class PrefixTrie{
public:
        PrefixTrie *child[26];
        int freq;
    PrefixTrie(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
        freq = 1;
    }
};

void PrefixInsert(PrefixTrie *root, string key){
PrefixTrie *tmp = root;
for(int i = 0;i<key.size();i++){
    int idx = key[i] - 'a';
    if(!tmp->child[idx]){
        tmp->child[i] = new PrefixTrie();
    }else{
        tmp->child[i]->freq++;
    }
    tmp = tmp->child[idx];
}
}

void search_prefix(PrefixTrie* root,char prefix[],int idx){
if(root==NULL){
    return;
}

if(root->freq == 1){
    prefix[idx] = '\0';
    cout << prefix << " ";
    return;
}
for(int i = 0;i<MAX;i++){
    if(root->child[i]!=NULL){
        prefix[idx] = i;
        search_prefix(root->child[i],prefix,i+1);
    }
}
}
void find_Prefix(string ar[],int n){
PrefixTrie *root = new PrefixTrie();
for(int i = 0;i<n;i++){
    PrefixInsert(root,ar[i]);
}
char prefix[MAX];
search_prefix(root,prefix,0);
}
int main(){
// string keys[] = {"the", "a", "there", 
//                     "answer", "any", "by", 
//                      "bye", "their" }; 
// int n = sizeof(keys)/sizeof(keys[0]); 

// TrieNode * root = new TrieNode();

// for(int i = 0;i<n;i++){
//     insert(root,keys[i]);
// }

// cout << search(root,"any");
// cout << "\n";
// cout<< search(root,"their");

/* For Word Break*/
TrieNode *root = new TrieNode();
string dict[] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"};
int size = sizeof(dict)/sizeof(dict[0]);

for(int i = 0;i<size;i++){
    insert(root,dict[i]);
}
//cout << wordBreak();
return 0;
}