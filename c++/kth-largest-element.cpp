#include<iostream>
#include<vector>

using namespace std;

class Solution {

public:
    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    int kthLargestElementHelper(vector<int> &nums, int left, int right, int n) {
        int i = left;
        int j = right;
        int pivot = nums[left];

        while (i < j) {
            while (nums[j] <= pivot && i < j) j--;

            while (nums[i] >= pivot && i < j) i++;

            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        
        if (i+1 == n) {
           return nums[i];
        } else if (i+1 < n) {
           return kthLargestElementHelper(nums, i+1, right, n);
        } else {
           return kthLargestElementHelper(nums, left, i-1, n);
        }
    }

    int kthLargestElement(vector<int> &nums, int n) { 
        int left = 0;
        int right = nums.size()-1;
        return kthLargestElementHelper(nums, left, right, n);
    }

};

int main() {
    vector<int> nums {9, 3, 2, 4, 8};

    Solution s = Solution();
    int rst = s.kthLargestElement(nums, 3);

    cout << rst << endl;

    return 0;
}
