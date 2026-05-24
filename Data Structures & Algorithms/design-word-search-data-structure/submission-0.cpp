class TrieNode{
    public:
    bool isEnd;
    unordered_map<char,TrieNode*>ref;
    TrieNode(){
        isEnd = false;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            unordered_map<char,TrieNode*> ref = curr -> ref;
            if(ref.find(c)==ref.end())
              curr -> ref[c] = new TrieNode();
            curr = curr -> ref[c]; 
        }
        curr -> isEnd = true;
    }
    
    bool find(string &word, int index, TrieNode* curr){
        if(index==word.size()){
            return curr->isEnd;
        }
        unordered_map<char,TrieNode*> ref = curr -> ref;
        if(word[index]!='.'){
            if(ref.find(word[index])==ref.end())
              return false;
            return find(word,index+1,curr -> ref[word[index]]);
        }
        for(auto a: ref){
            if(find(word,index+1, a.second))
             return true;
        }
        return false;
    }

    bool search(string word) {
        TrieNode* curr = root;
        return find(word,0,curr);
    }
};
