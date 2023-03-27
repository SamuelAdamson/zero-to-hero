class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), i, gap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(i = 0; i < n-1; i++) {
            gap = heights[i+1] - heights[i];
            if(gap <= 0) continue;
            
            if(minHeap.size() < ladders) minHeap.push(gap);
            else if(minHeap.empty() || gap <= minHeap.top()) {
                if(bricks < gap) return i;
                bricks -= gap;
            }
            else {
                if(bricks < minHeap.top()) return i;
                bricks -= minHeap.top();

                minHeap.pop();
                minHeap.push(gap);
            }
            
        }

        return i;
    }
};