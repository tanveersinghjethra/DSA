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
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* fast = head;
        ListNode* temp = head;
        ListNode* slow = head;

        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        int mid = length / 2;

        for (int i = 0; i < mid; i++) {
            slow = slow->next;
        }

        return slow;
    }
};