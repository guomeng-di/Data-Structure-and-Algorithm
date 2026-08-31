//21. 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        //1特殊情况
        if(list1==nullptr||list2==nullptr)
          return list1==nullptr?list2:list1;
        //2确定头节点,需要固定(返回值)
        ListNode* head=list1->val<=list2->val?list1:list2;
        ListNode* pre=head;
        //3比较的当前节点
        ListNode* curr1=list1->val<=list2->val?list2:list1;
        ListNode* curr2=head->next;
        //4
        while(curr1!=nullptr&&curr2!=nullptr){
            if(curr1->val<=curr2->val){
                pre->next=curr1;
                curr1=curr1->next;
            }else{
                pre->next=curr2;
                curr2=curr2->next;
            }
            pre=pre->next;
        }
        pre->next=curr1==nullptr?curr2:curr1;
        return head;
    }
};
