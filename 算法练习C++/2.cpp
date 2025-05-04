#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> hash;
        for (const string& s : strs) {
            string s_sorted = s;
            sort(s_sorted.begin(), s_sorted.end());

            if (hash.find(s_sorted) != hash.end())
            {
                hash[s_sorted].push_back(s);

            }
            else
            {
                hash[s_sorted].push_back(s);
            }

        }

        vector<vector<string>> ans;
        for (const auto& pair : hash) {
            ans.push_back(pair.second);
        }

        return ans;


    }
};

//#ifdef Main2
//int main() {
//    Solution solution;
//    vector<string> e = { "eat","tea","tan","ate","nat","bat" };
//    vector<vector<string>> ans = solution.groupAnagrams(e);
//    for (const vector<string>& s : ans) {
//        cout << '/n' << "新的一行" << endl;
//        for (const auto& ss : s) {
//            cout << ss << '/t';
//        }
//
//    }
//}
//#endif
