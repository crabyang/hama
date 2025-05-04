//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <unordered_set>
//#include <string>
//using namespace std;
//
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
////class Solution {
////public:
////    ListNode* reverseList(ListNode* head) {
////
////        if (head == nullptr || head->next==nullptr || head->next->next == nullptr) {
////            return head;
////            //就是只有一个节点，直接返回就可以了
////        }
////        ListNode* pointer1 = head;
////        ListNode* pointer2 = head;  //pointer指链表尾部
////        
////        while (pointer2->next != nullptr) {
////            //->next != nullptr是找到最后一个节点，不是遍历所有节点
////            pointer2 = pointer2->next;
////        }
////        ListNode* pointer3 = head->next->next;
////
////        while (pointer1->next != pointer2) {
////            pointer3 = head->next->next;
////            pointer1->next->next = pointer2->next;
////            pointer2->next = pointer1->next;
////            pointer1->next = pointer3;
////            
////        }
////
////        return head;
////
////
////
////    }
////};
//
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* cur = head, * pre = nullptr;
//        while (cur != nullptr) {
//            ListNode* tmp = cur->next; // 暂存后继节点 cur.next
//            cur->next = pre;           // 修改 next 引用指向
//            pre = cur;                 // pre 暂存 cur
//            cur = tmp;                 // cur 访问下一节点
//        }
//        return pre;
//    }
//};
//
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
//    ListNode* pointer = headA.next;  // pointer 应该指向链表的第一个有效节点
//    while (pointer != nullptr) {
//        cout << pointer->val;
//        pointer = pointer->next;
//    }
//
//    cout << "reverse!" << endl;
//
//    Solution s;
//    ListNode* ans = s.reverseList(headA.next);  // 传入链表的第一个有效节点
//
//    ListNode* pointer2 = ans;  // pointer2 应该指向反转后的链表头
//    while (pointer2 != nullptr) {
//        cout << pointer2->val;
//        pointer2 = pointer2->next;
//    }
//}
