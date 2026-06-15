//2130. 链表最大孪生和

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
    int pairSum(ListNode* head) {
        ListNode* pre=head;
        vector<int> arr;
        int sum=INT_MIN;
        while(pre!=NULL){
            arr.push_back(pre->val);
            pre=pre->next;
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum=max(sum,arr[i]+arr[n-1-i]);
        }
        return sum;
    }
};
