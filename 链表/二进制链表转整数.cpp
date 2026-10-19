//https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        //1链表反转
        ListNode* cur=nullptr,*next=nullptr;
        while(head){
            next=head->next;
            head->next=cur;
            cur=head;
            head=next;
        }
        //2 101=1*2 0+0*2 1+1*2 2
        int ans=0;
        int n=0;
        while(cur){
            ans+=cur->val*pow(2,n);
            n++;
            cur=cur->next;
        }
        return ans;
    }
};
