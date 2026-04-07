class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        int level = 0;
        int temp = label;

        // Find level of label
        while (temp > 0) {
            level++;
            temp /= 2;
        }

        while (label >= 1) {
            path.push_back(label);

            int start = pow(2, level - 1);
            int end = pow(2, level) - 1;

            label = (start + end - label) / 2;
            level--;
        }

        reverse(path.begin(), path.end());
        return path;
    }
};