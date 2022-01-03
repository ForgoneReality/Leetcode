class Solution {
public:
    int maxArea(vector<int>& height) {
        //Initialize indices
        int l = 1;
        int r = height.size()-1;
        //Initialize best heights
        int lh = height[0];
        int rh = height[r-1];
        //Initialize area
        int area = lh*rh;
        
        for(int i = l+1; i<r; i++) //need change end
        {
            if(height[l]<height[i])//need to check
            {
                int stop_here = (area + height[i] - 1)/(height[i]);
                for (int j = r; j>=i+stop_here; j--)
                {
                    //if height[j] >= height[i], we stop here and take our best area
                    //otherwise, we keep going until the sun sets
                    
                    if (height[l]<height[j])
                    {
                        int b = (j - i)*height[j]
                        if (b > area)
                        {
                            area = b;
                        }
                        if 
                            
                    }
                }
            }
        }
        return area;
        };
    }
};