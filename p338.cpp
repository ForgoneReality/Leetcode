class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        ans.push_back(0);
        
        if(n==0)
            return ans;
        
        ans.push_back(1);
        if(n==1)
            return ans;
        
        ans.push_back(1);
        if(n==2)//this one can be included in the next loop, but probably faster out
            return ans;
        
        int curr = 2;
        int target = 4;
        int i = 3;
        while(i<=n)
        {
            if(i==target)
            {
                ans.push_back(1);
                curr = target;
                target = target*2;
            }
            else
                ans.push_back(ans[i-curr]+1);
            
            i++;
        }
        return ans;
    }
};