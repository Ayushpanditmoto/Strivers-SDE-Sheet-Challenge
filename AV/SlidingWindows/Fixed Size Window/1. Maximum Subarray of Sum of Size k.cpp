//sliding window
//https://leetcode.com/problems/maximum-subarray-of-size-k/

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int ans = sum;
        for(int i=k;i<n;i++){
            sum += nums[i] - nums[i-k];
            ans = max(ans,sum);
        }
        return ans;
    }
    //sliding widdow function
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int i=0,j=0;
        int ans = INT_MIN;
        while(j<n){
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans = max(ans,sum);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};