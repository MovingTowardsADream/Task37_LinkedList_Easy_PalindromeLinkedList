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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return 1;
        }
        ListNode* first = head;
        head = middleNode(head);
        ListNode* reverse = reverseList(head->next);
        head->next = NULL;
        int tmp1, tmp2;
        while (reverse != NULL && first != NULL) {
            tmp1 = reverse->val;
            tmp2 = first->val;
            if (tmp1 != tmp2) {
                return 0;
            }
            first = first->next;
            reverse = reverse->next;
        }
        return 1;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;
        int len = 0;
        while (tmp) {
            tmp = tmp->next;
            len++;
        }
        len /= 2;
        tmp = head;
        for (int i = 0;i < len - 1;i++) {
            tmp = tmp->next;
        }
        return tmp;
    }

    ListNode* reverseList(ListNode* right) {
        if (right == NULL || right->next == NULL) {
            return right;
        }
        ListNode* left = NULL;
        ListNode* tmp;
        while (right->next) {
            tmp = left;
            left = right;
            right = right->next;
            left->next = tmp;
        }
        right->next = left;
        return right;
    }
};