class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        for(int i=0; i<k-1; ++i) pq.pop();

        return pq.top();
    }
};

/* 优化:12ms */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        ::sort(nums.begin(), nums.end(), std::greater<int>());/* 从大到小排序 */
        return nums[k-1];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
		auto comp = [](int a, int b){ return a>b; };
        ::sort(nums.begin(), nums.end(), comp);/* 从大到小排序 */
        return nums[k-1];
    }
};

