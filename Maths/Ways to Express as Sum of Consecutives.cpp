class Solution {
  public:

int getCount(int n) {
    int cnt = 0;

    for(int i = 1 ; i < sqrt(2*n) ; i++){
        if((n - (i * (i-1))/2) % i == 0)
            cnt++ ; 
    }

    return cnt - 1;
}
};
