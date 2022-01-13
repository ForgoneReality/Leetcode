class Solution {
public:
    Solution()
    {
        maybe = INT_MAX;
    }
    
    double curse(vector<int>& n1, vector<int>& n2, int start1, int start2, int size1, int size2, int bigger_than)
    {
        // if (n1.empty()) //should never get here besides when given initially!
        // {
        //     cerr << "Scenario 0..." << endl;
        //     //not completely impossible?? tbh i think it is.
        //     return -1;
        // }

        if (size2 > bigger_than + 1)
        {
            size2 = bigger_than + 1;
            maybe = min(maybe, n2[bigger_than + 1]);
        }

        if (bigger_than == 0)
        {
            if (n1[start1] <= n2[start2])
            {
                maybe = min(n2[start2], maybe);
                return n1[start1];
            }
            else
            {
                maybe = min(n1[start1], maybe);
                return n2[start2];
            }
        }
        else if (size1 == 1)
        {
            if (size2 == 1)
            {
                // if (bigger_than == 1)
                // {
                //     cout << "Scenario 1 - UNEXPECTED" << endl;
                //     return max(n1[start1], n2[start2]);
                // }
                // else //>1
                // {
                //     cerr << "Scenario 2 : " << bigger_than << endl;
                //     return -1;
                // }
            }
            else
            {
                if (n1[start1] <= n2[start2 + bigger_than - 1])
                {
                    maybe = min(n2[start2 + bigger_than], maybe);
                    return n2[start2 + bigger_than - 1];
                }
                else
                {
                    return(curse(n1, n2, start1, start2 + bigger_than, 1, size2-bigger_than, 0));
                }
            }
        }
        int temp = ((size1 - 1) / 2);
        int index_a = start1 + temp;
        int a = n1[index_a];
        int index_b = start2 + bigger_than - 1 - temp;
        int b = n2[index_b];

        if (a <= b)
        {
            //size swapping optimizations!
            int new_size_a = start1 + size1 - index_a - 1;
            int new_size_b = index_b - start2 + 1;
            maybe = min(maybe, n2[index_b + 1]);

            if (new_size_a <= new_size_b)
                return(curse(n1, n2, index_a + 1, start2, new_size_a, new_size_b, (bigger_than - temp - 1)));
            else
                return(curse(n2, n1, start2, index_a + 1, new_size_b, new_size_a, (bigger_than - temp - 1)));
            //OPTIMIZE START2 AND SIZE!
        }
        else //a > b
        {
            int new_size_a = index_a - start1 + 1;
            int new_size_b = start2 + size2 - (index_b)-1;

            maybe = min(maybe, n1[index_a + 1]);

            if (new_size_a <= new_size_b)
                return(curse(n1, n2, start1, index_b + 1, new_size_a, new_size_b, (bigger_than - index_b + start2 - 1)));
            else
                return(curse(n2, n1, index_b + 1, start1, new_size_b, new_size_a, (bigger_than - index_b + start2 - 1)));
        }

    }
    
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    bool odd = ((nums2.size() + nums1.size()) % 2);
    if (nums1.empty())
    {
        if (odd)
        {
            return nums2[(nums2.size() - 1) / 2];
        }
        else
        {
            return(double(nums2[(nums2.size() - 1) / 2] + nums2[nums2.size() / 2])/2);
        }
    }
    if (nums2.empty()) //should never get here besides when given initially!
    {
        if (odd)
        {
            return nums1[(nums1.size() - 1) / 2];
        }
        else
        {
            return((double(nums1[nums1.size() / 2] + nums1[(nums1.size() - 1) / 2]))/2);
        }
    }
    double left;
    if (nums2.size() > nums1.size())
    {
        left = (curse(nums1, nums2, 0, 0, nums1.size(), nums2.size(), ((nums1.size() + nums2.size() - 1) / 2)));
    }
    else
    {
        left = (curse(nums2, nums1, 0, 0, nums2.size(), nums1.size(), ((nums1.size() + nums2.size() - 1) / 2)));
    }
    if (odd)
    {
        return left;
    }
    else
    {
        // cout << "left: " << left << endl;
        // cout << "right: " << maybe << endl;
        return (double(left + maybe) / 2);
    }
}
    
private:
    int maybe;
};