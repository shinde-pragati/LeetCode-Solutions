// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result;
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if(num <= 40) {
                result = (num - 1) % 10 + 1;
                break;
            }
        }
        return result;
    }
};