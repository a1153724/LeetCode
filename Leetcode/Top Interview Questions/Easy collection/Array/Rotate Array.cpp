class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;
        int taken = (size-k)%size;
        int location;
        int temp1 = nums[taken];                   //for taken的值
        int temp2;                                   //for location的值
        location = (taken + k)%size;
        int flag = 0;                                   //為了判斷是否是同一小批的球在做交換，而不是所有的球都在交換，紀錄第一顆砸向的位置(因為第一顆球會被複製)，如果下次又準備砸向同一個地方，則捨棄手上那一顆(複製過所以共兩顆，故直接丟掉沒問題)，改舉起下一顆
        for (int done = 0; done<size; done++)
        {
            temp2 = nums[location];
            nums[location] = temp1;
            temp1 = temp2;
            taken = location;
            location = (taken + k)%size;
            if (location == flag)
            {
                taken = (taken + 1)%size ;
                temp1 = nums[taken];
                location = (taken + k)%size;
                flag = location;
            }
        }
    }
};