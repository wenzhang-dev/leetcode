/* 递归法：暴力法 */
class Solution {
public:
    /* 递归式f(i)=1+f(i-coins[i]) */
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0) return 0;
        int res = INT_MAX;
        for(int coin : coins)
        {
            if(coin > amount) continue;
            int subRes = coinChange(coins, amount-coin);
            if(subRes == -1) continue;
            res = min(res, subRes+1);
        }
        return res==INT_MAX?-1:res;
    }
};

/* 记忆法 */
class Solution {
public:
    /* 递归式f(i)=1+f(i-coins[i]) */
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> vec(amount+1, -2);
        return helper(coins, vec, amount);
    }

    int helper(vector<int> &coins, vector<int> &v, int amount)
    {
        if(amount == 0) return 0;
        if(v[amount] != -2) return v[amount];

        int res = INT_MAX;
        for(int coin : coins)
        {
            if(coin > amount) continue;
            int subRes = coinChange(coins, amount-coin);
            if(subRes == -1) continue;
            res = min(res, subRes+1);
        }
        v[amount] = res==INT_MAX?-1:res;
        return v[amount];
    }
};

/* 动态规划 */
class Solution {
public:
    /* 递归式f(i)=1+f(i-coins[i]) */
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins)
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};