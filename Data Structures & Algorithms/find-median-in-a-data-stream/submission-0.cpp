class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()<=minheap.size())
          maxheap.push(num);
        else
          minheap.push(num);
        while(maxheap.size()&&minheap.size()&&maxheap.top()>minheap.top()){
            int temp = maxheap.top();
            maxheap.pop();
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(temp);
        }
    }
    
    double findMedian() {
        if((maxheap.size()+minheap.size())%2)
         return maxheap.top();
        else
         return (maxheap.top()+minheap.top())/2.0;
    }
};
