class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
        {
            return 1;
        }
        
        int i = 1;//index current
        int k = 1;//index supposed-to
        bool changes = false;
        
        //Although less natural, using iterators instead of looping through i and nums.size()
        //dramatically increased speed. 
        for (vector<int>::iterator it = nums.begin()+1; it!=nums.end(); ++it)
        {
            if (*it == *(prev(it))) //if current same as previous, in duplication state
            {
                if (!changes)
                    changes = true;
            }
            else //nums[i] > nums[i-1]
            {
                if (changes)
                {
                    nums[k] = nums[i];    
                }
                k++;
            }
            i++;
        }
        return k;
    }
};