class Solution {
public:
    /*static bool my_comparer(vector<int> left, vector<int> right)
    {
        return(left.front()<= right.front());
    }*/ <- this is implicit
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end());
        int prev = (intervals.front()).back();
        for (vector<vector<int>>::iterator it = intervals.begin()+1; it!= intervals.end(); ++it)
        {
            if ((*it).front() < prev)
            {
                return false;
            }
            else
                prev = (*it).back();
        }
        return true;
    }
    
};