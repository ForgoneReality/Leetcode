class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it;
        for(it = digits.end()-1; it!=digits.begin(); --it)
        {
            int x = *it + 1;
            if (x != 10)
            {
                (*it) = x;
                break;
            }
            else
            {
                *it = 0;
            }
        }
        //now we have to handle beginning
        if(it == digits.begin())
        {
            int x = *it + 1;
            if (x != 10)
            {
                (*it) = x;
            }
            else
            {
                *it = 0;
                digits.insert(it, 1);
            }
        }
        return digits;
    }
};