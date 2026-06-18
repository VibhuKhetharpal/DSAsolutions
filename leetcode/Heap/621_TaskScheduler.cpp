class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int freq[26]={0};
            for(char t:tasks){
                freq[t-'A']++;
            }
            int max_freq = *max_element(freq,freq+26);
            int count_max = count(freq,freq+26,max_freq);
    
            return max((int)tasks.size(), (max_freq - 1) * (n + 1) + count_max);
    
        }
    };