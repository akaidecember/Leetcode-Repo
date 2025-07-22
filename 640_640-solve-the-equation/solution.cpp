// Link: https://leetcode.com/problems/solve-the-equation/description
// Description
// Solve a given equation and return the value of
// 'x'
// in the form of a string
// "x=#value"
// . The equation contains only
// '+'
// ,
// '-'
// operation, the variable
// 'x'
// and its coefficient. You should return
// "No solution"
// if there is no solution for the equation, or
// "Infinite solutions"
// if there are infinite solutions for the equation.
// If there is exactly one solution for the equation, we ensure that the value of
// 'x'
// is an integer.
// Example 1:
// Input:
// equation = "x+5-3+x=6+x-2"
// Output:
// "x=2"
// Example 2:
// Input:
// equation = "x=x"
// Output:
// "Infinite solutions"
// Example 3:
// Input:
// equation = "2x=x"
// Output:
// "x=0"
// Constraints:
// 3 <= equation.length <= 1000
// equation
// has exactly one
// '='
// .
// equation
// consists of integers with an absolute value in the range
// [0, 100]
// without any leading zeros, and the variable
// 'x'
// .
// The input is generated that if there is a single solution, it will be an integer.

class Solution {
public:
    string solveEquation(string equation) {
        unordered_map<char,int> lhs = {{'x', 0}, {'n', 0}};
        unordered_map<char,int> rhs = {{'x', 0}, {'n', 0}};

        bool leftHandSide = true;
        char curOperator = '+';
        string curNum = "";
        char modify = 'n';
        string ans = "x=";
        for (int i = 0; i < equation.size(); i++) {
            if (equation[i] == '=') {
                if (curOperator  == '+') {
                    lhs[modify] += stoi(curNum);
                } else {
                    lhs[modify] -= stoi(curNum);
                }
                leftHandSide = false;
                curNum = "";
                curOperator = '+';
                continue;
            }

            // change operator
            if (ispunct(equation[i])) {
                if (curNum.size() != 0) {
                    // do manipulation
                    if (leftHandSide) {
                        if (curOperator == '+') {
                            lhs[modify] += stoi(curNum);
                        } else {
                            lhs[modify] -= stoi(curNum);
                        }
                    } else {
                        if (curOperator  == '+') {
                            rhs[modify] += stoi(curNum);
                        } else {
                            rhs[modify] -= stoi(curNum);
                        }
                    }

                    //reset curNUm
                    curNum = "";
                }
                curOperator = equation[i];
            }

            if (isalnum(equation[i])) {
                if (isdigit(equation[i])) {
                    curNum+=equation[i];
                    modify = 'n';
                } else {
                    if (curNum.size() == 0) curNum+='1';
                    modify = 'x';
                }
            }

            if (i == equation.size() - 1) {
                if (curOperator  == '+') {
                    rhs[modify] += stoi(curNum);
                } else {
                    rhs[modify] -= stoi(curNum);
                }
            }
        }
        cout << lhs['x'] << " " << lhs['n'] << endl;
        cout << rhs['x'] << " " << rhs['n'] << endl;

        if((lhs['x'] - rhs['x'] == 0) && (rhs['n'] - lhs['n'] != 0)) {
            return "No solution";
        }

        if (lhs['x'] == rhs['x']) {
            return "Infinite solutions";
        }

        int val = (rhs['n'] - lhs['n'])/(lhs['x'] - rhs['x']);
        ans+=to_string(val);
        return ans;
    }
};
