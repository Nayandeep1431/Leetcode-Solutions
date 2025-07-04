class Solution {
  public:
    vector<int> nse(vector<int> &arr) {
      int n = arr.size();
     stack<int> st;
     vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() > arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

    vector<int> pse(vector<int> &arr){
             int n = arr.size();
     stack<int> st;
     vector<int> ans(n, -1);

    for (int i = 0 ; i < n ; i++) {
        while (!st.empty() && st.top() > arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
    }
    
    int maxSum(vector<int> &arr) {
        // code here
        vector<int> ns , ps ;
        int n = arr.size() ;
        ns = nse(arr) ;
        ps = pse(arr) ;
        
        int maxi = INT_MIN ;
        for(int i =0 ; i< n ; i++){
            int ele = arr[i] ;
            int next = (ns[i] != -1) ? ns[i] : -1e9 ;
            int prev = (ps[i] != -1) ? ps[i] : -1e9 ;
            
            maxi = max({maxi , ele + next ,ele + prev}) ;
        }
        return maxi ;
    }
};
