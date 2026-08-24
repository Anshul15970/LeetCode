class MyCalendar {
public:
    vector<vector<int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &i : cal){
            if(i[0] < endTime && startTime < i[1]){
                return false;
            }
        }
        cal.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */