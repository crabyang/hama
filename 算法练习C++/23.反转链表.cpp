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
////            //����ֻ��һ���ڵ㣬ֱ�ӷ��ؾͿ�����
////        }
////        ListNode* pointer1 = head;
////        ListNode* pointer2 = head;  //pointerָ����β��
////        
////        while (pointer2->next != nullptr) {
////            //->next != nullptr���ҵ����һ���ڵ㣬���Ǳ������нڵ�
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
//            ListNode* tmp = cur->next; // �ݴ��̽ڵ� cur.next
//            cur->next = pre;           // �޸� next ����ָ��
//            pre = cur;                 // pre �ݴ� cur
//            cur = tmp;                 // cur ������һ�ڵ�
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
//    ListNode* pointer = headA.next;  // pointer Ӧ��ָ������ĵ�һ����Ч�ڵ�
//    while (pointer != nullptr) {
//        cout << pointer->val;
//        pointer = pointer->next;
//    }
//
//    cout << "reverse!" << endl;
//
//    Solution s;
//    ListNode* ans = s.reverseList(headA.next);  // ��������ĵ�һ����Ч�ڵ�
//
//    ListNode* pointer2 = ans;  // pointer2 Ӧ��ָ��ת�������ͷ
//    while (pointer2 != nullptr) {
//        cout << pointer2->val;
//        pointer2 = pointer2->next;
//    }
//}
