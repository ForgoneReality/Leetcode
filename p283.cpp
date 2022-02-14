class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        while((*it)!=0)
        {
            it++;
            if(it==nums.end())
                return;
        }
        
        vector<int>::iterator mover = it + 1;
        while(mover!= nums.end())
        {
            if((*mover)!=0)
            {
                int temp = *mover;
                *mover = *it;
                *it = temp;
                it++;
            }
            mover++;
        }
        
    }
};