class LRUCache {
public:
    list<int> dll ;
    map<int , pair<list<int>::iterator , int>> mpp ;
    int n ;
    LRUCache(int capacity) {
        n = capacity ;
    }
    
    void solve(int key){
        dll.erase(mpp[key].first) ;
        dll.push_front(key) ;
        mpp[key].first = dll.begin() ;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1 ;
        }
        solve(key) ;
        return mpp[key].second ;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key].second = value ;
            solve(key) ;
        }
        else{
            dll.push_front(key) ;
            mpp[key] = {dll.begin() , value} ;
            n-- ;
        }

        if(n < 0){
            mpp.erase(dll.back()) ;
            dll.pop_back() ;
            n++ ;
        }
    }
};
