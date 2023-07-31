void solution(vector<int> &nums,int target){
   int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2; // it prevent integer overflow 10^9 + 10^9
        if(nums[mid]==target){
            cout<<mid;
            return;
        }
        else if(target<nums[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}

//2 . Reverse Sorted Array 
// then just change the condition of binary search
// if(nums[mid]==target){
//             cout<<mid;
//             return;
//         }
//         else if(target<nums[mid]){
//             low = mid+1;
//         }
//         else{
//             high = mid-1;
//         }


// 3 Order of the array is not known
// then just change the condition of binary search
//  then check arr[0]<arr[1] or arr[0]>arr[1]
// to check the order of the array



