class TrieNode{
    public:
    bool isEnd;
    unordered_map<char,TrieNode*>ref;
    TrieNode(){
       isEnd = false;
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word){
           unordered_map<char,TrieNode*>ref = curr -> ref;
           if(ref.find(c)==ref.end())
             curr->ref[c] = new TrieNode();
           curr = curr -> ref[c];
        }
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word){
           unordered_map<char,TrieNode*>ref = curr -> ref;
           if(ref.find(c)==ref.end())
             return false;
           curr = curr -> ref[c];
        }
        return curr -> isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix){
           unordered_map<char,TrieNode*>ref = curr -> ref;
           if(ref.find(c)==ref.end())
             return false;
           curr = curr -> ref[c];
        }
        return true;
    }
};
