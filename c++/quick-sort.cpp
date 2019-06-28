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
    
    void sort(vector<int> &src, int left, int right) {
        if (left >= right) return;
        
        int i, j, pivot;
        i = left;
        j = right;
        pivot = src[left];
        while(i != j) {
            while (src[j] >= pivot && i < j) j--;

            while (src[i] <=pivot && i < j) i++;

            if (i < j) swap(src[i], src[j]);
        }
        swap(src[left], src[i]);
        sort(src, left, i - 1);
        sort(src, i + 1, right);
        return;
    }
};

int main() {
    vector<int> src = {4, 2, 8, 3, 1};
    Solution s = Solution();
    s.sort(src, 0, src.size()-1);
    for (int i=0; i < src.size(); i++) {
        cout << src[i];
    }
    cout << endl;
}
