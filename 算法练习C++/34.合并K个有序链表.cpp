#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };


public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> heap;

        for (auto head : lists) {
            ListNode* p = head;
            while (p != nullptr) {
                heap.push(p);
                p = p->next;   //不要忘记推进指针
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;

        while (heap.empty() != true) {
            ListNode* cur = heap.top();
            heap.pop();
            ans->next = cur;
            ans = ans->next;   //不要忘记推进指针
        }

        return ans->next;


    }
};