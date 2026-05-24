class Solution {
public:
    int getIndex(char c){
        if(c>='a'&&c<='z'){
            return c-'a';
        }
        return (c-'A')+26;
    }
    bool verify(int freq[],int freq2[]){
        for(int i=0;i<52;i++){
            if(freq[i]>freq2[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans="";
        bool found = false;
        int n=s.size(), m=t.size();
        int freq[52], freq2[52];
        for(int i=0;i<52;i++){
            freq[i]=freq2[i] = 0;
        }
        for(char c: t){
            freq[getIndex(c)]++;
        }
        int i=0,j=0;
        // while(j<m){
        //      freq2[getIndex(s[j++])]++;
        // }
        while(true){
           if(verify(freq,freq2)){
            while(verify(freq,freq2)){
               string temp = s.substr(i,j-i);
               if(temp.size()<ans.size() || found==false){
                ans = temp;
                found = true;
               }
               freq2[getIndex(s[i++])]--;
            }
           }
           if(j<n)
            freq2[getIndex(s[j++])]++;
           else
            break;
        }
        return ans;
    }
};
