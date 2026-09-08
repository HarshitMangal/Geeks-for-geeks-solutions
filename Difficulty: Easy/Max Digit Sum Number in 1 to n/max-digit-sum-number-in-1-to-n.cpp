
class Solution {
public:
    int sum(int n) {
        int s = 0;

        while(n > 0) {
            s += n % 10;
            n /= 10;
        }

        return s;
    }

    int findMax(int n) {
        int ans = n;
        int maxi = sum(n);

        string s = to_string(n);

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '0')
                continue;

            s[i]--;

            for(int j = i + 1; j < s.size(); j++) {
                s[j] = '9';
            }

            int num = stoi(s);
            int digitSum = sum(num);

            if(digitSum > maxi ||
              (digitSum == maxi && num > ans)) {
                maxi = digitSum;
                ans = num;
            }

            s = to_string(n);
        }

        return ans;
    }
};

