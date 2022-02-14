class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> my_table;
        
        for(char c: s)
        {
            if(my_table.count(c))
                my_table[c] += 1;
            else
                my_table[c] = 1;
        }
        
        for(char c: t)
        {
            if(my_table.count(c) && my_table[c]>0)
            {
                my_table[c] -= 1;
            }
            else
                return false;
        }
        return true;
    }
};