//https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
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
    vector<int> reverseBookList(ListNode* head) {
        ListNode* pre=nullptr,*next=nullptr;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        vector<int> arr;
        while(pre){
            arr.push_back(pre->val);
            pre=pre->next;
        }
        return arr;
    }
};
