class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        int maxYet = 0;
        vector<int> maxr(n, 0);
        maxr[height.size() - 1] = height[height.size() - 1];
        for(int i=height.size()-2; i>=0; i--){
            maxr[i] = max(maxr[i+1], height[i]);
        }
        
        for(int i=0; i<height.size(); i++){
            //int m1 = getMaxElement(height, 0, i-1);
            //cout<<m1<<" "<<m2<<" ";
            int curr = min(maxr[i], maxYet) - height[i];
            maxYet = max(maxYet, height[i]);
            if(curr < 0) continue;
            waterTrapped = waterTrapped + curr;
            
            cout<<maxYet<<" ";
        }
        
        return waterTrapped;
    }
};