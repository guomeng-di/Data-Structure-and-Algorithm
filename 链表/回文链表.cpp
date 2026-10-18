//https://leetcode.cn/problems/aMhZSa/
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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        int n=0;
        while(head){
            int num=head->val;
            arr.push_back(num);
            n++;
            head=head->next;
        }
        for(int i=0;i<n/2;i++){
            if(arr[i]!=arr[n-i-1]) return 0;
        }
        return 1;
    }
};
