// Link: https://leetcode.com/problems/lexicographical-numbers/description
// Description
// Given an integer
// n
// , return all the numbers in the range
// [1, n]
// sorted in lexicographical order.
// You must write an algorithm that runs in
// O(n)
// time and uses
// O(1)
// extra space.
// Example 1:
// Input:
// n = 13
// Output:
// [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:
// Input:
// n = 2
// Output:
// [1,2]
// Constraints:
// 1 <= n <= 5 * 10
// 4

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int temp = 1;
        for(int i = 0; i < n; i++){
            ret[i] = temp;
            if(temp * 10 > n){
                if(temp == n){
                    temp /= 10;
                }
                temp++;
                while(temp % 10 == 0){
                    temp /= 10;
                }
            }
            else{
                temp *= 10;
            }
        } 
        return ret;
    }
};
