class Solution {
// Using binary Search
    int cntSmaller(vector<vector<int>> &mat , int mid){
        int n = mat.size() ;
        int cnt =0 ;
        for(int i =0 ; i< n ; i++){
            cnt += upper_bound(mat[i].begin() ,mat[i].end() ,mid) - mat[i].begin() ;
        }
        return cnt ;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int low = matrix[0][0] ;
        int high = matrix[n-1][n-1] ;   
        int ans = -1 ;

        while(low <= high){
            int mid = low + (high - low) / 2 ;
            int cnt = cntSmaller(matrix , mid) ;
            if(cnt >= k){
                ans = mid ;
                high = mid - 1 ;
            }
            else
                low = mid + 1 ;
        }
        return ans ;
     }

// Using Max Heap
        //  int kthSmallest(vector<vector<int>>& matrix, int k) {
        // int n = matrix.size() ;
        // priority_queue<int> pq ;
        // for(int i =0 ; i< n ; i++){
        //     for(int j =0 ; j< n ; j++){
        //         if(pq.size() < k){
        //             pq.push(matrix[i][j]) ;
        //         }
        //         else if(pq.size() == k){
        //             if(matrix[i][j] < pq.top()){
        //                 pq.pop() ;
        //                 pq.push(matrix[i][j]) ;
        //             }
        //         }
        //     }
        // }
        // return pq.top() ;
        //  }
};
