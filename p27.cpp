class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;//index current
        int k = 0;//index supposed-to
        bool changes = false;
        
        //Although less natural, using iterators instead of looping through i and nums.size()
        //dramatically increased speed. 
        for (vector<int>::iterator it = nums.begin(); it!=nums.end(); ++it)
        {
            if (*it == val) //we have an offender!
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