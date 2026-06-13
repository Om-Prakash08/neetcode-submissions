class Solution {
public:
    bool ifEdge(string a, string b){
        int n = a.size();
        int diff = 0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])
              diff++;
            if(diff>1)
              return false;
        }
        return diff==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int ans=1;
        int n = wordList.size();
        vector<int>visited(n,false);
        while(q.size()){
            int m = q.size();
            ans++;
            while(m--){
            string front = q.front();
            q.pop();
            for(int i=0;i<n;i++){
              if(visited[i]==false&&ifEdge(wordList[i],front)){
                if(wordList[i]==endWord)
                  return ans;
                visited[i] = true;
                q.push(wordList[i]);
              }
            }
            }
        }
        return 0;
    }
};
