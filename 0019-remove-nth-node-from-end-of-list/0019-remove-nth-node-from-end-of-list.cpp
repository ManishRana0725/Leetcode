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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* node = head;
        
        int size = 0;
        while(node != NULL){
            size++;
            node = node->next;
        }
        cout<<size;

        int kth = size - n +1;
        if(n == size){
            return head->next;
        }
        ListNode* newhead = head;
        node = newhead;
        ListNode* prev = NULL;
        int count = 1;
        while(count != kth){
            prev = node;
            node = node->next;
            count++;
        }
        prev->next = node->next;

        return newhead;

    }
};