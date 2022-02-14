class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool found = false;
        while(n)
        {
            if(n & 0x1)
            {
                if(found)
                    return false;
                else
                {
                    found = true;
                }
            }
            n = (n >> 1);
        }
        return found;
    }
};