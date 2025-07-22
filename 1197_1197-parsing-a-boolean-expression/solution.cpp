// Link: https://leetcode.com/problems/parsing-a-boolean-expression/description
// Description
// A
// boolean expression
// is an expression that evaluates to either
// true
// or
// false
// . It can be in one of the following shapes:
// 't'
// that evaluates to
// true
// .
// 'f'
// that evaluates to
// false
// .
// '!(subExpr)'
// that evaluates to
// the logical NOT
// of the inner expression
// subExpr
// .
// '&(subExpr
// 1
// , subExpr
// 2
// , ..., subExpr
// n
// )'
// that evaluates to
// the logical AND
// of the inner expressions
// subExpr
// 1
// , subExpr
// 2
// , ..., subExpr
// n
// where
// n >= 1
// .
// '|(subExpr
// 1
// , subExpr
// 2
// , ..., subExpr
// n
// )'
// that evaluates to
// the logical OR
// of the inner expressions
// subExpr
// 1
// , subExpr
// 2
// , ..., subExpr
// n
// where
// n >= 1
// .
// Given a string
// expression
// that represents a
// boolean expression
// , return
// the evaluation of that expression
// .
// It is
// guaranteed
// that the given expression is valid and follows the given rules.
// Example 1:
// Input:
// expression = "&(|(f))"
// Output:
// false
// Explanation:
// First, evaluate |(f) --> f. The expression is now "&(f)".
// Then, evaluate &(f) --> f. The expression is now "f".
// Finally, return false.
// Example 2:
// Input:
// expression = "|(f,f,f,t)"
// Output:
// true
// Explanation:
// The evaluation of (false OR false OR false OR true) is true.
// Example 3:
// Input:
// expression = "!(&(f,t))"
// Output:
// true
// Explanation:
// First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
// Then, evaluate !(f) --> NOT false --> true. We return true.
// Constraints:
// 1 <= expression.length <= 2 * 10
// 4
// expression[i] is one following characters:
// '('
// ,
// ')'
// ,
// '&'
// ,
// '|'
// ,
// '!'
// ,
// 't'
// ,
// 'f'
// , and
// ','
// .

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for(char c : expression){
            if(c != ')' and c != ','){
                stk.push(c);
            }
            else if(c == ')'){
                vector<bool> v;

                while(!stk.empty() and stk.top() != '('){
                    char temp = stk.top();
                    stk.pop();
                    v.push_back((temp == 't') ? true : false);
                }
                stk.pop();

                if(!stk.empty()){
                    char temp = stk.top();
                    stk.pop();
                    bool val = v[0];

                    if(temp == '&'){
                        val = accumulate(v.begin() + 1, v.end(), val, std::bit_and<int>());
                    }
                    else if(temp == '|'){
                        val = accumulate(v.begin() + 1, v.end(), val, std::bit_or<int>());
                    }
                    else{
                        val = !val;
                    }

                    stk.push((val) ? 't' : 'f');
                }
            }
        }
        
        return stk.top() == 't';
    }
};
