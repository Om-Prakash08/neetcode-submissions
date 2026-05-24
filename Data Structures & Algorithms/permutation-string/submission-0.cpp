class Solution {
public:
    bool verify(int freq[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int freq[26],freq2[26] ;
        for(int i=0;i<26;i++){
            freq[i]=0;
            freq2[i]=0;
        }
        for(char c: s1){
            freq[c-'a']++;
        }
        int i=0, j=s1.size()-1;
        for(int k=i;k<=j;k++){
            freq2[s2[k]-'a']++;
        }
        while(j<=s2.size()){
           if(verify(freq,freq2)){
            return true;
           }
           if(j<s2.size()-1)
           {freq2[s2[++j]-'a']++;
           freq2[s2[i++]-'a']--;
           }
           else{
            j++;
            i++;
           }
        }
        return false;
    }
};
     