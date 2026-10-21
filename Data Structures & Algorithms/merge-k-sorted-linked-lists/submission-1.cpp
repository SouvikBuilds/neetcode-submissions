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
    ListNode* insertEnd(ListNode* head, ListNode*& tail, int val) {
        ListNode* newNode = new ListNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return head;
        }

        tail->next = newNode;
        tail = newNode;

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>result;
        if(lists.size() == 0) return NULL;
        for(int i = 0; i<lists.size(); i++){
            ListNode *temp = lists[i];
            while(temp != NULL){
                result.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(result.begin(),result.end());
        ListNode *newHead = NULL;
        ListNode *tail = NULL;
        for(int i:result){
            newHead = insertEnd(newHead,tail,i);
        }

        return newHead;
    }
};
