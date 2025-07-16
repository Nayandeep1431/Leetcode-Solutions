class Solution {
    int oddEvenMax(vector<int> &nums){
        int odd =0 ;
        int even =0 ;
        for(int i =0; i< nums.size() ; i++){
            if(nums[i] % 2 == 0)
                even++ ;
            else
                odd++ ;    
        }
        return max(odd , even) ;
    }

 int alternate(vector<int> &a) {
    int n = a.size();
    int maxi1 = 0, f1 = 0;

    for (int i = 0; i < n; i++) {
        if (!f1 && a[i] % 2) {
            f1 = 1;
            maxi1++;
        } else if (f1 && a[i] % 2 == 0) {
            maxi1++;
            f1 = 0;
        }
    }

    int maxi2 = 0, f2 = 1;

    for (int i = 0; i < n; i++) {
        if (f2 && a[i] % 2 == 0) {
            f2 = 0;
            maxi2++;
        } else if (!f2 && a[i] % 2) {
            maxi2++;
            f2 = 1;
        }
    }

    return max(maxi1, maxi2);
}

    
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size() ;
        if(n <= 2)
            return n ;

        return max(oddEvenMax(nums) , alternate(nums)) ;    
    }
};
