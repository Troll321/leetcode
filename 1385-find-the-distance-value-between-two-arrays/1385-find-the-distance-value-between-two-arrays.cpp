class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=arr1.size();
        for(int x:arr1) {
            for(int y:arr2) {
                if(abs(x-y)<=d) {ans--;break ;}
            }
        }
        return ans;
    }
};