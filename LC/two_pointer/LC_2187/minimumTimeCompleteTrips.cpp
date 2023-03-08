class Solution {
private:
    // idea here is that for each time, the number of trips
    //  made will be t / time, so we can sum these to get the total trips at t
    bool checkValidTime(long long t, int totalTrips, vector<int> &times) {
        long long sum = 0;

        for(int time : times) 
            sum += t/time;

        return sum >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minTime = *min_element(time.begin(), time.end());
        long long l = 1, h = minTime * totalTrips, m;

        while(l < h) {
            m = l + (h-l)/2;

            if(checkValidTime(m, totalTrips, time)) h = m;
            else l = m+1;
        }

        return l;
    }
};