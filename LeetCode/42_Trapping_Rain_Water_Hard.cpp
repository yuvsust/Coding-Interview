class Solution {
public:
    int trap(vector<int>& height) {
        vector < int > water_above_bar;
        
        int mx = 0;
        for(int i = 0; i < height.size(); i++) {
            mx = max(mx, height[i]);
            water_above_bar.push_back(mx);
        }

        mx = 0;
        int total_water = 0;
        
        for(int i = height.size()-1; i >= 0; i--) {
            mx = max(mx, height[i]);
            if(mx <= water_above_bar[i]) {
                water_above_bar[i] = mx - height[i];
            }
            else {
                water_above_bar[i] -= height[i];
            }
            total_water += (water_above_bar[i]);
        }

        return total_water;
		
		
		
		
		/*****
		Using Two Pointers (Just one iteration)
		
		int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;
        int total_water = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                total_water += (leftMax - height[left]);
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                total_water += (rightMax - height[right]);
                right--;
            }
        }
        return total_water;
		
		*****/
    }
};