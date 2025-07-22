// Link: https://leetcode.com/problems/daily-temperatures/description
// Description
// Given an array of integers
// temperatures
// represents the daily temperatures, return
// an array
// answer
// such that
// answer[i]
// is the number of days you have to wait after the
// i
// th
// day to get a warmer temperature
// . If there is no future day for which this is possible, keep
// answer[i] == 0
// instead.
// Example 1:
// Input:
// temperatures = [73,74,75,71,69,72,76,73]
// Output:
// [1,1,4,2,1,1,0,0]
// Example 2:
// Input:
// temperatures = [30,40,50,60]
// Output:
// [1,1,1,0]
// Example 3:
// Input:
// temperatures = [30,60,90]
// Output:
// [1,1,0]
// Constraints:
// 1 <= temperatures.length <= 10
// 5
// 30 <= temperatures[i] <= 100

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> stk;
        vector<int> ret(n,0);
        for(int i = 0; i < n; i++){
            while(!stk.empty() && temp[i] > temp[stk.top()]){
                int temp = stk.top();
                stk.pop();
                ret[temp] = i - temp;
            }
            stk.push(i);
        }
        return ret;
    }
};
