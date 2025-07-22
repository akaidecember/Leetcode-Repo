// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description
// Description
// Given an integer array
// nums
// , return
// an integer array
// counts
// where
// counts[i]
// is the number of smaller elements to the right of
// nums[i]
// .
// Example 1:
// Input:
// nums = [5,2,6,1]
// Output:
// [2,1,1,0]
// Explanation:
// To the right of 5 there are
// 2
// smaller elements (2 and 1).
// To the right of 2 there is only
// 1
// smaller element (1).
// To the right of 6 there is
// 1
// smaller element (1).
// To the right of 1 there is
// 0
// smaller element.
// Example 2:
// Input:
// nums = [-1]
// Output:
// [0]
// Example 3:
// Input:
// nums = [-1,-1]
// Output:
// [0,0]
// Constraints:
// 1 <= nums.length <= 10
// 5
// -10
// 4
// <= nums[i] <= 10
// 4

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 0);
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++){
            arr.emplace_back(nums[i], i);
        }

        mergeSortCount(arr, 0, n - 1, ret);
        return ret;
    }

    void mergeSortCount(vector<pair<int, int>>& arr, int left, int right, vector<int>& ret){
        if(left >= right){
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSortCount(arr, left, mid, ret);
        mergeSortCount(arr, mid + 1, right, ret);
        merge(arr, left, mid, right, ret);
    }

    void merge(vector<pair<int, int>> &arr, int left, int mid, int right, vector<int> &ret){
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0, right_count = 0;

        while(i <= mid and j <= right){
            if(arr[i].first <= arr[j].first){
                ret[arr[i].second] += right_count;
                temp[k++] = arr[i++];
            }
            else{
                right_count++;
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            ret[arr[i].second] += right_count;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }
    }
};
