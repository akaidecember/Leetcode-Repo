// Link: https://leetcode.com/problems/relative-ranks/description
// Description
// You are given an integer array
// score
// of size
// n
// , where
// score[i]
// is the score of the
// i
// th
// athlete in a competition. All the scores are guaranteed to be
// unique
// .
// The athletes are
// placed
// based on their scores, where the
// 1
// st
// place athlete has the highest score, the
// 2
// nd
// place athlete has the
// 2
// nd
// highest score, and so on. The placement of each athlete determines their rank:
// The
// 1
// st
// place athlete's rank is
// "Gold Medal"
// .
// The
// 2
// nd
// place athlete's rank is
// "Silver Medal"
// .
// The
// 3
// rd
// place athlete's rank is
// "Bronze Medal"
// .
// For the
// 4
// th
// place to the
// n
// th
// place athlete, their rank is their placement number (i.e., the
// x
// th
// place athlete's rank is
// "x"
// ).
// Return an array
// answer
// of size
// n
// where
// answer[i]
// is the
// rank
// of the
// i
// th
// athlete.
// Example 1:
// Input:
// score = [5,4,3,2,1]
// Output:
// ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
// Explanation:
// The placements are [1
// st
// , 2
// nd
// , 3
// rd
// , 4
// th
// , 5
// th
// ].
// Example 2:
// Input:
// score = [10,3,8,9,4]
// Output:
// ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
// Explanation:
// The placements are [1
// st
// , 5
// th
// , 3
// rd
// , 2
// nd
// , 4
// th
// ].
// Constraints:
// n == score.length
// 1 <= n <= 10
// 4
// 0 <= score[i] <= 10
// 6
// All the values in
// score
// are
// unique
// .

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> v;
        int n = score.size();
        vector<string> ret(n);

        for(int i = 0; i < n; i++){
            v.push_back({score[i], i});
        }

        sort(v.begin(), v.end(), [](const auto& l, const auto& r){
            return l.first > r.first;
        });
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                ret[v[i].second] = "Gold Medal";
            }
            if(i == 1){
                ret[v[i].second] = "Silver Medal";
            }
            if(i == 2){
                ret[v[i].second] = "Bronze Medal";
            }
            if(i > 2){
                ret[v[i].second] = to_string(i+1);
            }
        }
        return ret;
    }
};
