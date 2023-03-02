class Solution {
private:
    /* Merge Sort */
    void merge(vector<int> &nums, int l, int m, int r) {
        int i, j, k;
        vector<int> merged(r-l+1);

        for(i = l, j = m+1, k = 0; i <= m && j <= r; k++) {
            if(nums[i] <= nums[j]) merged[k] = nums[i++];
            else merged[k] = nums[j++];
        }

        while(i <= m) merged[k++] = nums[i++];
        while(j <= r) merged[k++] = nums[j++];

        for(i = l, k = 0; k < merged.size(); i++, k++) nums[i] = merged[k];
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if(l == r) return;
        int m = l + (r-l)/2;

        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);

        merge(nums, l, m, r);
    }

    /* Quick Sort */
    int partition(vector<int> &nums, int l, int r) {
        int p = l + (r-l)/2, i, j; // estimate p in the middle
        
        swap(nums[p], nums[l]);
        p = l;

        for(i = l+1, j = l+1; i <= r; i++) 
            if(nums[i] < nums[p]) swap(nums[i], nums[j++]);

        swap(nums[p], nums[--j]);
        return j;
    }

    void quickSort(vector<int> &nums, int l, int r) {
        if(l >= r) return;
        int p = partition(nums, l, r);

        quickSort(nums, l, p-1);
        quickSort(nums, p+1, r);
    }

public:
 

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        // quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};