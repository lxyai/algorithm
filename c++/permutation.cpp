#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {}

    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    void reverse(vector<int> &src, int left, int right) {
        int i = left;
        int j = right;
        while(i < j) {
            swap(src[i], src[j]);
            i++;
            j--;
        }
    }

    void permutation(vector<int> src, vector<vector<int>> &rst) {
        rst.push_back(src);
        while(true) {
                int i = src.size()-2;
                while(src[i] > src[i+1]) {
                    if (i <= 0) return;
                    i--;
                }

                int j = src.size()-1;
                while(src[i] >= src[j]) j--;

                swap(src[i], src[j]);
                reverse(src, i+1, src.size()-1);
                rst.push_back(src);
        }
    }

    void permutationRecurrent(vector<int> &src, int n, vector<vector<int>> &rst) {
        if (n == src.size()-1) {
            rst.push_back(src);
            return;
        }

        for (int i = n; i < src.size(); i++) {
            swap(src[n], src[i]);
            permutationRecurrent(src, n+1, rst);
            swap(src[n], src[i]);
        }
    }
};

int main() {
    vector<int> src {1, 2, 3, 4};
    vector<vector<int>> rst;
    Solution s = Solution();
    // s.permutation(src, rst);
    s.permutationRecurrent(src, 0, rst);
    for (int i=0; i < rst.size(); i++) {
        for (int j=0; j < rst[i].size(); j++) {
            cout << rst[i][j];
        }
        cout << endl;
    }
}
