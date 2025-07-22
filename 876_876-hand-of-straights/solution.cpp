// Link: https://leetcode.com/problems/hand-of-straights/description
// Description
// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size
// groupSize
// , and consists of
// groupSize
// consecutive cards.
// Given an integer array
// hand
// where
// hand[i]
// is the value written on the
// i
// th
// card and an integer
// groupSize
// , return
// true
// if she can rearrange the cards, or
// false
// otherwise.
// Example 1:
// Input:
// hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output:
// true
// Explanation:
// Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:
// Input:
// hand = [1,2,3,4,5], groupSize = 4
// Output:
// false
// Explanation:
// Alice's hand can not be rearranged into groups of 4.
// Constraints:
// 1 <= hand.length <= 10
// 4
// 0 <= hand[i] <= 10
// 9
// 1 <= groupSize <= hand.length
// Note:
// This question is the same as 1296:
// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        map<int,int> mp;
        if(hand.size() % gs != 0) return false;
        for(const auto& h : hand) mp[h]++;
        for(const auto& [f,_] : mp){
            if(mp[f] > 0){
                int temp = mp[f];
                for(int i = 0; i < gs; i++){
                    if(mp[f+i] < temp) return false;
                    mp[f+i] -= temp;
                }
            }
        }
        return true;
    }
};
