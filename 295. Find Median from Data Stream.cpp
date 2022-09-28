class MedianFinder {
public:
    // ALGO - maintain two priority queue left max heap and right min heap so we can have middle left element and middle right 
    // element from the two queues. also maintain their size to hve middle always 
    priority_queue<int> pqLeft;
    priority_queue <int,vector<int>, greater<int> > pqRight;
    MedianFinder() {
    }
    
    void addNum(int num) {
       if(pqLeft.empty() || num<pqLeft.top()){
           pqLeft.push(num);
       } 
       else{
           pqRight.push(num);
       }
        int n1 = pqLeft.size(), n2 = pqRight.size();
       if(n1-n2>1){
           pqRight.push(pqLeft.top());
           pqLeft.pop();
       }
       if(n2-n1>1){
           pqLeft.push(pqRight.top());
           pqRight.pop();
       }
    }
    
    double findMedian() {
        double ans = 0;
        if(pqLeft.size()==pqRight.size()){
            ans = (double)(pqLeft.top()+pqRight.top())/2;
        }
        else{
            if(pqLeft.size()>pqRight.size()){
                ans = (double) pqLeft.top();
            }
            else ans = (double) pqRight.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */