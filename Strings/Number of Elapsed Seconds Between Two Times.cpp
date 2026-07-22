class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int ans = 0 ; 
        int sh = ((startTime[0] - '0') * 10 + startTime[1] - '0') ; 
        int eh = ((endTime[0] - '0') * 10 + endTime[1] - '0') ; 

        int sm = ((startTime[3] - '0') * 10 + startTime[4] - '0') ; 
        int em = ((endTime[3] - '0') * 10 + endTime[4] - '0') ; 

        int ss = ((startTime[6] - '0') * 10 + startTime[7] - '0') ; 
        int es = ((endTime[6] - '0' )* 10 + endTime[7] - '0') ;   

        ans = ((eh - sh) * 60 *60) + ((em - sm)* 60) + (es - ss) ; 
        return ans ;      
    }
};
