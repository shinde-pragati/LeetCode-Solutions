class Solution {
    private:
    double rad;
    double xc;
    double yc;

public:
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    vector<double>

    randPoint() {
        
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
     
        double r = rad * sqrt((double)rand() / RAND_MAX);
      
        double x = xc + r * cos(theta);
        double y = yc + r * sin(theta);
        
        return {x, y};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */