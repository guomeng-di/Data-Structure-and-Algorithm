//2. 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr||l2==nullptr)
          return l1==nullptr?l2:l1;
        ListNode* ans=nullptr,*curr=nullptr;
        int cnt=0;
        for(int sum,val;
        l1!=nullptr||l2!=nullptr;
        l1=l1==nullptr?nullptr:l1->next,
        l2=l2==nullptr?nullptr:l2->next){
            sum=(l1==nullptr?0:l1->val)+(l2==nullptr?0:l2->val);
            val=(sum+cnt)%10;
            cnt=(sum+cnt)/10;
            if(ans==nullptr){
                ans=new ListNode(val);
                curr=ans;
            }else{
                curr->next=new ListNode(val);
                curr=curr->next;
            }
        }
        if(cnt==1) curr->next=new ListNode(1);
        return ans;
    }
};
