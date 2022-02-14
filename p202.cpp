class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mset;
        
        while(n!=1)
        {
            if (mset.count(n))
            {
                return false;
            }
            else
            {
                mset.insert(n);
                int m = 0; //WOW this thing breaks when i dont have = 0. it remembers.
                while(n>0)
                {
                    m += pow((n%10),2);
                    n = n/10;
                }
                n = m;
            }
        }
        return true;
    }
};