class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int	single = 0;
        for(auto value:nums)
            {
                single = single^value;
            }
        return single;
    }
};