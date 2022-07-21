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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int l=left-1,r=right-1;
        vector<ListNode*>dup;
        ListNode* current = head ;
        while(current != nullptr){
            dup.push_back(new ListNode(current->val));
            current = current -> next;
        }
        reverse(dup.begin()+l,dup.begin()+r+1);
        for(int i=1;i<dup.size();i++){
            dup[i-1]->next = dup[i];
        }
        return dup[0];
    }
};