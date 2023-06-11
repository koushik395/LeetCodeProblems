class StockPrice {
public:
    int curr;
    int prevTimestamp = 0;
    set<pair<int,int>> st;
    unordered_map<int,int> mp;
    StockPrice() {
        curr = 0;
    }
    
    void update(int timestamp, int price) {
        if(prevTimestamp == 0) prevTimestamp = timestamp;
        if(mp.find(timestamp) != mp.end())
        {
            st.erase({mp[timestamp],timestamp});
        }
        st.insert({price,timestamp});
        mp[timestamp] = price;
        if(timestamp >= prevTimestamp)
        {
            curr = price;
            prevTimestamp = timestamp;
        }
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return prev(st.end())->first;
    }
    
    int minimum() {
        return st.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */