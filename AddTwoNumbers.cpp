// 2. Add Two Numbers: https://leetcode.com/problems/add-two-numbers/description/
// linked list, Math, Recursion
// Tag: Medium

/*
approach:
-> store a dummyNode having head as -1 value
-> L1.data + L2.data -> push (sum % 10) value to new node -> store carry as (sum / 10)
-> if L1 && L2 == null, then if (carry != null) then push (carry) to new node
-> return dummyNode -> next, as this will be the head of the returned linked list
*/

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
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* currNode = dummyNode;
        int carry = 0;

        while(l1 != NULL || l2 != NULL){
            int sum = carry;

            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            carry = sum / 10;
            sum = sum % 10;
            
            currNode->next = new ListNode(sum);
            currNode = currNode->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry) { 
            currNode->next = new ListNode(carry);
            currNode = currNode->next;
        }
        
        return dummyNode->next;
    }
};