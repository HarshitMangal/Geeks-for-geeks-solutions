class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
          int n=arr1.size();
        int m=arr2.size();
        int i=0;
        int j=0;
        int sum1=0;
        int sum2=0;
        int maxsum=0;
        while(i<n&&j<m){
            if(arr1[i]==arr2[j]){
                sum1+=arr1[i];
                sum2+=arr2[j];
                maxsum=max(sum1,sum2);
                sum1=maxsum;
                sum2=maxsum;
                i++;
                j++;
            }
            else if(arr1[i]>arr2[j]){
                sum2+=arr2[j];
                j++;
            }
            else if(arr1[i]<arr2[j]){
                sum1+=arr1[i];
                i++;
            }
        }
            while(i==n&&j<m){
                sum2+=arr2[j];
                j++;
            }
            while(j==m&&i<n){
                sum1+=arr1[i];
                i++;
            }
        
        return max(sum1,sum2);
        
    }
};