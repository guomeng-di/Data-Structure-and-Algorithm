2095. 删除链表的中间节点
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
    ListNode* deleteMiddle(ListNode* head) {
        //遍历一次获取长度
        int n=0;
        ListNode* pre=head;
        ListNode* ans=head;
        while(pre!=NULL){
            n++;
            pre=pre->next;
        }
        if(n==1){
            head=head->next;
            return head;
        }
        pre=head;
        for(int i=0;i<n/2;i++){
            ans=pre;
            pre=pre->next;
        }
        ans->next=pre->next;
        return head;
    }
};
//ans 只是一个指针变量，不是新节点，它并没有新建链表节点，只是存储了某个节点的内存地址，所以它指向谁，就操作原链表的哪个节点
