class Solution {
public:
    char toLower(char a){
        if(a>='A' && a<='Z'){
            return 'a' + (a-'A');
        }
        return a;
    }
    bool isPalindrome(string s) {
         int i=0, j=s.size()-1;
         while(i<j){
            char a = s[i];
            char b = s[j];
            if(!(a>='A' && a<='Z') && !(a>='a' && a<='z') && !(a>='0' && a<='9')){
                i++;
                continue;
            }
            if(!(b>='A' && b<='Z') && !(b>='a' && b<='z') && !(b>='0' && b<='9')){
                j--;
                continue;
            }
            if(toLower(a)!=toLower(b)){
                return false;
            }
            i++;
            j--;
         }
         return true;
    }
};
