https://leetcode.cn/problems/merge-k-sorted-lists/

# 自己做:  
思路:  
将链表所有数据存入数组arr,sort排序后创建新的链表  
```c++
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                arr.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }

        if(arr.empty()) return nullptr;

        sort(arr.begin(),arr.end());

        ListNode* head=new ListNode(arr[0]);
        ListNode* curr=head;
        int cnt=1;
        while(cnt<arr.size()){
            curr->next=new ListNode(arr[cnt]);
            curr=curr->next;
            cnt++;
        }
        return head;
    }
};
```
# 进阶:

