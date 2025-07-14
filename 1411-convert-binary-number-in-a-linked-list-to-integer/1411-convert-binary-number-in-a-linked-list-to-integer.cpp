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

ListNode* reverseLL(ListNode*head){
    ListNode*prev = nullptr;
    while(head){
        ListNode*nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}


    int getDecimalValue(ListNode* head) {
        head = reverseLL(head);

        int result = 0;
        int power = 0;
        while(head){
            if(head->val==1){
                result += pow(2,power);
            }
            power++;
            head = head->next;
        }
        return result;
    }

};