class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums.front();
        unordered_set<int> a;
        
        int ans = 0;
        for(int i: nums)
        {
            if(a.count(i))
                ans-=i;
            else
                ans+=i;
            a.insert(i);
        }
        return ans;
    }
};