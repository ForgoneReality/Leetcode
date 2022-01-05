class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> me_map;
        int begin = 0;
        int best = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            if (me_map.count(a)) //found previous
            {
                if(me_map[a] >= begin)
                {
                    best = max(best, i-begin);
                    begin = me_map[a] + 1;
                }
                else
                {
                    best = max(best, i-begin +1);
                }
            }
            me_map[a] = i;
        }
        if(s.length() - begin > best)
        {
            int temp = s.length() - begin;
            return temp;
        }
        else
            return best;
    }
};