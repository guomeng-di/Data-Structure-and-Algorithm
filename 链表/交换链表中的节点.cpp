//https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        //遍历链表,元素存入数组
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        //交换元素
        int n=arr.size();
        swap(arr[k-1],arr[n-k]);
        //3重建链表
        ListNode* cur=new ListNode(arr[0]);
        head=cur;
        for(int i=1;i<n;i++){
            cur->next=new ListNode(arr[i]);
            cur=cur->next;
        }
        return head;
    }
};
