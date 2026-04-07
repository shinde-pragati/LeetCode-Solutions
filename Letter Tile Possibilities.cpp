class Solution {
public:
    int backtrack(vector<int>& count) {
        int sum = 0;

        for(int i = 0; i < 26; i++) {
            if(count[i] == 0) continue;

            sum++;                 // use this character
            count[i]--;
            sum += backtrack(count);
            count[i]++;            // backtrack
        }

        return sum;
    }

    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);

        for(char c : tiles)
            count[c - 'A']++;

        return backtrack(count);
    }
};