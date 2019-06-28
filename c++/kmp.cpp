#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
    Solution() {}
    
    vector<int> next;

    void makenext(string s) {
            int n = s.length();
            for (int i=0; i < n; i++) next.push_back(0);

            for (int i=1, j=0; i < n; i++) {
                    while (j > 0 && s[i] != s[j]) j = next[j-1];

                    if (s[i] == s[j]) j++;

                    next[i] = j;
            }

    }

    int strStr(string src, string target) {
        int m = src.length();
        int n = target.length();
        int rst = 0;
        if (n == 0) return 0;
        
        for (int i, j=0; i < m; i++) {
            while (j > 0 && src[i] != target[j]) j = next[j-1];

            if (src[i] == target[j]) j++;

            if (j == n) {
               rst = i - n + 1;
               break;
            }
        }
        return rst;
    }
};

int strStr_test(string &source, string &target) {
    int m = source.length();
    int n = target.length();
    vector<int> next;
    int k = 0;
    for (int i = 0; i < n; i++) {
        next.push_back(0);
    }

    for (int i = 1; i < n; i++) {
        while (k > 0 && target[i] != target[k]) k = next[k-1];

        if (target[i] == target[k]) k++;

        next[i] = k;
    }

    int rst = -1;

    for (int i=0, j=0; i < m; i++) {
        while (j > 0 && source[i] != target[j]) j = next[j-1];

        if (source[i] == target[j]) j++;

        if (j == n) {
           rst = i - n + 1;
           break;
        }
    }
    return rst;
}

int main() {
    string target = "ABCDABD";
    string source = "BBCABCDABABCDABCDABDE";
    Solution s = Solution();
    s.makenext(target);
    int index = s.strStr(source, target);
    index = strStr_test(source, target);
    cout << index << endl;
    return 0;
}
