class Solution {
public:
    int minProd(vector<int>& arr) {

        int negCount = 0;
        int posCount = 0;
        int zeroCount = 0;

        int product = 1;

        int smallestNeg = INT_MIN;
        int smallestPos = INT_MAX;

        for(int x : arr) {

            if(x < 0) {
                negCount++;
                smallestNeg = max(smallestNeg, x);
            }
            else if(x == 0) {
                zeroCount++;
            }
            else {
                posCount++;
                smallestPos = min(smallestPos, x);
            }
        }

        // Negative numbers exist
        if(negCount > 0) {

            // Odd number of negatives
            if(negCount % 2 == 1) {

                for(int x : arr) {
                    if(x != 0)
                        product *= x;
                }

                return product;
            }

            // Even number of negatives
            else {

                bool skipped = false;

                for(int x : arr) {

                    // Remove only ONE negative
                    if(x == smallestNeg && !skipped) {
                        skipped = true;
                        continue;
                    }

                    if(x != 0)
                        product *= x;
                }

                return product;
            }
        }

        // No negative
        if(zeroCount > 0)
            return 0;

        // Only positive numbers
        return smallestPos;
    }
};