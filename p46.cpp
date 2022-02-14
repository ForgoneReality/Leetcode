class Solution {
public:
    void helper(vector<int>&nums, int index, int last)
    {
        if (index >= last)
        {
            ans.push_back(nums);
            return;
        }
        
        helper(nums, index+1, last);
        for(int i = index + 1; i<=last; i++)
        {
            vector<int> copyy = nums;
            int temp = copyy[i];
            copyy[i] = copyy[index];
            copyy[index] = temp;
            helper(copyy, index+1, last);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size(); 
        helper(nums, 1, size - 1);
        if(nums.size()==1)
            return ans;
        for(int i=1; i<size; i++)
        {
            vector<int> copyy = nums;
            int temp = copyy[i];
            copyy[i] = copyy[0];
            copyy[0] = temp;
            helper(copyy, 1, size-1);
        }
        return ans;
    }
    
    private:
    vector<vector<int>> ans;
    
};