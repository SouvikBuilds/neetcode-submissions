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
    ListNode *insertEnd(ListNode * head,int val){
        ListNode *newNode = new ListNode(val);
        if(isEmpty(head)) return newNode;
        ListNode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(isEmpty(head) || isEmpty(head->next)) {
            return NULL;
        }
        vector<int>nodes;
        ListNode *temp = head;
        while(temp != NULL){
            nodes.push_back(temp->val);
            temp = temp->next;
        }

        nodes.erase(nodes.begin()+(nodes.size()-n));

        ListNode *newHead = NULL;
        for(int i:nodes){
            newHead = insertEnd(newHead,i);
        }

        return newHead;
    }

    
};
