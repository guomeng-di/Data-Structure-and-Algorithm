//https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/
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
    int kthToLast(ListNode* head, int k) {
        ListNode* pre=nullptr,*next=nullptr;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        //return pre;
        k--;
        while(k--){
            pre=pre->next;
        }
        return pre->val;
    }
};
