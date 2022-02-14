class Solution {
public:
    
    vector<pair<int,int>> initialize(const vector<vector<int>>& rooms)
    {
        vector<pair<int,int>> ans;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        return ans;
    }
    
    void expand(const pair<int,int>& my_thing, vector<vector<int>>& rooms)
    {
        stack<tuple<int,int,int>> my_stack; 
        my_stack.push(make_tuple(my_thing.first, my_thing.second, 1));
    
        
        while(!(my_stack.empty()))
        {
            auto k = my_stack.top();
            int i = get<0>(k);
            int j = get<1>(k);
            int dist = get<2>(k);
            
            
            my_stack.pop();
            if (i>0)
            {
                if(dist<rooms[i-1][j])
                {
                    my_stack.push(make_tuple(i-1, j, dist+1));
                    rooms[i-1][j] = dist;
                }
            }
            if (i<m-1)
            {
                if(dist<rooms[i+1][j])
                {
                    my_stack.push(make_tuple(i+1, j, dist+1));
                    rooms[i+1][j] = dist;
                }
            }
            if (j>0)
            {
                if(dist<rooms[i][j-1])
                {
                    my_stack.push(make_tuple(i, j-1, dist+1));
                    rooms[i][j-1] = dist;
                }
            }
            if (j<n-1)
            {
                if(dist<rooms[i][j+1])
                {
                    my_stack.push(make_tuple(i, j+1, dist+1));
                    rooms[i][j+1] = dist;
                }
            }
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms.front().size();
        
        vector<pair<int,int>> bruhmoment9000 = initialize(rooms);
        
        for(auto i: bruhmoment9000)
        {
            expand(i, rooms);
        }
    }
    
private:
    int m;
    int n;
    const int empty = 2147483647;
};