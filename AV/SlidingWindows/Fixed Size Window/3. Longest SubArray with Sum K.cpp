//3. Longest SubArray with Sum K 
// Sliding window solution

class Solution {
public:
    int lenOfLongSubarr(vector<int> array, int k) {
        int n = array.size();
        int i=0,j=0;
        int sum = 0;
        int ans = INT_MIN;
        while(j<n){
            sum += array[j];
            if(sum < k){
                j++;
            }
            else if(sum == k){
                ans = max(ans,j-i+1);
                j++;
            }
            else if(sum > k){
                while(sum > k){
                    sum -= array[i];
                    i++;
                }
                if(sum == k){
                    ans = max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};