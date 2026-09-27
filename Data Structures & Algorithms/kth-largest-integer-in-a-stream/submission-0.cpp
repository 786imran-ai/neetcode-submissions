class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int n: nums){
            minheap.push(n);
            if(minheap.size()>k) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k) minheap.pop();
        return minheap.top();
    }
};
