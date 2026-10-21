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
    ListNode* reverseList(ListNode* head) {
        // Time complexity: O(n)
        // Space complexity O(1)
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;

        while(head != nullptr){
            temp = head -> next; // Save next node dir
            head -> next = prev; // Save previous dir
            prev = head;
            head = temp; // Update current ListNode
        }
        return prev;
    }
};
