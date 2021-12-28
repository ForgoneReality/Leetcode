class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> me_map;//key, int
        int index = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it, index++) {
            int a = *it;
            if(me_map.count(target - a))
               {
                   vector<int> vect{me_map.at(target-a), index};
                   return vect;
               }
            else
                {   
                    me_map[a] = index;
                }
            
        }
        vector<int> bruh_moment{-1, -1};
        return bruh_moment;

    }
};