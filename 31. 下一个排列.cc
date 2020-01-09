class Solution {
public:
    /* 从后向前找第一个nums[i+1] <= nums[i]的元素 */
    /* 在nums[i]->nums.end()有序序列中找第一个大于nums[i]的元素 */
    /* 逆序nums[i+1] -> nums.end()序列 */
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-2;
        while(i>=0 && nums[i+1] <= nums[i]) --i;
        if(i >= 0)
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};

/* 手动reverse函数 */
class Solution {
    void reverse(vector<int> &nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums[start], nums[end]);
            ++start; --end;
        }
    }

public:
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-2;
        while(i>=0 && nums[i+1] <= nums[i]) --i;
        if(i >= 0)
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i+1, nums.size()-1);
    }
};

