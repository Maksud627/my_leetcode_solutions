// 206. Reverse Linked List: https://leetcode.com/problems/reverse-linked-list/
// reverse linked list, easy


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
    approach1:
    1. traverse linked list and store values in a vactor
    2. now traverse from head and reassign values from the end of vectors
    3. delete the vector to optimize SC, return head
*/

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         vector<int> temp;

//         for(ListNode *curr = head; curr!=NULL; curr = curr->next){
//             temp.push_back(curr->val);
//         }

//         for(ListNode *curr = head; curr!=NULL; curr = curr->next){
//             curr->val = temp.back();
//             temp.pop_back();
//         }

//         temp.clear(); // free the vector
//         return head;
//     }
// };
// TC: O(n) as for traversing the list, SC: O(n) as .clear doesn't work practically for not destroying the vector 

/*
    approach2:
    1. 3 pointer approach, curr, prev, temp (to store the next pointer before breaking)
    2. set curr as head, prev as null and temp as curr->next
    3. for each traverse, store temp, link curr->next as prev, set prev as curr, move curr to temp (for next curr)
    4. repeat this until at one point curr will be NULL, then return the prev which will be reversed head.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *temp=NULL;

        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// TC: O(n) for traversing the whole list
// SC: O(1) as three pointers are used