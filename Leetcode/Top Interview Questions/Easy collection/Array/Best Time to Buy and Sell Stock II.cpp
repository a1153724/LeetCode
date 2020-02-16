class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mod;
        int profit = 0;
        for(int i = 1;i<prices.size(); i++)
        {
            mod.insert(mod.end(),prices[i]-prices[i-1]);
        }
        for(int i = 0; i<mod.size(); i++)
        {
            if (mod[i]>0) 
                profit = profit + mod[i];
        }
        return profit;
    }
};