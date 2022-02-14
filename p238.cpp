//check answer! unable to come up with O(1) memory solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> nums2{nums.front()};
        
        for(vector<int>::iterator it = nums.begin()+1; it!= nums.end(); ++it)
        {
            nums2.push_back(nums2.back()*(*it));
        }
        
        int l = nums.size()-1;
        int roller = nums[l];
        nums[l] = nums2[l-1];
        
        l--;
        
        while(l>0)
        {
            int temp = roller;
            roller = roller* nums[l];
            nums[l] = nums2[l-1] * temp;
            l--;
        }
        nums[0] = roller;
        return nums;
        
    }
};