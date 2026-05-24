class Solution {
public:
    bool isColumnValid(vector<vector<char>>& board){
         for(int j=0;j<9;j++){
            set<char> s;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end())
                      return false;
                    s.insert(board[i][j]);
                }
            }
         }
         return true;
    }
    bool isRowValid(vector<vector<char>>& board){
         for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end())
                      return false;
                    s.insert(board[i][j]);
                }
            }
         }
         return true;
    }
    bool boxValid(vector<vector<char>>& board, int x, int y){
        set<char>s ;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[x+i][y+j]!='.'){
                    if(s.find(board[x+i][y+j])!=s.end())
                      return false;
                    s.insert(board[x+i][y+j]);
                }
            }
        }
        return true;
    }
    bool isSubBoxValid(vector<vector<char>>& board){
         int di[3]= {0,3,6};
         int dj[3]= {0,3,6};
         for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!boxValid(board,di[i],dj[j])){
                    return false;
                }
            }
         }
         return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         if(!isColumnValid(board))
           return false;
         if(!isRowValid(board))
           return false;
         if(!isSubBoxValid(board))
           return false;
         return true;
    }
};
