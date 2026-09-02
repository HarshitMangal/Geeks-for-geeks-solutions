class Solution {
  public:
    int solve(int n, string s) {
   map<char, bool> mp;

   int used = 0;
   int rejected = 0;

   for(char ch : s) {

       // First occurrence
       if(mp.find(ch) == mp.end()) {

           if(used < n) {
               // Computer mil gaya
               mp[ch] = true;
               used++;
           }
           else {
               // Computer nahi mila
               mp[ch] = false;
               rejected++;
           }
       }

       // Second occurrence
       else {

           // Agar computer mila tha
           if(mp[ch] == true) {
               used--;
           }

           // Customer ko remove kar do
           mp.erase(ch);
       }
   }

   return rejected;
    }
};
