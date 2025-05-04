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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            //�������Ϊ�գ�����ֻ��һ���ڵ�Ļ���ֱ�ӷ���û�л�

            //֮�����еĴ��������ǰ����ǰ�жϣ�����Ϊ���õ�һЩhead->next��Щֵ����������ǿյģ���Ҫ��ǰ����
            return NULL;
        }
        ListNode* slow = head, * fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;

       

   

    }
};

