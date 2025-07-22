// Link: https://leetcode.com/problems/open-the-lock/description
// Description
// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots:
// '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
// . The wheels can rotate freely and wrap around: for example we can turn
// '9'
// to be
// '0'
// , or
// '0'
// to be
// '9'
// . Each move consists of turning one wheel one slot.
// The lock initially starts at
// '0000'
// , a string representing the state of the 4 wheels.
// You are given a list of
// deadends
// dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
// Given a
// target
// representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
// Example 1:
// Input:
// deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output:
// 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
// Example 2:
// Input:
// deadends = ["8888"], target = "0009"
// Output:
// 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
// Example 3:
// Input:
// deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output:
// -1
// Explanation:
// We cannot reach the target without getting stuck.
// Constraints:
// 1 <= deadends.length <= 500
// deadends[i].length == 4
// target.length == 4
// target
// will not be
// in the list
// deadends
// .
// target
// and
// deadends[i]
// consist of digits only.

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool v[10][10][10][10] = {0};
        for(string& d : deadends){
            v[d[0]-48][d[1]-48][d[2]-48][d[3]-48] = true;
        }
        if(v[0][0][0][0]) return -1;
        int ret = 0;
        queue<tuple<int, int, int, int>> q; 
        q.push({0,0,0,0});
        tuple<int, int, int, int> t = {target[0]-48, target[1]-48, target[2]-48, target[3]-48};
        vector<vector<int>> moves = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                if(q.front() == t){
                    return ret;
                }
                auto [d1,d2,d3,d4] = q.front();
                q.pop();
                for(const auto &m : moves){
                    tuple<int, int, int, int> next{(d1 + m[0] + 10) % 10, (d2 + m[1] + 10) % 10, (d3 + m[2] + 10) % 10, (d4 + m[3] + 10) % 10};
                    if(!v[get<0>(next)][get<1>(next)][get<2>(next)][get<3>(next)]){
                        q.push(next);
                        v[get<0>(next)][get<1>(next)][get<2>(next)][get<3>(next)] = true;
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};
