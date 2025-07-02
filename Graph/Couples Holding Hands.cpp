class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() ;
        unordered_map<int , int> mpp ;
        for(int i =0 ; i< n ; i++)
            mpp[row[i]] = i ;

        int cnt = 0 ;
        for(int i =0 ; i< n ; i+= 2){
            int ele = row[i] ;
            if(ele & 1){
                if(mpp[ele - 1] == i+1)
                    continue ;
                else{
                    cnt++ ;
                    int ind = mpp[ele - 1] ;
                    mpp[row[i+1]] = mpp[ele - 1] ;
                    mpp[ele - 1] = i+1 ;
                    swap(row[i+1] ,row[ind]) ;
                }    
            }
            else{
                if(mpp[ele + 1] == i+1)
                    continue ;
                else{
                    cnt++ ;
                    int ind = mpp[ele + 1] ;
                    mpp[row[i+1]] = mpp[ele + 1] ;
                    mpp[ele + 1] = i+1 ;
                    swap(row[i+1] ,row[ind]) ;
                }                        
                   
            }
        }  
        return cnt ;  
    }
};
