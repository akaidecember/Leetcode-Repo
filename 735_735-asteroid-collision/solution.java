// Link: https://leetcode.com/problems/asteroid-collision/description
// Description
// We are given an array
// asteroids
// of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
// Example 1:
// Input:
// asteroids = [5,10,-5]
// Output:
// [5,10]
// Explanation:
// The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:
// Input:
// asteroids = [8,-8]
// Output:
// []
// Explanation:
// The 8 and -8 collide exploding each other.
// Example 3:
// Input:
// asteroids = [10,2,-5]
// Output:
// [10]
// Explanation:
// The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
// Constraints:
// 2 <= asteroids.length <= 10
// 4
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();

        for(int ast : asteroids){
            Boolean flag = true;
            while(!stk.isEmpty() && stk.peek() > 0 && ast < 0){
                if(Math.abs(stk.peek()) < Math.abs(ast)){
                    stk.pop();
                    continue;
                }
                else if(Math.abs(stk.peek()) == Math.abs(ast)){
                    stk.pop();
                }
                flag = false;
                break;
            }
            if(flag == true){
                stk.push(ast);
            }
        }

        int n = stk.size();
        int[] ret = new int[n];

        for(int i = n - 1; i >= 0; i--){
            ret[i] = stk.pop();
        }

        return ret;
    }
}
