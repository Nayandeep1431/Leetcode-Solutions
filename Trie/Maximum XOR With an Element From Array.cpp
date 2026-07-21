int n ;
class Node{
    public : 
    Node* links[2] ; 
    bool flag = false ; 
    
    bool containsKey(int bit){
        return links[bit] != NULL  ; 
    }

    Node* get(int bit){
        return links[bit] ; 
    }

    void put(int bit , Node* node){
        links[bit] = node ; 
    }
};

class Trie{
    public : 
    Node* root ; 
    Trie(){
        root = new Node() ;
    }

    void insert(int num){
        Node* node = root ; 
        for(int i = 31 ; i>= 0 ; i--){
            int bit = (num >> i) & 1 ;
            if(!node -> containsKey(bit))
                node -> put(bit , new Node()) ;

            node = node -> get(bit) ;     
        }
    }

    int getMax(int num){
        Node* node = root ; 
        int maxi = 0 ; 
        for(int i = 31 ; i>= 0 ; i--){
            int bit = (num >> i) & 1 ;
            if(node -> containsKey(1 - bit)){
                maxi = maxi | (1 << i) ; 
                node = node -> get(1 - bit) ; 
            }
            else
                node = node -> get(bit) ; 
        }
        return maxi ;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 
        int q = queries.size() ; 
        vector<int> ans(q) ; 
        
        vector<pair<int , pair<int , int>>> arr ; 
        int ind = 0 ; 
        for(auto it : queries){
            arr.push_back({it[1] , {it[0] , ind++}})  ; 
        }

        sort(arr.begin() ,arr.end()) ; 
        int i = 0 ; 
        Trie trie ; 

        for(auto &it : arr){
            while(i < n && nums[i] <= it.first){
                trie.insert(nums[i]) ; 
                i++ ;
            }

            if(i != 0)
                ans[it.second.second] = trie.getMax(it.second.first) ; 
            else
                ans[it.second.second] = - 1;    
        }
        return ans;
    }
};
