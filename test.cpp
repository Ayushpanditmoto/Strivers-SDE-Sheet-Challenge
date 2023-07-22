//  You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

// base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

// Return true if the given array is good, otherwise return false.

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int max_ele = max_element(n);

              
    }
    int max_element(int n){
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,nums[i]);
        }
        return ans;
    }
   
};