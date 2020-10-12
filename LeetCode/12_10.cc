
// TLE on iterative, need better solution
class Solution {
public:
    
    string prints(string s,int l,int r){
    string p;
        int i = 0;
    while(l<r){
        p.push_back(s[l]);
        l++;
    
    }
   
        return p;
}
    string longestPalindrome(string s) {
        int sz = s.size();
        
        if(sz == 0 || sz == 1){
            return s;
        }
        if(sz == 2 && s[0]!=s[1]){
            string q ;
            q.push_back(s[0]);
            return q;
        }
        bool flag;
        int mx = 1;
        int st = 0;
        int en = 0;
        for(int i = 0; i<sz; i++){
            for(int j = i; j<sz; j++){
                flag = true;
                
                for(int k = 0;k < (j-i+1)/2; k++){
                    if(s[i+k]!=s[j-k]){
                        flag = false;
                    }
                }
                
                if(flag && (j-i+1) >= mx){
                    st = i;
                    mx = j-i+1;
                    en = i + mx;
                }
            }
        }
        cout<<st << " " <<en;
        string p = prints(s,st,en);
        return p;
    }
};

// Valid Paranthesis

class Solution {
public:
    bool isValid(string s) {
       
        stack<char> st;
        for(auto i:s){
            if(i=='(' or i == '{' or i == '['){
                st.push(i);
            }else{
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        } 
       return st.empty();
    }
};

// Count and Say

class Solution {
public:
    string countAndSay(int n) {
           if(n==1) return "1"; // base case
        string res,tmp = countAndSay(n-1); // recursion
        char c= tmp[0];
        int count=1;
        for(int i=1;i<tmp.size();i++)
            if(tmp[i]==c)
                count++;
            else {
                res+=to_string(count);
                res.push_back(c);
                c=tmp[i];
                count=1;
            }
        res+=to_string(count);
        res.push_back(c);
        return res;
    }
};

