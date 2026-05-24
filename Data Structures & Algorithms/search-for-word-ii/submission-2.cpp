class TrieNode{
    public:
    bool isEnd;
    unordered_map<char,TrieNode*>ref;
    TrieNode(){
        isEnd = false;
    }
};
class Solution {
public:
    void insert(string word,TrieNode *root){
         for(char c: word){
            if(root->ref.find(c)==root->ref.end())
              root->ref[c] = new TrieNode();
            root= root->ref[c];
         }
         root->isEnd = true;
    }
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void find(vector<vector<char>>& board, int i,int j, int n, int m, TrieNode* root, vector<string>& ans,vector<vector<bool>>&visited,string &s){
         if(i>=n || i<0 || j>=m || j<0)
           return;
         if(root->isEnd){
            ans.push_back(s);
            root->isEnd = false;
         }
        
         for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0 && x<n && y>=0 && y<m &&   !visited[x][y] && root->ref.find(board[x][y])!= root->ref.end()){
              visited[x][y] =true;
              s.push_back(board[x][y]);
              find(board,x,y,n,m,root->ref[board[x][y]],ans,visited,s);
              visited[x][y] = false;
              s.pop_back();
            }
         }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = new TrieNode();
        for(string word: words)
         insert(word,root);
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->ref.find(board[i][j])!=root->ref.end()){
                string s;
                s+=board[i][j];
                visited[i][j] = true;
                find(board,i,j,n,m,root->ref[board[i][j]],ans,visited,s);
                visited[i][j] = false;
                }
            }
        }
        return ans;
    }
};
