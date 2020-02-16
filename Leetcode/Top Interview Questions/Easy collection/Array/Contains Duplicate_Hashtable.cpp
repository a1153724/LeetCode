class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<vector<int>> hash_table;
        hash_table.resize(1000);
        
        for(int i=0; i<nums.size(); i++)
        {
            unsigned int idx = abs(nums[i]%1000);
            std::cout<<nums[i]<<" "<<idx<<endl;
            for(auto value:hash_table[idx])
            {
                if(value==nums[i])
                {
                    return true;
                }
            }
            hash_table[idx].push_back(nums[i]);
        }
        return false;
    }
};