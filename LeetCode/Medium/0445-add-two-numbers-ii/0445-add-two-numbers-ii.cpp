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
        stack<int> s1,s2,s3;
        ListNode* temp1 = l1; ListNode* temp2 = l2;
        while(temp1){s1.push(temp1->val); temp1=temp1->next;}
        while(temp2){s2.push(temp2->val); temp2=temp2->next;}
        int carry = 0;
        while(s1.size() || s2.size()){
            int sum = carry;
            if(s1.size()){sum += s1.top(); s1.pop();}
            if(s2.size()){sum += s2.top(); s2.pop();}
            carry = sum/10;
            s3.push(sum%10);
        }
        if(carry>0){s3.push(carry);}
        ListNode* l3 = NULL; ListNode* t3 = l3;
        while(s3.size()){if(!l3){l3 = new ListNode(s3.top());t3 = l3;}
        else{t3->next = new ListNode(s3.top()); t3 = t3->next;} s3.pop();}
        return l3;
    }
};