// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/description
// Description
// Given a string
// expression
// of numbers and operators, return
// all possible results from computing all the different possible ways to group numbers and operators
// . You may return the answer in
// any order
// .
// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed
// 10
// 4
// .
// Example 1:
// Input:
// expression = "2-1-1"
// Output:
// [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:
// Input:
// expression = "2*3-4*5"
// Output:
// [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
// Constraints:
// 1 <= expression.length <= 20
// expression
// consists of digits and the operator
// '+'
// ,
// '-'
// , and
// '*'
// .
// All the integer values in the input expression are in the range
// [0, 99]
// .
// The integer values in the input expression do not have a leading
// '-'
// or
// '+'
// denoting the sign.

class Solution {
public:
    vector<int> diffWaysToCompute(string expression){
        vector<int> ret;
        int n = expression.size();

        for(int i = 0; i < n; i++){
            char op = expression[i];
            if(op == '+' || op == '-' || op == '*'){
                vector<int> str1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> str2 = diffWaysToCompute(expression.substr(i + 1));
                for(const auto& a : str1){
                    for(const auto& b : str2){
                        if(op == '+'){
                            ret.push_back(a + b);
                        }
                        else if(op == '-'){
                            ret.push_back(a - b);
                        }
                        else if(op == '*'){
                            ret.push_back(a * b);
                        }
                    }
                }
            }
        }
        if(ret.empty()){
            ret.push_back(stoi(expression));
        }
        return ret;
    }
};
