/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int st, int end) {
        if (st == end)
            return lists[st];

        int mid = st + (end - st) / 2;
        ListNode* left = mergeSort(lists, st, mid);
        ListNode* right = mergeSort(lists, mid + 1, end);

        return merge(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        return mergeSort(lists, 0, lists.size() - 1);
    }
};