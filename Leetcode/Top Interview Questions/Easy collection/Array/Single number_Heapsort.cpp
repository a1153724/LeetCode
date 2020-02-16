class Solution {
public:    


    int Left(int i)
    {
        return 2*i;
    };

    int Right(int i)
    {
        return 2*i+1;
    };
    
    int Parent(int i)
    {
        return int(i/2);
    };
    
    int singleNumber(vector<int>& nums) {
        BuildMaxHeap(nums);
        HeapSort(nums);
        for(int i =0; i<nums.size()-1; i = i+2)
        {
        	if (nums[i]!=nums[i+1])
            {
                 return	nums[i];
            }
        }
        return nums[nums.size()-1];
    }

    void Swap(int& x, int& y)
    {
        int z = x;
        x = y;
        y = z;
    }
    void MaxHeapify(std::vector<int> &array, int root, int size)    //須注意Heap從1開始數，但array從0開始，故此處為了計算left和right選擇保留Heap從一開始的特性(不然0的left還是0)，僅在前往array取值時將Index-1
    {
        int largest = root;    
        if(Left(root)<=size)
        {
            if (array[largest-1] < array[Left(root)-1])
            {
                largest = Left(root);
            }
        }
        if ((Right(root)<=size))
        {
            if(array[largest-1] < array[Right(root)-1])
            {
                largest = Right(root);
            }
        }
        if(largest!=root)
        {
            Swap(array[root-1], array[largest-1]);
            MaxHeapify(array, largest,size);
        }
    };
    
    void BuildMaxHeap(std::vector<int> &array)
    {
        int size = array.size();
        for(int i = size; i>0; i--)
        {
            MaxHeapify(array, i, size);
        }
    };

    void HeapSort(std::vector<int> &array)
    {
        int size = array.size();
        for(;size>0;){
            Swap(array[size-1],array[0]);
            size--;
            MaxHeapify(array, 1, size);        
        }
        
    };
};








