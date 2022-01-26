class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ans;
        if(nums.front()>0)
            ans = true;
        else if (nums.front()<0)
            ans = false;
        else
            return 0;
            
        for(vector<int>::iterator it = nums.begin()+1; it!= nums.end(); ++it)
        {
            int a = *it;
            if (a==0)
                return 0;
            if (a<0)
                ans = !ans;
        }
        if (ans)
            return 1;
        else
            return -1;
    }
};