//多练习
//https://leetcode.cn/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //1统计链表长度,元素放入数组
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        //2计算要分成几部分
        int n=arr.size();
        int size=n/k;
        int num=n%k;
        //3放入ans
        vector<ListNode*> ans(k);
        
        int cnt=0;
        for(int i=0;i<k;i++){
            int q=num==0?(size):(size+1);
            // q等于0代表这一段为空，直接赋值nullptr，不新建节点
            if(q == 0){
              ans[i] = nullptr;
              continue;
            }
            if(num>0) num--;
            ListNode* head=new ListNode(arr[cnt++]);
            q--;
            ListNode* cur=head;
            while(q--){
                cur->next=new ListNode(arr[cnt++]);
                cur=cur->next;
            }

            ans[i]=head;
        }
        return ans;
    }
};
