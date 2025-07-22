// Link: https://leetcode.com/problems/maximum-subsequence-score/description
// Description
// You are given two
// 0-indexed
// integer arrays
// nums1
// and
// nums2
// of equal length
// n
// and a positive integer
// k
// . You must choose a
// subsequence
// of indices from
// nums1
// of length
// k
// .
// For chosen indices
// i
// 0
// ,
// i
// 1
// , ...,
// i
// k - 1
// , your
// score
// is defined as:
// The sum of the selected elements from
// nums1
// multiplied with the
// minimum
// of the selected elements from
// nums2
// .
// It can defined simply as:
// (nums1[i
// 0
// ] + nums1[i
// 1
// ] +...+ nums1[i
// k - 1
// ]) * min(nums2[i
// 0
// ] , nums2[i
// 1
// ], ... ,nums2[i
// k - 1
// ])
// .
// Return
// the
// maximum
// possible score.
// A
// subsequence
// of indices of an array is a set that can be derived from the set
// {0, 1, ..., n-1}
// by deleting some or no elements.
// Example 1:
// Input:
// nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
// Output:
// 12
// Explanation:
// The four possible subsequence scores are:
// - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
// - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
// - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
// - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
// Therefore, we return the max score, which is 12.
// Example 2:
// Input:
// nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
// Output:
// 30
// Explanation:
// Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
// Constraints:
// n == nums1.length == nums2.length
// 1 <= n <= 10
// 5
// 0 <= nums1[i], nums2[j] <= 10
// 5
// 1 <= k <= n

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            pairs.push_back({nums1[i], nums2[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum1 = 0, ret = 0;
        for(const auto& p : pairs){
            sum1 += p.first;
            minHeap.push(p.first);
            if(minHeap.size() > k){
                sum1 -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == k){
                ret = max(ret, sum1 * p.second);
            }
        }
        return ret;
    }
};
