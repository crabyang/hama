#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> table;
        ListNode* pointer = headA;
        while (pointer != nullptr) {
            table.insert(pointer);
            pointer = pointer->next;

        }
        ListNode* pointer2 = headB;
        while (pointer2 != nullptr) {
            if (table.find(pointer2) != table.end()) {
                return pointer2;
            }
            pointer2 = pointer2->next;

        }

        return nullptr;
    }
};

//int main() {
//    vector<int> A = { 4,1 };
//    vector<int> B = { 5,6,1 };
//    ListNode headA(0);
//    ListNode headB(0);
//    ListNode a1(4);
//    ListNode a2(1);
//    ListNode c1(8);
//    ListNode c2(4);
//    ListNode c3(5);
//    ListNode b1(5);
//    ListNode b2(6);
//    ListNode b3(1);
//    headA.next = &a1;
//    a1.next = &a2;
//    a2.next = &c1;
//    c1.next = &c2;
//    c2.next = &c3;
//    headB.next = &b1;
//    b1.next = &b2;
//    b2.next = &b3;
//    b3.next = &c1;
//
//    ListNode* pointer = &headA;  //pointer是一个指针，不是一个节点，指向头结点
//    while (pointer != nullptr) {
//        cout << pointer->val;
//        pointer = pointer->next;
//
//    }
//
//    Solution s;
//    ListNode *ans = s.getIntersectionNode(&headA, &headB);
//    cout << ans->val;
//
//}