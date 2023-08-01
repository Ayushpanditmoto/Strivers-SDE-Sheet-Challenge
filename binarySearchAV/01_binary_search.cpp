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

//9 Find Floor of an element in a sorted array
// Floor of an element is the greatest element smaller than or equal to the target element

int findFloor(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int ans = -1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}

//10 Find Ceil of an element in a sorted array
// Ceil of an element is the smallest element greater than or equal to the target element

int findCeil(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    int ans = -1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

// 11. Next Alphabetical Element

char nextAlphabet(vector<char> &nums, char target){
    int left = 0, right = nums.size() - 1;
    char ans = '#';
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            ans = nums[mid];
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

// 12 . Find the position of an element in an infinite sorted array

int findPos(vector<int> &nums, int target){
    int left = 0, right = 1;
    while(nums[right] < target){
        left = right;
        right = right * 2;
    }
    return binarySearch(nums, left, right, target);
}

//13 . Find the index of 1st 1 in a binary sorted infinite array
// ex 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1

int findPosOf1(int a[], int key)
{
// Infinity Sorted Code
    int low = 0, high = 1;
    while (a[high] < key)
    {
        low = high;
        high = 2 * high;
    }

//   First Occurance Code
    int res=-1;
    while (low <= high){
        int mid = (low + high) >>1;
        if (a[mid] > key) high = mid - 1;
        else if (a[mid] < key) low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

//14. Minimum Difference Element in a Sorted Array

int minDiffElement(vector<int>& arr,int key){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return arr[mid];
        else if(arr[mid]>key) high=mid-1;
        else low=mid+1;
    }
    return (abs(arr[low]-key)<abs(arr[high]-key))?arr[low]:arr[high];
}

// 15. Find Peak Element 

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1,mid=0;
        if(n==1) return 0;
        while(s<=e){
            mid = s+(e-s)/2;
            if(mid>0&&mid<n-1){
                if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(nums[mid]>nums[mid-1])
                    s=mid+1;
                else
                    e = mid-1;
            }
            else if(mid==0){
                if(nums[mid]>nums[(mid+1)]) return mid;
                else return mid+1;
            }
            else if(mid==n-1){
                if(nums[mid]>nums[(mid-1)]) return mid;
                else return mid-1;
            }
        }
        return -1;
    }


// 16. Find the peak element in a bitonic array
// Bitonic Array is an array which is strictly increasing and then strictly decreasing

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1,mid=0;
        if(n==1) return 0;
        while(s<=e){
            mid = s+(e-s)/2;
            if(mid>0&&mid<n-1){
                if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(nums[mid]>nums[mid-1])
                    s=mid+1;
                else
                    e = mid-1;
            }
            else if(mid==0){
                if(nums[mid]>nums[(mid+1)]) return mid;
                else return mid+1;
            }
            else if(mid==n-1){
                if(nums[mid]>nums[(mid-1)]) return mid;
                else return mid-1;
            }
        }
        return -1;
    }

    // 17. Search an element in a bitonic array
    // Bitonic Array is an array which is strictly increasing and then strictly decreasing

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0,e=n-1,mid=0;
        if(n==1) return nums[0]==target?0:-1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(mid>0&&mid<n-1){
                if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                    if(nums[mid]>target) e=mid-1;
                    else s=mid+1;
                }
                else if(nums[mid]>nums[mid-1])
                    s=mid+1;
                else
                    e = mid-1;
            }
            else if(mid==0){
                if(nums[mid]>nums[(mid+1)]) return nums[mid]==target?mid:-1;
                else return nums[mid+1]==target?mid+1:-1;
            }
            else if(mid==n-1){
                if(nums[mid]>nums[(mid-1)]) return nums[mid]==target?mid:-1;
                else return nums[mid-1]==target?mid-1:-1;
            }
        }
        return -1;
    }

 //18. Search in a row wise and column wise sorted matrix

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int i=0,j=m-1;
            while(i<n&&j>=0){
                if(matrix[i][j]==target) return true;
                else if(matrix[i][j]>target) j--;
                else i++;
            }
            return false;
        }

// 19 . Allocate minimum number of pages

bool isPossible(int arr[],int n,int m,int curr_min){
    int studentsRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    long long sum = 0;
    if(n<m) return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = 0, end = sum;
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return result;
}
    
