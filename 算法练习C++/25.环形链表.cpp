#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            //�������Ϊ�գ�����ֻ��һ���ڵ�Ļ���ֱ�ӷ���û�л�

            //֮�����еĴ��������ǰ����ǰ�жϣ�����Ϊ���õ�һЩhead->next��Щֵ����������ǿյģ���Ҫ��ǰ����
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
                //ע�����fastһ������������fast->nextҲ��null��ʱ��Ҳ��������û�л�������

            }
            else
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }

        //�������ѭ���ˣ���˵��fast == slow�����ˣ�˵���л�
        return true;
    }
};