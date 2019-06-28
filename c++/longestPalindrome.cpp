#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution {
public:
    string findLongestPalindrome(string data) {
        if (data.empty()) return NULL;
        vector<vector<bool> > p;
        int start, longest;
        int length = data.length();
        
        for (int i = 1; i < length; i++) {
            p[i][i] = true;
            if (data[i] == data[i+1] && i < length-1) {
                p[i][i+1] = true;
                start = i;
                longest = 2;
            }
        }
        for (int len = 3; len < length; len++) {
            for (int i = 0; i < length - len; i++) {
                int j = i + len - 1;
                if (p[i+1][j-1] && data[i] == data[j]) {
                    p[i][j] = true;
                    start = i;
                    longest = len;
                }
            }
        }
        if (longest >= 2) {
            return data.substr(start, start+longest+1);
        }
        return NULL;
    }
};

int main() {
    string data = "hiehgabccbaennni";
    solution s = solution();
    string rst = s.findLongestPalindrome(data);
    cout << rst << endl;
    return 0;
}
