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
    ListNode *insertEnd(ListNode *head, int val){
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr;
        ListNode *tempOne = list1;
        ListNode *tempTwo = list2;

        while(tempOne != NULL){
            arr.push_back(tempOne->val);
            tempOne = tempOne->next;
        }

        while(tempTwo != NULL){
            arr.push_back(tempTwo->val);
            tempTwo = tempTwo->next;
        }
        sort(arr.begin(),arr.end());
        ListNode *newHead = NULL;
        for(int i:arr){
            newHead = insertEnd(newHead,i);
        }

        return newHead;
    }
};
