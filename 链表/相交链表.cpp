//https://leetcode.cn/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A=headA,*B=headB;
        while(A!=B){
            A=A==nullptr?headB:A->next;
            B=B==nullptr?headA:B->next;
        }
        return A;
    }
};
//没有交点时，A、B最终会同时变成nullptr，满足A == B，循环退出,返回nullptr
