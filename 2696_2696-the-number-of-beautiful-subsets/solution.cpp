// Link: https://leetcode.com/problems/the-number-of-beautiful-subsets/description
// Description
// You are given an array
// nums
// of positive integers and a
// positive
// integer
// k
// .
// A subset of
// nums
// is
// beautiful
// if it does not contain two integers with an absolute difference equal to
// k
// .
// Return
// the number of
// non-empty beautiful
// subsets of the array
// nums
// .
// A
// subset
// of
// nums
// is an array that can be obtained by deleting some (possibly none) elements from
// nums
// . Two subsets are different if and only if the chosen indices to delete are different.
// Example 1:
// Input:
// nums = [2,4,6], k = 2
// Output:
// 4
// Explanation:
// The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
// Example 2:
// Input:
// nums = [1], k = 1
// Output:
// 1
// Explanation:
// The beautiful subset of the array nums is [1].
// It can be proved that there is only 1 beautiful subset in the array [1].
// Constraints:
// 1 <= nums.length <= 18
// 1 <= nums[i], k <= 1000

class Solution {
public:
    map<int, int> cache;
    int solver(int n, const map<int, int>& g, int k){
        if (g.find(n) == g.end()) return 1;
        if (cache.find(n) != cache.end()) return cache[n];
        int skip = solver(n + k, g, k);
        int count = (g.find(n) != g.end()) ? g.at(n) : 0;
        int inc = (static_cast<int>(pow(2, count)) - 1) * solver(n + 2 * k, g, k);
        cache[n] = skip + inc;
        return skip + inc;
    }

    int beautifulSubsets(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        for (const auto& n : nums) mp[n]++;
        vector<map<int, int>> groups;
        set<int> visited;
        for (auto& [key, count] : mp){
            if (visited.find(key) != visited.end()) continue;
            map<int, int> temp;
            int start = key;
            while (mp.find(start - k) != mp.end()) start -= k;
            for (int i = start; mp.find(i) != mp.end(); i += k){
                temp[i] = mp[i];
                visited.insert(i);
            }
            groups.push_back(temp);
        }
        int ret = 1;
        for (const auto& g : groups){
            cache.clear();
            int n = g.begin()->first;
            ret *= solver(n, g, k);
        }
        return ret - 1;
    }
};
