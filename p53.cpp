class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int running_sum = 0;
        
        for(vector<int>::iterator it = nums.begin(); it!= nums.end(); ++it)
        {
            int x = *it;
            running_sum += x; 
            running_sum = max(running_sum, x);
            sum = max(sum, running_sum);
        }
        return sum;
    }
};