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
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummyNode = new ListNode(-1);

        dummyNode->next = head;
        ListNode* p1 = dummyNode;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;

        while (p1 != nullptr && p2 != nullptr) {
            //这里是按序处理每一个next指针，要防止出现节点丢失
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            

            //推进指针
            p1 = p2;
            if (p2->next != nullptr) {
                p2 = p2->next;  //这是一个简单的思路，在邻接情况会出现错误，那么就在执行前先判断
            }
            else
            {
                break;
            }
            
            if (p2->next != nullptr) {
                p3 = p2->next;
            }
            else
            {
                break;
            }
            



        }

        ListNode* ans = dummyNode->next;
        delete dummyNode;
        return ans;

    }
};

