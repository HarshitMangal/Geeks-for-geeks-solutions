class Solution {
  public:
    void bst(vector<int>&arr, int lower, int upper, int &index, int N) {
        if (index == N || arr[index] <= lower || arr[index] >= upper) return;

        int value = arr[index];
        index++;

        bst(arr, lower, value, index, N);   // left subtree
        bst(arr, value, upper, index, N);   // right subtree
    }

    bool canRepresentBST(vector<int> &arr) {
        int N=arr.size();
      int index = 0;
        bst(arr, INT_MIN, INT_MAX, index, N);
        return index == N ? 1 : 0;
    }
};