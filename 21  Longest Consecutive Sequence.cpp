class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res = 0;
        int cnt = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] == nums[i-1]+1){
                cnt++;
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                res = max(res,cnt);
                cnt = 1;
            }
        }
        res = max(res,cnt);
        return res;
    }
};