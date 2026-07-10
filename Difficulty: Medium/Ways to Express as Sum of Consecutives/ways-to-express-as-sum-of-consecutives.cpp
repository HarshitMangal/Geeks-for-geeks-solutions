class Solution {
  public:
    int getCount(int N) {
         int count=0;
       for (int k = 2; k * (k - 1) < 2 * N; ++k) {
    int num = N - (k * (k - 1)) / 2;
    if (num % k == 0) {
        count++;
    }
}
 return count;
        
    }
};