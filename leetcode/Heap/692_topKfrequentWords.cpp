class Compare{
    public:
    bool operator()(pair<int,string>& a,
                    pair<int,string>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;

    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        unordered_map<string,int> freq;
        vector<string> ans;

        for(auto& p:words){
            freq[p]++;
        }
        for(auto& [x,y]:freq){
            pq.push({y,x});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};