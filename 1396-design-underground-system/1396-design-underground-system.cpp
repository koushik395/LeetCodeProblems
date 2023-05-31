class UndergroundSystem {
public:
    unordered_map<string,unordered_map<string,vector<int>>> stat;
    unordered_map<int,pair<string,int>> time;
    double avgTime;
    UndergroundSystem() {
        avgTime = 0;
    }
    
    void checkIn(int id, string stationName, int t) {
        time[id] = make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string checkinStation = time[id].first;
        int checkinTime = time[id].second;
        stat[checkinStation][stationName].push_back(t - checkinTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int len = stat[startStation][endStation].size();
        vector<int> times = stat[startStation][endStation];
        int sum  = accumulate(times.begin(),times.end(),0);

        avgTime = (sum*1.0)/len;
        return avgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */