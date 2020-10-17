class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsum = nums[0];
        for(int i = 1;i<nums.size();i++){
            sum = max(nums[i],sum+nums[i]);
            if(sum>maxsum){
                maxsum = sum;
            }
        }
        return maxsum;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), i = 0, j = 1;
    
		if(size == 0)
			return 0;  //Exclude edge case
    
		for(j = 1; j<size; j++)
		{
		
			if(nums[i]!=nums[j])
			{
				i+=1;
				nums[i] = nums[j];
			}
		}
    
		return i+1;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int> m;
        
        for(int i = 0;i<nums.size();i++){
            int k = target - nums[i];
            if(m.find(k)!=m.end()){
            ans.push_back(m[k]);
            ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
            }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            ans.push_back(sum+=nums[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> form;
        
        for(int i = 0;i<n;i++){
            form.push_back(start + 2*i);
        }
        for(auto x : form){
            cout<<x << " ";
        }
        int a = 0;
        for(int i = 0;i<n;i++){
            a = a xor form[i];
        }
        
        return a;
    }
};