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
            //如果链表为空，或者只有一个节点的话，直接返回没有环

            //之所以有的代码会这样前面提前判断，是因为会用到一些head->next这些值，如果本身是空的，就要提前报错
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
                //注意这里，fast一次走两个，当fast->next也是null的时候也代表链表没有环！！！

            }
            else
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }

        //如果跳出循环了，就说明fast == slow存在了，说明有环
        return true;
    }
};