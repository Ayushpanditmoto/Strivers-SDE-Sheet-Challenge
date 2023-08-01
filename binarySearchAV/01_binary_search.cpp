// If Sorted Array then use Binay Search

int binarySearch(vector<int> &nums,int left,int right, int target){
    // int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1; 
    }
    return -1; 
}

//2 . Reverse Sorted Array 
// then just change the condition of binary search
if(nums[mid]==target) return mid;
else if(nums[mid]<target) right = mid - 1;
else left = mid + 1;

// 3 Order of the array is not known
// then just change the condition of binary search
//  then check arr[0]<arr[1] or arr[0]>arr[1]
// to check the order of the array

//4. If Duplicate elements are present in the array
//1st occurance and Last occurance of the element Find

int firstOccurance(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            if(mid == 0 || nums[mid - 1] != target) return mid;
            else right = mid - 1;
        }
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1; 
    }
    return -1; 
}

int endOccurance(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            if(mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
            else left = mid + 1;
        }
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1; 
    }
    return -1; 
}


//5. Count The element in a sorted array

int countElement(vector<int> &nums, int target){
    int first = firstOccurance(nums, target);
    int last = endOccurance(nums, target);
    if(first == -1 || last == -1) return 0;
    return last - first + 1;
}

//6 . Number of times a sorted array is rotated
// Find the index of the minimum element
// both of the neighbours se smaller hai

int findMin(vector<int> &nums){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) return mid;
        else if(nums[mid] < nums[right]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

//7. Find the element in a rotated sorted array
// Find the index of the minimum element

int search(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int minIndex = findMin(nums);
    int ans = binarySearch(nums, left, minIndex - 1, target);
    if(ans != -1) return ans;
    return binarySearch(nums, minIndex, right, target);
}



//8. Searching in a nearly sorted array
// 1 2 3 4 5 6 7 8 9
// 2 1 3 4 5 6 7 8 9
// 2 3 1 4 5 6 7 8 9

int search(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(mid - 1 >= left && nums[mid - 1] == target) return mid - 1;
        else if(mid + 1 <= right && nums[mid + 1] == target) return mid + 1;
        else if(nums[mid] < target) left = mid + 2;
        else right = mid - 2;
    }
    return -1;
}
