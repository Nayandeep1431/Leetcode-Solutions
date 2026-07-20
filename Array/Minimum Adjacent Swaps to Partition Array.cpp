class Solution {
public:
    int MOD = 1e9 + 7 ; 
 long long merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;
        long long inv = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv = (inv + (mid - i + 1)) % MOD;
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];

        return inv;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return 0;

        int mid = l + (r - l) / 2;

        long long left = mergeSort(arr, l, mid);
        long long right = mergeSort(arr, mid + 1, r);
        long long curr = merge(arr, l, mid, r);

        return (left + right + curr) % MOD;
    }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size() ; 
        for(int i =0 ; i< n ; i++){
            if(nums[i] < a)
                nums[i] = 0 ; 
            else if(nums[i] > b)
                nums[i] = 2 ; 
            else
                nums[i] = 1 ;        
        }
        return mergeSort(nums , 0 , n-1) % MOD ;
    }
};
