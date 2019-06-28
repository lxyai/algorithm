#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
  private:
    vector<int> result;

  public:
    vector<int> FindAnagram(string s, string p)
    {
        vector<int> vs(26, 0);
        vector<int> vp(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            vp[p[i] - 'a']++;
        }
        for (int j = 0; j < s.size(); j++)
        {
            if (j >= p.size())
            {
                vs[s[j - p.size()] - 'a']--;
            }
            vs[s[j] - 'a']++;
            if (vs == vp)
            {
                result.push_back(j - p.size() + 1);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str_s = "cbaebabacd";
    string str_p = "abc";
    vector<int> result;
    solution *slove = new solution();
    result = slove->FindAnagram(str_s, str_p);
    for (int i=0;i<result.size();i++){
        cout<<"result:"<<result[i]<<endl;
    }
    return 0;
}
