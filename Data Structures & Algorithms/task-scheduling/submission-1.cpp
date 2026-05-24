class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] ={0};
        int lastSchedeule[26];
        for(int i=0;i<26;i++)
          lastSchedeule[i]=INT_MIN;
        for(char c: tasks)
          freq[c-'A']++;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++)
          if(freq[i])
           pq.push({freq[i],i});
        int ans=0;
        while(pq.empty()==false){
           ans++;
           vector<int>temp;
           while(pq.empty()==false&&lastSchedeule[pq.top().second]+n+1>ans){
             temp.push_back(pq.top().second);
             pq.pop();
           }
           if(pq.empty()==false){
            pair<int,int>top = pq.top();
            pq.pop();
            lastSchedeule[top.second] = ans;
            freq[top.second]--;
            if(freq[top.second])
             pq.push({freq[top.second],top.second});
           }
           for(int i: temp){
            pq.push({freq[i],i});
           }
        }
        return ans;
    }
};
