#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                int max_val = -1;
                int max_index = -1;
                for (int j = i+1; j < n; j++) {
                    if (arr[j] < arr[i] && arr[j] > max_val) {
                        max_val = arr[j];
                        max_index = j;
                    }
                }
                if (max_index != -1) {
                    swap(arr[i], arr[max_index]);
                    return arr;
                }
            }
        }
        return arr;
    }
};