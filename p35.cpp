class Solution {
public:
    int helper(vector<int> &nums, int target, int left, int right)
    {
        if (right<left)
        {
            return left-1;
        }
        
        int pivot_index = (right+left)/2;
        int pivot = nums[pivot_index];
        
        if (pivot == target)
        {
            return pivot_index;
        }
        else if (pivot < target)
        {
            if (right == left)
            {
                return left+1;
            }
            return helper(nums, target, pivot_index+1, right);
        }
        else
        {
            if (left == right || left == pivot_index)
                return left;
            return helper(nums, target, left, pivot_index-1);
        }
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size()-1;
        
        if (right == -1)
            return 0;
        int left = 0;
        
        int pivot_index = right/2;
        int pivot = nums[pivot_index];
        
        if (pivot == target)
        {
            return pivot_index;
        }
        else if (pivot < target)
        {
            if (right == left)
            {
                return left+1;
            }
            return helper(nums, target, pivot_index+1, right);
        }
        else
        {
            if (left == right || left == pivot_index)
            {
                return left;
            }
            return helper(nums, target, left, pivot_index-1);
        }
        
    }
};