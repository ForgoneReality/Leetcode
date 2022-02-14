class Solution {
public:
    int majorityElement(vector<int> nums) {
        const int median = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + median, nums.end());
        return nums[median];
    }
};
