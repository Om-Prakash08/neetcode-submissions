class Solution {
   public:
    bool buildgraph(string& prev, string& curr, unordered_map<char, unordered_set<char>>& mp,
                    unordered_map<char, int>& indegree) {
        int i = 0;
        int j = 0;
        int n = prev.size();
        int m = curr.size();
        while (i < n && j < m && prev[i] == curr[j]) {
            i++;
            j++;
        }
        if (j == m && i < n) return false;
        if (i != n && j != m) {
            if (!(mp.find(prev[i]) != mp.end() && mp[prev[i]].find(curr[j]) != mp[prev[i]].end())) {
                indegree[curr[j]]++;
                mp[prev[i]].insert(curr[j]);
            }
        }
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> mp;
        unordered_map<char, int> indegree;
        for (int i = 0; i < 26; i++) {
            indegree['a' + i] = 0;
        }
        vector<bool> v(26, false);
        int n = 0;
        string prev = words[0];
        for (char c : prev) {
            if (v[c - 'a'] == false) {
                v[c - 'a'] = true;
                n++;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            string curr = words[i];
            for (char c : curr) {
                if (v[c - 'a'] == false) {
                    v[c - 'a'] = true;
                    n++;
                }
            }
            if (buildgraph(prev, curr, mp, indegree) == false) return "";
            prev = curr;
        }
        queue<char> q;
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (v[i] && indegree['a' + i] == 0) {
                q.push('a' + i);
            }
        }
        while (q.empty() == false) {
            char front = q.front();
            q.pop();
            ans.push_back(front);
            for (char c : mp[front]) {
                indegree[c]--;
                if (indegree[c] == 0) {
                    q.push(c);
                }
            }
        }
        return ans.size() == n ? ans : "";
    }
};
