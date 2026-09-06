
class Solution {
public:
    long long pairAndSum(std::vector<int> &arr) {
        long long totalSum = 0;

        // Iterate through all 32 bit positions
        for (int bit = 0; bit < 32; bit++) {
            long long count = 0;

            // Count elements that have the current bit set
            for (int x : arr) {
                if ((x >> bit) & 1) {
                    count++;
                }
            }

            // Number of pairs where both elements have the bit-th bit set
            long long pairs = (count * (count - 1)) / 2;
            totalSum += pairs * (1LL << bit);
        }

        return totalSum;
    }
};



