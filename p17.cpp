class Solution {
public:
    inline static const vector<string> numbers = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.empty())
            return v;
        v.push_back("");
         //initiate vector with empty string
        
        for (char c: digits)//maybe skip null?
        {
            vector<string> next_level;
            
            for(char a: numbers[int(c)-48])//for everything in the current layer
            {//48 is ASCII stuff cuz C++ is cool
                for(auto i: v)
                {
                    next_level.push_back(i+a);
                }
            }
            v.swap(next_level);
        }
        return v;
    }

};