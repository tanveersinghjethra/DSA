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
    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {

            // Find the kth node
            ListNode* kthNode = temp;
            for (int i = 1; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }

            // If less than k nodes remain, stop
            if (kthNode == nullptr) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            // Save next group's starting node
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = nullptr;

            // Reverse current group
            ListNode* newHead = reverse(temp);

            // Connect with previous group
            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            // Current temp becomes the last node after reversal
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};