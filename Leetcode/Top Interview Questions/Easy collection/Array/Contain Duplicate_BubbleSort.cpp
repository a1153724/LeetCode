class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return false;
        int k = 0;          //record the last element that is sorted
        int j;              //the element being compared with the new element to be sorted
        int size = nums.size();
        std::vector<int>::iterator it;
        for(int i =1; i <size; i++)    //sort the array first
        {
            j = k=i-1;
            while(nums[i]<nums[j])
            {
                if (j==0)
                    break;
                else
                    j--;
            }
            if (nums[i]==nums[j])
                return true;

            it = nums.begin()+j+1;
            nums.insert(it,nums[i]);
            nums.erase(nums.begin()+i+1);
        }
        return false;
    }
};