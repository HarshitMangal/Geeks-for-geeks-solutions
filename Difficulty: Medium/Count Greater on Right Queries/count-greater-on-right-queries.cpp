class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
         vector<int> ans;

        for (int index : indices) {
            int count = 0;

            for (int j = index + 1; j < arr.size(); j++) {
                if (arr[j] > arr[index]) {
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
        
    }
};