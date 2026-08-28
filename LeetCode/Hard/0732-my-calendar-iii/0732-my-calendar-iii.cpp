class MyCalendarThree {
public:
    map<int,int> m;
    int mcnt = 0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        m[startTime]+=1;
        m[endTime]-=1;
        int cnt = 0;
        for(auto i : m){cnt += i.second; mcnt = max(mcnt,cnt);}
        return mcnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */