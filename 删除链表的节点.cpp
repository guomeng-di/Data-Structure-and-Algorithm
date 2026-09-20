//https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* cur=dummy;
        while(cur->next){
            if(cur->next->val==val){
                cur->next=cur->next->next;
                break;
            }
            cur=cur->next;
        }
        return dummy->next;
    }
};
