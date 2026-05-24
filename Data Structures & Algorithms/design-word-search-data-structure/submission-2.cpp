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
            if(curr -> ref.find(c)==curr -> ref.end())
              curr -> ref[c] = new TrieNode();
            curr = curr -> ref[c]; 
        }
        curr -> isEnd = true;
    }
    
    bool find(string &word, int index, TrieNode* curr){
        if(index==word.size()){
            return curr->isEnd;
        }
        if(word[index]!='.'){
            if(curr -> ref.find(word[index])==curr -> ref.end())
              return false;
            return find(word,index+1,curr -> ref[word[index]]);
        }
        for(auto a: curr -> ref){
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
