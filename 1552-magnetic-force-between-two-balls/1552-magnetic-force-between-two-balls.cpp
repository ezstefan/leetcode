class Solution {
    bool canWePlace(vector<int>& position, int force, int balls) {
        int n = position.size();
        int cntBalls = 1;
        int last = position[0];

        for (int i =1; i<n; i++) {
            if (position[i] - last >= force) {
                cntBalls++;
                last = position[i];
            }
            if (cntBalls >= balls) return true;

        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1;
        int high = position[n-1] - position[0];

        while (low<=high) {
            int mid = low + (high-low) / 2;

            if(canWePlace(position,mid,m) == true) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;

       
    }
};