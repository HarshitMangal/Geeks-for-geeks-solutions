class Solution {
	public:
	int maxSubsetXOR(vector<int> &arr) {
		int N = arr.size();
		if (N == 0)
			return 0;
		
		int x = 0;
		
		while (true) {
			int y = *max_element(arr.begin(), arr.end());
			
			if (y == 0)
				return x;
			
			x = max(x, x ^ y);
			
			for (int i = 0; i < N; i++) {
				arr[i] = min(arr[i], arr[i] ^ y);
			}
		}
		
		return x;
	}
};