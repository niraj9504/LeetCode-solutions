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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        k%=n;
        if(k==0)return head;
        k=(n-k);
        temp=head;
        while(k!=1){
            temp=temp->next;
            k--;
        }
        ListNode* newHead=temp->next;
        ListNode* x=newHead;
        while(x->next){
            x=x->next;
        }
        x->next=head;
        temp->next=NULL;
        head=newHead;
        return head;
    }
};