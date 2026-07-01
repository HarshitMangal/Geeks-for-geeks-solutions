class Solution {
  public:
    int isValid(string &s) {
         int n=s.length();
         int count=0;
         for(int i=0;i<n;i++){
               int num=0;
                 string temp="";
               while(i<n&&s[i]&&s[i]!='.'){
                   num=num*10+(s[i]-'0');
                   temp+=s[i];
                   i++;
               }
               
               if(!(num>=0&&num<=255)) return false;
               if(s[i]=='.'&&s[i+1]=='.') return false;
               if(temp.length()>1&&temp[0]=='0') return false;
               count++;
               
         }
          return count==4;
    }
};