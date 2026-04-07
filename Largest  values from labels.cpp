class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        
        vector<pair<int,int>> items;
        
        for(int i = 0; i < values.size(); i++){
            items.push_back({values[i], labels[i]});
        }
        
        // sort by value descending
        sort(items.begin(), items.end(), greater<pair<int,int>>());
        
        unordered_map<int,int> count;
        int sum = 0;
        int taken = 0;
        
        for(auto &item : items){
            int value = item.first;
            int label = item.second;
            
            if(count[label] < useLimit){
                sum += value;
                count[label]++;
                taken++;
            }
            
            if(taken == numWanted) break;
        }
        
        return sum;
    }
};