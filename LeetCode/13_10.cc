// is valid palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        
       int l = 0;
       int r = s.size()-1;
        while(l < r){
           
           if(!isalnum(s[l]))l++;
            else if(!isalnum(s[r]))r--;
            else if(tolower(s[l])!=tolower(s[r]))return false;
            else{
                l++;
                r--;
            }
        }
         return true;
    }
   
};

// 3 sum - checks for duplicates as well
// one more method using hash
class Solution {
public:
    
    vector<vector<int> > vvk;
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return vvk;
        }
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //int i = 0;
        
        for(int i = 0;i<n-1;i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1])continue;
            int l = i+1;
            int r = n-1;
            long int x = nums[i];
           
            while(l<r){
                
                if((x + nums[l] + nums[r])==0) {
                    vector<int>v3;
                    v3.push_back(x);
                    v3.push_back(nums[l]);
                    v3.push_back(nums[r]);
                    vvk.push_back(v3);
                    v3.clear();
                    
                    while( l < r && nums[l] == nums[l+1])l++;
                    while( l <r && nums[r] == nums[r-1])r--;
                    l++;
                    r--;
                   
                }else if((x + nums[l] + nums[r]) < 0){
                    l++;
                }else{
                    r--;
                }
            }
             
        }

        return vvk;
    }
};

// if a straight line
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       int cz = coordinates.size();
        if (cz == 1) return false;  // One point only, not a straight line
        if (cz == 2) return true;  // Two points only, always a straight line
        
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;
        
        for (int i = 1; i < cz; i++) {   // Checking two point formula for each point with the first point
            int x = coordinates[i][0], y = coordinates[i][1];
            if (dx * (y - y0) != dy * (x - x0))  // Two point formula of line, if (x2-x1)*(y1-y0) = (x1-x0)(y2-y1), then a straight line, otherwise not
			    return false;
        }
        return true;
    
    }
};

//Reverse integer
// also checks integer overflows
class Solution {
public:
    int reverse(int x) {
      bool sign = false;
        
        if(x<0){
            sign = true;
            x = abs(x);
        }
         long int rev = 0;
        
        while(x!=0){
           
            rev = rev*10 + (x%10);
            x = x/10;
        }
        if(rev > INT_MAX || rev < INT_MIN){
            return false;
        }
        if(sign){
            return (-1)*rev;
        }
        
        return rev;
    }
};

//Add Binary Number

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while(i >= 0 || j>=0 || carry ){
            if(i>=0 && a[i--] == '1')carry++;
            if(j>=0 && b[j--] == '1')carry++;
            if(carry%2 == 0){
                ans.push_back('0');
            }else{
                ans.push_back('1');
            }
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//Palindrome number

class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0;
        int c = x;
        if(x<0){
        return false;    
        }
        if(x==0){
            return true;
        }
        if(x%10==0){
            return false;
        }
        while(x!=0){
            rev = rev*10 + (x%10);
            x = x/10;
        }
        //cout<<rev<<endl<<x;
        if(rev == c){
            return true;
        }
        return false;
    }
};

