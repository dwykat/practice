/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        if(head->next == nullptr)
            return true;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_prev = slow;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        bool is_ord = false;
        if(fast->next == nullptr)
            is_ord = true;

        // 找中间结点
        ListNode* mid = slow;
        ListNode* latter_node = mid->next;
        ListNode* former_end;
        if(is_ord){ // 如果是奇数,前半段取mid前一个
            former_end = slow_prev;
        }else{ // 偶数,前半段取mid
            former_end = mid;
        }
        if(former_end != nullptr)
            former_end->next = nullptr;

        // 前面in place头插
        ListNode* cur_node = head;
        ListNode* prev_node = nullptr;
        while(cur_node != nullptr){
            ListNode* next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }

        ListNode* former_node = prev_node;
        // 比较
        while(former_node != nullptr && latter_node != nullptr){
            if(former_node->val != latter_node->val)
                return false;
            former_node = former_node->next;
            latter_node = latter_node->next;
        }
        if(former_node == nullptr && latter_node == nullptr)
            return true;
        return false;
    }
};
