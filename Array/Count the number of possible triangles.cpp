class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin() , arr.end()) ;
         int n=arr.size();
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            int min=arr[i];
            int j=0;
            int k=i-1;
            while(j<k)
            {
                if(arr[j]+arr[k]>min)
                {
                    count+=k-j;
                    k--;
                }
                else j++;
            }
        }
        return count;
    }
};
