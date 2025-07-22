// Link: https://leetcode.com/problems/implement-trie-prefix-tree/description
// Description
// A
// trie
// (pronounced as "try") or
// prefix tree
// is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
// Implement the Trie class:
// Trie()
// Initializes the trie object.
// void insert(String word)
// Inserts the string
// word
// into the trie.
// boolean search(String word)
// Returns
// true
// if the string
// word
// is in the trie (i.e., was inserted before), and
// false
// otherwise.
// boolean startsWith(String prefix)
// Returns
// true
// if there is a previously inserted string
// word
// that has the prefix
// prefix
// , and
// false
// otherwise.
// Example 1:
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word
// and
// prefix
// consist only of lowercase English letters.
// At most
// 3 * 10
// 4
// calls
// in total
// will be made to
// insert
// ,
// search
// , and
// startsWith
// .

class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool end;

    TrieNode(){
        children = unordered_map<char, TrieNode*>();
        end = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(const auto& c : word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(const auto& c : word){
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            curr =  curr->children[c];
        }
        return curr->end; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(const auto& c : prefix){
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            curr =  curr->children[c];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
