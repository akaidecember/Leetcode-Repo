// Link: https://leetcode.com/problems/search-suggestions-system/description
// Description
// You are given an array of strings
// products
// and a string
// searchWord
// .
// Design a system that suggests at most three product names from
// products
// after each character of
// searchWord
// is typed. Suggested products should have common prefix with
// searchWord
// . If there are more than three products with a common prefix return the three lexicographically minimums products.
// Return
// a list of lists of the suggested products after each character of
// searchWord
// is typed
// .
// Example 1:
// Input:
// products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output:
// [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
// Explanation:
// products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
// Example 2:
// Input:
// products = ["havana"], searchWord = "havana"
// Output:
// [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
// Explanation:
// The only word "havana" will be always suggested while typing the search word.
// Constraints:
// 1 <= products.length <= 1000
// 1 <= products[i].length <= 3000
// 1 <= sum(products[i].length) <= 2 * 10
// 4
// All the strings of
// products
// are
// unique
// .
// products[i]
// consists of lowercase English letters.
// 1 <= searchWord.length <= 1000
// searchWord
// consists of lowercase English letters.

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        sort(begin(products), end(products));
        int left = 0, n = products.size(),right = n-1, m = searchWord.size();
        
        for(int i = 0; i < m; i++){
            char c = searchWord[i];
            while(left <= right && (products[left].size() <= i || products[left][i] != c)){
                left++;
            }
            while(left <= right && (products[right].size() <= i || products[right][i] != c)){
                right--;
            }
            vector<string> t;
            int temp = right - left + 1;
            for(int i = 0; i < min(3, temp); i++){
                t.push_back(products[left + i]);
            }
            ret.push_back(t);
        }
        return ret;
    }
};
