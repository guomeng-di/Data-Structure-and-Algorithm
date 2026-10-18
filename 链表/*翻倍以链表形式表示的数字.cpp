//https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/
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
    ListNode* reverse(ListNode* head){
        ListNode* cur=nullptr,*next=nullptr;
        while(head){
            next=head->next;
            head->next=cur;
            cur=head;
            head=next;
        }
        return cur;
    } 
    ListNode* doubleIt(ListNode* head) {
        ListNode* q1=reverse(head);
        ListNode* q=q1;

        ListNode* last = nullptr; // 保存尾节点
        int carry=0;
        while(q){
            last=q;
            int val=q->val*2+carry;
            q->val=val%10;
            carry=val/10;
            q=q->next;
        }
        if(carry) last->next=new ListNode(carry);
        return reverse(q1);

    }
};
