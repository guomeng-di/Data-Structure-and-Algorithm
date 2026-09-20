//https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        if(!(l1&&l2)) return l1==nullptr?l2:l1;
        ListNode* head=nullptr,*curr=head;
        while(l1&&l2){
            int val1=l1->val,val2=l2->val;
            if(val1<=val2){
                if(!head){
                    head=l1;
                    curr=head;
                }
                else {
                    curr->next=l1;
                    curr=curr->next;
                }
                l1=l1->next;
            }else{
                if(!head){
                    head=l2;
                    curr=head;
                }
                else {
                    curr->next=l2;
                    curr=curr->next;
                }
                l2=l2->next;
            }

        }

        if(curr) curr->next=l1==nullptr?l2:l1;

        return head;
    }
};
