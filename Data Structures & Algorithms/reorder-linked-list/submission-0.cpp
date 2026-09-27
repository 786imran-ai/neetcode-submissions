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
    void reorderList(ListNode* head) {
        if(!head && !head->next) return;
        // step 1 middle
        ListNode *slow= head;
        ListNode *fast= head;
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        // step 2 reverse second half
        ListNode *second=slow->next;
        slow->next=NULL;
        ListNode *prev=NULL;
        while(second){
            ListNode *temp= second->next;
            second->next= prev;
            prev= second;
            second= temp;
        }
        // step 3 is to merge 
        ListNode *first=head;
        second= prev;
        while(second){
            ListNode *tmp1= first->next;
            ListNode *tmp2= second->next;
            first->next= second;
            second->next= tmp1;
            first=tmp1;
            second=tmp2;
        }
    }
};
