class Solution {
public:
    
        int getpivot(vector<int>& nums){
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int mid = s + (e - s) / 2;

            if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }

    int bs(vector<int>& nums, int target, int s, int e){
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;   // ✅ FIXED
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target){
        int pivot = getpivot(nums);
        int n = nums.size();

        if(target >= nums[pivot] && target <= nums[n - 1]){
            return bs(nums, target, pivot, n - 1);
        }
        else{
            return bs(nums, target, 0, pivot - 1);
        }
    }
        
    
};
