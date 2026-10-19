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

    ListNode *insertEnd(ListNode *head,int val){
        ListNode *temp = new ListNode(val);
        if(isEmpty(head)) return temp;
        ListNode *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        ptr->next = temp;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(isEmpty(head)) return NULL;
        vector<int>arr;
        ListNode *temp = head;
        while(temp!= NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        reverse(arr.begin(),arr.end());
        ListNode *newHead = NULL;
        for(int i:arr){
            newHead = insertEnd(newHead,i);
        }

        return newHead;

    }
};
