class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        if(m.size()==n) return 0;
        for(auto i:m){
            if(i.second>1){
                return i.first;
            }
        }
        return 0;   
    }
};