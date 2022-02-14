class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        //function pointer?
        int max = 0;
        
        //int last;
        for(int i = 0; i<intervals.size(); i++)
        {
            if(!(pq.empty()))
            {
                int start = intervals[i].front();
                while(pq.top()<=start) 
                {
                    pq.pop();
                    if(pq.empty())
                        break;
                }
            }
            
            pq.push(intervals[i].back());
            if(pq.size()>max)
                max = pq.size();
        }
        return max;
        
    }

};

