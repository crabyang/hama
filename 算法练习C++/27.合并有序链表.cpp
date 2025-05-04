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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                //这里就是>的情况了
                p->next = p2;
                p2 = p2->next;
            }

            //答案指针p 一直都指向末端
            p = p->next;

        }


        if (p1 != nullptr) {
            p->next = p1;

        }

        if (p2 != nullptr) {
            p->next = p2;
        }



        return dummy->next;
    }
};