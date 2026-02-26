class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
      int maxEat = candyType.size() / 2;
      return min (uniqueCandies.size(),(size_t)maxEat);  
    }
};