#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    //void dfs_helper(vector<int>& candidates, int curNum,vector<int> container) {


    //    //�����candidates�Ѿ���ϴ����
    //    for (int i = 0; i < candidates.size(); i++) {
    //        //if (candidates[i] > curNum) {
    //        //    return;  //��֦     //return ��ʹ������ѭ��������������Ҫ������ģ�����˵������Ǵ��ڵ�ʱ��ִ���κβ����Ϳ�����
    //        //}
    //        
    //        if (candidates[i] == curNum) {
    //            container.push_back(candidates[i]);  //��ʱ��Ϳ���ֱ��ת��
    //            ans.push_back(container);  //ת���
    //            container.pop_back();  //Ҳ�൱���ǻ�����
    //        }

    //        if (candidates[i] < curNum) {
    //            container.push_back(candidates[i]);
    //            dfs_helper(candidates, curNum-candidates[i], container);
    //            container.pop_back();
    //        }
    //    }
    //}


    void dfs_helper(vector<int>& candidates, int curNum, vector<int> container, int index) {
        if (curNum == 0) {
            ans.push_back(container);
            return;
        }

        if (curNum < 0) {
            return;
        }

        //�����candidates�Ѿ���ϴ����
        for (int i = index; i < candidates.size(); i++) {
               container.push_back(candidates[i]);
               dfs_helper(candidates, curNum - candidates[i], container, i);
               container.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //��ȥ��candidates�д��������target��������Ϊcandidates��û�и����ģ����ڵ��ھ�ֱ���д���
        
        for (size_t i = candidates.size()-1; i >0 ; i--)   //ע��������ΪҪɾ�����ݣ�����˵�Ƿ������
        {
            if (candidates[i] == target)
            {
                ans.push_back({ target });
                candidates.erase(candidates.begin()+i);
                continue;  //ʹ��continue������ѭ������ǰ��������ִ���ˣ�����Ķ�ֱ��������
            }

            if (candidates[i] > target) {
                candidates.erase(candidates.begin() + i);
            }
        }

        sort(candidates.begin(), candidates.end());
        //Ҫ����


        vector<int> container;

        dfs_helper(candidates, target, container,0);
        return ans;


    }
};

//int main() {
//    Solution s;
//    vector<int> test = { 2,9,3,6,7,8};
//
//
//    vector<vector<int>> ans = s.combinationSum(test, 7);
//
//    cout << "jieshu";
//
//
//}