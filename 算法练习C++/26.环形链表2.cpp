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
            //如果链表为空，或者只有一个节点的话，直接返回没有环

            //之所以有的代码会这样前面提前判断，是因为会用到一些head->next这些值，如果本身是空的，就要提前报错
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

