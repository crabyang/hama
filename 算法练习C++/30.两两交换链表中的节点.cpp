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
            //�����ǰ�����ÿһ��nextָ�룬Ҫ��ֹ���ֽڵ㶪ʧ
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            

            //�ƽ�ָ��
            p1 = p2;
            if (p2->next != nullptr) {
                p2 = p2->next;  //����һ���򵥵�˼·�����ڽ��������ִ�����ô����ִ��ǰ���ж�
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

