class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        
        //initialize variables
        int best = 0; 
        int smallest = prices.front();
        
        for(vector<int>::iterator it = prices.begin()+1; it!= prices.end(); ++it)
        {
            if ((*it)>smallest)
            {
                best = max(best, (*it)- smallest);
            }
            else if ((*it)<smallest)
            {
                smallest = *it;
            }
        }
        return best;
        
    }
};