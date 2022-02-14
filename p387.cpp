class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> my_map;
        
        for(char c: s)
        {
            if(!(my_map.count(c)))
            {
                my_map[c] = 0;
            }
            else
                my_map[c] += 1;
        }
        
        for (int i = 0; i<s.length(); i++)
        {
            if (my_map[s[i]] == 0)
                return i;
        }
        return -1;
    }
};