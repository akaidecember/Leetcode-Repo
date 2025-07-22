// Link: https://leetcode.com/problems/minimum-area-rectangle/description
// Description
// You are given an array of points in the
// X-Y
// plane
// points
// where
// points[i] = [x
// i
// , y
// i
// ]
// .
// Return
// the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes
// . If there is not any such rectangle, return
// 0
// .
// Example 1:
// Input:
// points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
// Output:
// 4
// Example 2:
// Input:
// points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// Output:
// 2
// Constraints:
// 1 <= points.length <= 500
// points[i].length == 2
// 0 <= x
// i
// , y
// i
// <= 4 * 10
// 4
// All the given points are
// unique
// .

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> st;
        int ret = INT_MAX, n = points.size();

        for(const auto& p : points){
            st.insert(static_cast<long long>(p[0] * 40001 + p[1]));
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if(x1 != x2 and y1 != y2){
                    if(st.count(static_cast<long long>(x1) * 40001 + y2) and st.count(static_cast<long long>(x2) * 40001 + y1)) {
                        ret = min(ret, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
        return (ret == INT_MAX) ? 0 : ret;
    }
};
