// Link: https://leetcode.com/problems/all-oone-data-structure/description
// Description
// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
// Implement the
// AllOne
// class:
// AllOne()
// Initializes the object of the data structure.
// inc(String key)
// Increments the count of the string
// key
// by
// 1
// . If
// key
// does not exist in the data structure, insert it with count
// 1
// .
// dec(String key)
// Decrements the count of the string
// key
// by
// 1
// . If the count of
// key
// is
// 0
// after the decrement, remove it from the data structure. It is guaranteed that
// key
// exists in the data structure before the decrement.
// getMaxKey()
// Returns one of the keys with the maximal count. If no element exists, return an empty string
// ""
// .
// getMinKey()
// Returns one of the keys with the minimum count. If no element exists, return an empty string
// ""
// .
// Note
// that each function must run in
// O(1)
// average time complexity.
// Example 1:
// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]
// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"
// Constraints:
// 1 <= key.length <= 10
// key
// consists of lowercase English letters.
// It is guaranteed that for each call to
// dec
// ,
// key
// is existing in the data structure.
// At most
// 5 * 10
// 4
// calls will be made to
// inc
// ,
// dec
// ,
// getMaxKey
// , and
// getMinKey
// .

class Node{
public:
    unordered_set<string> keys;
    int count;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr), count(0) {}

    Node(string &key, int count) : next(nullptr), prev(nullptr), count(count) {
        keys.insert(key);
    }

    Node* insert(Node* node){
        node->next = this->next;
        node->prev = this;
        this->next->prev = node;
        this->next = node;
        return node;
    }

    void remove(){
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
};

class AllOne {
private:
    Node root;
    unordered_map<string, Node*> mp;

public:
    AllOne() {
        root.next = &root;
        root.prev = &root;    
    }
    
    void inc(string key) {
        if(mp.find(key) != mp.end()){

            Node* curr = mp[key];
            Node* next = curr->next;

            if(next == &root or next->count > curr->count + 1){
                mp[key] = curr->insert(new Node(key, curr->count + 1));
            }
            else{
                next->keys.insert(key);
                mp[key] = next;
            }

            curr->keys.erase(key);

            if(curr->keys.empty()){
                curr->remove();
                delete curr;
            }
        }
        else{
            if(root.next == &root or root.next->count > 1){
                mp[key] = root.insert(new Node(key, 1));
            } 
            else{
                root.next->keys.insert(key);
                mp[key] = root.next;
            }
        }
    }
    
    void dec(string key) {

        auto it = mp.find(key);
        if(it == mp.end()){
            return;
        }

        Node *current = it->second;

        if(current->count == 1){
            mp.erase(key);
        } 
        else{
            Node *prev = current->prev;

            if(prev == &root || prev->count < current->count - 1){
                mp[key] = prev->insert(new Node(key, current->count - 1));
            } 
            else{
                prev->keys.insert(key);
                mp[key] = prev;
            }
        }

        current->keys.erase(key);
        
        if(current->keys.empty()){
            current->remove();
            delete current;
        }
    }
    
    string getMaxKey() {
        if(root.prev == &root){
            return ""; 
        }
        return *root.prev->keys.begin();
    }
    
    string getMinKey() {
        if(root.next == &root){
            return ""; 
        }
        return *root.next->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
