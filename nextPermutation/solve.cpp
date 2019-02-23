#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool Exist(vector<int>& source){//是否逆序
    for(int i=1;i<source.size();i++){
        if(source[i]<=source[i-1]){continue;}
        else{return false;}
    }
    return true;
}
bool  Swap(vector<int>& source){//反转
    int len=source.size();
    for(int i=0;i<len/2;i++){
        int temp=source[i];
        source[i]=source[len-1-i];
        source[len-1-i]=temp;
    }
}
void nextPermutation(vector<int>& nums) {
    if(Exist(nums)==true){//是逆序序列，则不存在更大的序列,则交换次序即可
        Swap(nums);
    }
    else{//求下一级
        vector<int> nums_2=nums;
        int times=0;//记录删除了几个数据
        do{
            times++;
            nums_2.erase(nums_2.begin());
        }while(Exist(nums_2)==false);
        sort(nums.begin()+times,nums.end());
        for(int i=times;i<nums.size();i++){
            if(nums[i]>nums[times-1]){
                int temp=nums[times-1];
                nums[times-1]=nums[i];
                nums[i]=temp;
                break;
            }
        }

    }

}
int main(void){
    vector<int> nums={2,3,1};
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ,";
    }
    return 0;
}
