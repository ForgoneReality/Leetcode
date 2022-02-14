class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        vector<int>* left = &intervals[0];//maybe no &
        vector<vector<int>>::iterator right = intervals.begin()+1;
        
        vector<int> temp;
        while(right!= intervals.end())
        {
            if (left->back()>=(*right).front())//need combination!
            {
                vector<int> temp2{left->front(), max((*right).back(), left->back())};
                temp.swap(temp2);
                left = &temp;
                right++;
            }
            else
            {
                ans.push_back(*left);
                left = &(*right);
                right++;
            }
        }
        ans.push_back(*left);
        
        // if (left != &ans.back())//last thing we did was combine
        // {
        //     ans.push_back(*left);
        // }
        return ans;
    }
};