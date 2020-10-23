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
    void reorderList(ListNode* head) {
        /*
        利用数组的索引直接重排,
        第一个接最后一个,
        最后一个再接原第二个,
        原第二个再接原倒数第二
        ......
        */
        if(head == nullptr)
            return;
        vector<ListNode*> vec;
        while(head){
            vec.push_back(head);
            head = head->next;
        }
        int i=0, j=vec.size()-1;
        while(i<j){
            vec[i]->next = vec[j];
            i++;
            if(i==j)
                break;
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next=nullptr;
    }
};