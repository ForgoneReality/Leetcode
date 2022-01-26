class Solution {
public:
    // //pass in original vector nums by reference, target number, and the beginning and ending indices of where we want to check.
    // vector<vector<int> helper(vector<int>&nums, int target, int begin, int end)
    // {
    //     unordered_set<int> my_set;
    //     while(begin <= end)
    //     {
    //         begin++;
    //     }
    // }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())
            return empty;
        sort(nums.begin(), nums.end());
        
        //can use binary_search for 0 case... 

        
        vector<int>::iterator last_negative, first_positive;
        last_negative = std::lower_bound(nums.begin(), nums.end(), 0);
        first_positive = std::upper_bound(nums.begin(), nums.end(), 0);
        
        int n = last_negative - nums.begin() - 1;//points to last negative number
        int p =  first_positive - nums.begin(); //points to first positive number

        if(p-n >= 4) //only possible solution (if exists) is triple zeros
        {
            vector<int> triple_zeroes{0,0,0};
            empty.push_back(triple_zeroes);
        }
        
        if (n < 0 || p >= nums.size())//either no positives or no negatives
        {
            return empty;
        }
        
        int left = 0;
        int right = nums.size()-1;
        
        bool has_zero = false;
        if(p-n>1)
        {
            has_zero = true;
            last_negative--;
        }
        
        int previously = INT_MAX;

        while(left<=n && right >= p)
        {
            int x = abs(nums[left]); //dont wanna do (abs) multiple times
            int y= nums[right];

            if(x<y)
            {
                if(previously == y)
                {
                    right--;
                    continue;
                }
                else
                {
                    previously = y;
                }
                int target = - y;
                int prev = INT_MAX;
                unordered_set<int> my_set;

                vector<int>::iterator halfway = lower_bound(nums.begin() + left, last_negative, target/2);
                double really_annoyed = target;
                really_annoyed = really_annoyed/2;
                if( (*halfway)>really_annoyed)
                {
                    --halfway;
                }
                vector<int>::iterator it;
                
                for(it = nums.begin()+left; it<=halfway; ++it)
                {
                    // int temp = *it;
                    // if(temp != prev)//honestly not much of an improvement 99%+ of times, but in case it happens to do insert when set container size full
                    // {
                    //     my_set.insert(temp);
                    //     prev = temp;
                    // }
                    my_set.insert(*it);
                }
                while(it<=last_negative)
                {
                    if((*it) == prev)
                    {
                        it++;
                        continue;
                    }
                    if(my_set.count( target - (*it)))
                    {
                        vector<int> temp{-target, (*it), target-(*it)};
                        empty.push_back(temp);
                        prev = (*it);
                    }
                    it++;
                }
                right--;
            }
            else
            {   
                if(previously == -x)
                {
                    left++;
                    continue;
                }
                else if(x == y && has_zero && previously != -x)
                {
                    vector<int> temp{-x,x,0};
                    empty.push_back(temp); 
                    previously = -x;
                }
                else
                {
                    previously = -x;
                }
                
                //nums[left]>= nums[right]

                //int target = x;
                int prev = INT_MAX;
                unordered_set<int> my_set;

                vector<int>::iterator halfway = upper_bound(first_positive, nums.begin()+right + 1, x/2);
                if (*(halfway - 1) == ((x + 1)/2))
                    halfway--;

                vector<int>::iterator it;
                for(it = nums.begin()+right; it>=halfway; --it)
                {
                    // int temp = *it;
                    // if(temp != prev)//honestly not much of an improvement 99%+ of times, but in case it happens to do insert when set container size full
                    // {
                    //     my_set.insert(temp);
                    //     prev = temp;
                    // }
                    my_set.insert(*it);
                }
                while(it>=first_positive)
                {
                    if((*it) == prev)
                    {
                        it--;
                        continue;
                    }
                    if(my_set.count( x - (*it)))
                    {
                        vector<int> temp{-x, (*it), x-(*it)};
                        empty.push_back(temp);
                        prev = (*it);
                    }
                    it--;
                }
                left++;
            }
            
        }
        
        return empty;
    }
    private:
    vector<vector<int>> empty;
};