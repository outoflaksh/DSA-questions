int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int sum = 0;
    
    // The idea is that any gap will be contained by an interval of height vals.
    // And the water contained between them will be all the sum of min(boundary heights) - intermediate heights
    // So, we can just try to find such gaps, and we will find the water area wrt to the min height.
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] < leftMax) {
                sum += leftMax - height[left];
            } else {
                leftMax = height[left];
            }
            
            left++;
        } 
        
        else {
            if (height[right] < rightMax) {
                sum += rightMax - height[right];
            } else {
                rightMax = height[right];
            }
            
            right--;
        }
    }
    
    
    return sum;
}