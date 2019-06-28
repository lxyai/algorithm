#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {}

    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if (sum > max) max = sum;

            if (sum < 0) sum = 0;
        }
        return max;
    }

    int maxArray(vector<int> &nums, int left, int right, int &maxV) {
        if (left > right) return INT_MIN;

        int mid = (left + right) / 2;
        int lmax = maxArray(nums, left, mid-1, maxV);
        int rmax = maxArray(nums, mid+1, right, maxV);
        maxV = max(lmax, maxV);
        maxV = max(rmax, maxV);
        int sum = 0;
        int mlmax = 0;
        for (int i = mid - 1; i >= left; i--) {
            sum += nums[i];
            if (sum > mlmax) mlmax = sum;
        }
        sum = 0;
        int mrmax = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            if (sum > mrmax) mrmax = sum;
        }
        maxV = max(maxV, (mlmax + mrmax + nums[mid]));
        return maxV;
    }

    int maxSubArrayDivideAndConquer(vector<int> &nums) {
            int maxV = INT_MIN;
            return maxArray(nums, 0, nums.size()-1, maxV);
    }

};

int main() {
    vector<int> src {-2,1,-3,4,-1,2,1,-5,4};
    Solution s = Solution();
    int rst = s.maxSubArray(src);
    rst = s.maxSubArrayDivideAndConquer(src);
    cout << rst << endl;
}
