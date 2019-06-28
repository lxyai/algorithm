#include<iostream>
#include<vector>

using namespace std;

public class TreeNode {
    public int val;
    public TreeNode left, right;
    public TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

class Solution {
public:
    vector<int> getNumber(string &data) {
        vector<int> ret;
        string tmpStr = "";
        data = data.substr(1, data.length()-2);
        for (int i = 0; i <= data.length(); i++) {
            if (data[i] == '#') {
                i += 1;
                ret.push_back(NULL);
                continue;
            }
            if (data[i] == ',' || data[i] == '\0') {
                int n = stoi(tmpStr);
                ret.push_back(n);
                tmpStr = "";
            } else {
                tmpStr += data[i];
            }
        }
        return ret;
    }

    string serialize(TreeNode root) {
        ostringstream out;
        queue<TreeNode> q;
        if (root) q.push(&root);
        out << '{';
        while (!q.empty()) {
            TreeNode t = q.front(); q.pop();
            if (t) {
               out << t.val << ',';
               q.push(t->left);
               q.push(t->right);
            } else {
                out << '#' << ',';
            }
        }
        return out.str();
    }
};

int main() {
    string data = "{3,9,20,#,#,15,7}";
    Solution s = Solution();
    vector<int> nums = s.getNumber(data);
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
