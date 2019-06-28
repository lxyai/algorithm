#include <iostream>
#include <vector>

using namespace std;

class SubSet {
public:
    vector<vector<int>> subset(vector<int> nums) {
        vector<vector<int>> rst;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> tmp;
            tmp.push_back(nums[i]);
            rst.push_back(tmp);
        }
        for (int len = 2; len <= nums.size(); len++) {
            for (int i = 0; i <= nums.size()-len; i++) {
                int j = i + len;
                vector<int> tmp = vector<int>(nums.begin()+i, nums.begin()+j);
                rst.push_back(tmp);
            }
        }
        return rst;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    SubSet s = SubSet();
    vector<vector<int>> rst = s.subset(nums);
    for (int i = 0; i < rst.size(); i++) {
        for (int j = 0; j < rst[i].size(); j++) {
            cout << rst[i][j] << ',';
        }
        cout << endl;
    }
}
