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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //答案附在l1上

        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* ans = dummyNode;


        while (p1 != nullptr && p2 != nullptr) {
            int A = p1->val;
            int B = p2->val;
            int curN = (A + B + carry)%10;
            carry = (A + B + carry) / 10;
            ans->next = new ListNode(curN);
            ans = ans->next;  //别忘记推进，已经好多题都忘记写这个东西了
            p1 = p1->next;
            p2 = p2->next;

      
        }

        while (p1 == nullptr && p2!=nullptr) {
            int B = p2->val;
            int curN = (B + carry) % 10;
            carry = (B + carry) / 10;
            ans->next = new ListNode(curN);
            p2 = p2->next;
            ans = ans->next;
        }

        while (p1 != nullptr && p2 == nullptr) {
            int A = p1->val;
            int curN = (A + carry) % 10;
            carry = (A + carry) / 10;
            ans->next = new ListNode(curN);
            p1 = p1->next;
            ans = ans->next;
        }

        if (p1 == nullptr && p2 == nullptr) {
            if (carry == 1) {
                ans->next = new ListNode(1);
                return dummyNode->next;
            }
            else
            {
                return dummyNode->next;
            }
        }

        return dummyNode->next;


    }
};

//int main() {
//    ListNode headA(2);
//    ListNode headB(5);
//    ListNode a1(4);
//    ListNode a2(3);
//
//    ListNode b1(6);
//    ListNode b2(4);
//
//    headA.next = &a1;
//    a1.next = &a2;
//
//    headB.next = &b1;
//    b1.next = &b2;
//    
//    Solution s;
//    ListNode* p1 = &headA;
//    ListNode* p2 = &headB;
//    s.addTwoNumbers(p1,p2);
//}
