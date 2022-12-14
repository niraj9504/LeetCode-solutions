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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt<k)return head;
        temp=head;
        ListNode* prev=NULL,*curr=head,*nextptr;
        int count=0;
        while(count<k){
            nextptr=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nextptr;
            count++;
        }
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k);
        }
        return prev;
    }
};