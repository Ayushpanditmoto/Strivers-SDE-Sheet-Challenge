void solution(vector<int> &nums,int target){
   int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            cout<<mid;
            return;
        }
        else if(nums[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}