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

    ListNode* findMid(ListNode* node){
        ListNode* slow=node;
        ListNode* fast=node;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* ReverseList(ListNode* node){
        if(node == nullptr)
            return nullptr;
        ListNode* prev = nullptr;
        while(node != nullptr){
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }

    void MergeList(ListNode* l1, ListNode* l2){
        while(l1 != nullptr && l2 != nullptr){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            l1 = l1_next;
            l2->next = l1;
            l2 = l2_next;
        }
    }

    void reorderList(ListNode* head) {
        /*
        step1: 找到中间结点
        step2: 后半段链表翻转
        step3: 前后两段链表合并
        */
        if(head == nullptr)
            return;

        // 找中间结点
        ListNode* node = head;
        ListNode* mid = findMid(node);
        ListNode* mid_next = mid->next;
        mid->next = nullptr;

        // 后半段链表翻转
        ListNode* mid_next_new = ReverseList(mid_next);
        MergeList(node, mid_next_new);
    }
};