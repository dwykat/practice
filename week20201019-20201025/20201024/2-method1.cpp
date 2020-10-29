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
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        bool is_first = true;
        // 先按位计算，再用尾插法建表
        while(l1 != nullptr && l2 != nullptr){
            int left = l1->val;
            int right = l2->val;

            int sum = left + right + carry;
            if(sum >= 10){
                sum -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            if(is_first){
                cur->val = sum;
                is_first = false;
            }else{
                ListNode* tmp = new ListNode(0);
                tmp->val = sum;
                cur->next = tmp;
                cur = tmp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // 计算剩余位的值
        ListNode* left;
        bool skip = false;
        if(l1 != nullptr)
            left = l1;
        else if(l2 != nullptr)
            left = l2;
        else{
            skip = true;
        }
        while(!skip && left!=nullptr){
            int sum = left->val + carry;
            if(sum >= 10){
                sum -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode* tmp = new ListNode(0);
            tmp->val = sum;
            cur->next = tmp;
            cur = tmp;
            left = left->next;
        }
        if(carry != 0){
            ListNode* tmp = new ListNode(1);
            cur->next = tmp;
            cur = tmp;
        }
        cur->next = nullptr;
        return head;
    }
};
