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
    void reorderList(ListNode* &head) {
        if(isEmpty(head) || isEmpty(head->next)) return;
        vector<int>nodes;
        ListNode *temp = head;

        while(temp != NULL){
            nodes.push_back(temp->val);
            temp = temp->next;
        }

        int low = 0;
        int high = nodes.size()-1;
        vector<int>result;
        while(low<=high){
            result.push_back(nodes[low]);
            if(low != high){
                result.push_back(nodes[high]);
            }
            low++;
            high--;
        }
        ListNode *newHead = NULL;
        for(int i:result){
            newHead = insertEnd(newHead,i);
        }

        head = newHead;

    }
};
