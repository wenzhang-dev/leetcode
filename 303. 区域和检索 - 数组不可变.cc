class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums)
    {
        vector<int> subRes(nums.size());
        int sum = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            subRes[i] = sum;
        }
        dp = std::move(subRes);
    }
    
    int sumRange(int i, int j) 
    { 
        if(i==0) return dp[j];
        return dp[j]-dp[i-1];	//sumRange(i,j)=sumRange(0, j)-sumRange(0, i-1)
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
 
/* 暴力法 */
 class NumArray {
    vector<int> &nums_;
public:
    NumArray(vector<int>& nums) : nums_(nums){}
    
    int sumRange(int i, int j) 
    {
        int sum = 0;
        for(int k=i; k<=j; ++k) sum += nums_[k];
        return sum;    
    }
};