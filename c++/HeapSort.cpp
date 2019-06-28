#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    void adjustHeap(vector<int> &nums, int k, int length) {
        for (int i = 2*k+1; i < length; i = 2*i+1) {
            if (i < length - 1 && nums[i] < nums[i+1]) {
                i++;
            } 
            if (nums[i] > nums[k]) {
                swap(nums[i], nums[k]);
                k = i;
            } else {
                break;
            }
        }
    }

    void sort(vector<int> &nums) {
        for (int i = nums.size()/2 - 1; i >= 0; i--) {
            adjustHeap(nums, i, nums.size());
        }
        for (int i = nums.size()-1; i > 0; i--) {
            swap(nums[0], nums[i]);
            adjustHeap(nums, 0, i);
        }
    }
};

int main() {
    vector<int> nums = {2, 8, 6, 4, 1, 3};
    HeapSort s = HeapSort();
    s.sort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
