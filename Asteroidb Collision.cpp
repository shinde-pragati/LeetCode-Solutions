class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;  
        
        for (int asteroid : asteroids) {
     
            bool survives = true;
        
            while (!result.empty() && result.back() > 0 && asteroid < 0) {
            
                if (abs(result.back()) < abs(asteroid)) {
               
                    result.pop_back();
                } else if (abs(result.back()) == abs(asteroid)) {
              
                    result.pop_back();
                    survives = false;
                    break;
                } else {

                    survives = false;
                    break;
                }
            }
  
            if (survives) {
                result.push_back(asteroid);
            }
        }
        
        return result;
    }
};