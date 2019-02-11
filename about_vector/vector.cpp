 int removeDuplicates(vector<int>& nums) {
       vector<int>::iterator it;
        int i=0;
    int len=nums.size();
        while(i<len-1){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i);
                len=nums.size();
            }
            else i++;
        }
        return nums.size();
    }
