https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
# 自己做:  
数组下标  
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }
        int n_=arr.size();
        int sign_index=n_-n;

    ListNode* ans=nullptr,*curr=nullptr;
    for(int i=0;i<n_;i++){
        if(i==sign_index) continue;
        if(ans==nullptr){
            ans=new ListNode(arr[i]);
            curr=ans;
        }else{
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
    }
    return ans;
    }

};
```
# 进阶:
```
思路:
1. 怎么知道倒数第N个节点在哪里?
法1:数组下标
法2:指针移动2次
法3:双指针
思路:在最初就有指针1(left)和指针2(right)相距N -- 不难实现,让right先右移N+1即可
两者同步右移
当right到达队尾时,left就在倒数N+1处,下一个就是要删除的节点

2. 那万一我们想删除最后1个节点呢(一共N个),你怎么右移N+1位呢?
方法:引入 哨兵节点
具体来讲,在最左边,放入哨兵节点,起保护作用.并且,解决了N+1的问题.  

后续:如果遇到需要删除头节点的题目，添加哨兵节点可以简化代码逻辑
```
代码实现:  
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //创建哨兵节点简化代码
        ListNode dummy{0,head};
        //双指针
        ListNode* left=&dummy;
        ListNode* right=&dummy;

        //初始,right右移n
        while(n--){
            right=right->next;
        }
        //左右并行
        while(right->next){
            left=left->next;
            right=right->next;
        }
        //left下一个即为要删除的节点
        ListNode* delete_=left->next;
        left->next=delete_->next;
        delete delete_;
        return dummy.next;
    }
};
```
