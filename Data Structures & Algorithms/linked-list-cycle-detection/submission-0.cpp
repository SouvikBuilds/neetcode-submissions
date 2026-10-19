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
    bool isEmpty(ListNode *head){
        return head == NULL;
    }
    bool hasCycle(ListNode* head) {
        if(isEmpty(head)) return false;
        ListNode *temp = head;
        vector<ListNode *>adress;

        while(temp != NULL){
            ListNode *curr = temp;
            for(int i = 0; i<adress.size(); i++){
                if(adress[i] == curr){
                    return true;
                }
            }
            adress.push_back(temp);
            temp = temp->next;
        }

        return false;
    }


};
