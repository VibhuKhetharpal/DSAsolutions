#BruteForce 
class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        double median;
        if(n%2==0){
            median = ((double)nums[n/2]+nums[(n/2)-1])/2;
        }
        else{
            median = nums[n/2];
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 #TwoHeapsApproach

 class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);

        if(!small.empty()&&!large.empty()&&small.top()>large.top()){
            large.push(small.top());
            small.pop();
        }
        

        if(small.size()>large.size()+1){
            large.push(small.top());
            small.pop();
        }
        if(large.size()>small.size()){
            small.push(large.top());
            large.pop();
        }

    }
    
    double findMedian() {
        if(small.size()>large.size()){
            return small.top();
        }
        else{
            return(small.top()+large.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
