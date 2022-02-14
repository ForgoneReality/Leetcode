class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> first{1};
        vector<vector<int>> answer;
        answer.push_back(first);
        if(numRows==1)
        {
            return answer;
        }
            
        for (int i = 1; i<numRows; i++)   
        {
            vector<int> next{1};
            vector<int>& last = answer.back();
            for(int j = 1; j<i; j++)
            {
                next.push_back(last[j-1] + last[j]);
            }
            next.push_back(1);
            answer.push_back(next);
        }
        return answer;
    }
};