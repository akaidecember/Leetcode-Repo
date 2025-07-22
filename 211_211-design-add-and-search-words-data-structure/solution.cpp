// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description
// Description
// Design a data structure that supports adding new words and finding if a string matches any previously added string.
// Implement the
// WordDictionary
// class:
// WordDictionary()
// Initializes the object.
// void addWord(word)
// Adds
// word
// to the data structure, it can be matched later.
// bool search(word)
// Returns
// true
// if there is any string in the data structure that matches
// word
// or
// false
// otherwise.
// word
// may contain dots
// '.'
// where dots can be matched with any letter.
// Example:
// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]
// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
// Constraints:
// 1 <= word.length <= 25
// word
// in
// addWord
// consists of lowercase English letters.
// word
// in
// search
// consist of
// '.'
// or lowercase English letters.
// There will be at most
// 2
// dots in
// word
// for
// search
// queries.
// At most
// 10
// 4
// calls will be made to
// addWord
// and
// search
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

class WordDictionary {
private:
    TrieNode* root;

    bool search_helper(TrieNode* node, const string &word, int idx){
        if(idx == word.size()){
            return node->end;
        }
        char c = word[idx];
        if(c == '.'){
            for(auto& child : node->children){
                if(search_helper(child.second, word, idx + 1)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            return search_helper(node->children[c], word, idx + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return search_helper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
