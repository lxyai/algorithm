#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class subset {
public:
    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    void sort(vector<int> nums, int left, int right) {
        if (left >= right) return;
        int i = left;
        int j = right;

        while(i < j) {
            while (i < j && nums[j] >= nums[left]) j--;

            while (i < j && nums[i] <= nums[left]) i++;

            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        sort(nums, left, i-1);
        sort(nums, i+1, right);
    }

    vector<vector<int> > subsetsWithDup(vector<int> nums) {
        vector<vector<int> > rst;
        rst.push_back(vector<int>());
        if (nums.size() <= 0) return rst;
        sort(nums, 0, nums.size()-1);
        vector<int> p(nums.size(), 0);
        int length = 2;
        
        for (int i = 1; i < nums.size(); i++) {
            bool isEqual = false;
            int start= 0;
            p[i] = length;
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] == nums[j]) {
                    isEqual = true;
                    start = p[j];
                    break;
                }
            }
            if (isEqual) {
                length += length - start;
            } else {
                length += length;
            }
        }


        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int> > temp;
            for (int j = p[i]; j < rst.size(); j++) {
                vector<int> tmp(rst[j].begin(), rst[j].end());
                tmp.push_back(nums[i]);
                temp.push_back(tmp);
            }
            rst.insert(rst.end(), temp.begin(), temp.end());
        }
        return rst;
    }
};

int main() {
    vector<int> nums = {1,1,2,2};
    subset s = subset();
    vector<vector<int> > rst = s.subsetsWithDup(nums);
    for (int i = 0; i < rst.size(); i++) {
        for (int j = 0; j < rst[i].size(); j++) {
            cout << rst[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}
