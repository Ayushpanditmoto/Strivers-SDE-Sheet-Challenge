class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        int n = nums.size();
        int index = -1;

        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index = i-1;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int j = n-1;
            while(j>=index && nums[j]<=nums[index]){
                j--;
            }
            swap(nums[index],nums[j]);
            reverse(nums.begin()+index+1,nums.end());
        }

    }
};