class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        if(nums.empty()) return{};
        
        for(int i = 1; i <nums.size(); i++)
        {
            if (nums[i]>nums[n])
            {
                nums[n+1] = nums[i];
                n++;
            }
        }
        return n+1;
        
    }
};