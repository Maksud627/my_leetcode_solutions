// 19. Remove Nth Node From End of List: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// linked list, two pointers, medium

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

/*
    approach:
    - get n, subtract from size of LL, that is the node from 0th node to delete
    - traverse before that node, if n=2 then (5-2) = 3, 2th->node-> next = 2th->node->next->next,
    - bascially skipping that node
    - return head of the list
*/
class Solution {
public:
    int lengthofLL(ListNode* head){
        int length = 0;
        ListNode *temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }    

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = lengthofLL(head);
        int index = length - n;
        // base case if given n is the size of the LL
        // that means need to delete the head (length - n) == 0
        // in that case point to the next of head
        if(index == 0) return head->next;

        ListNode *temp = head, *dummy = NULL;

        // traverse till that node and then skipping
        while(index) {
            dummy = temp;
            temp = temp->next;
            index--;
        }

        dummy->next = temp->next;
        return head;
    }
};


// this solution can be improved by two pointers, fast and slow, next try that