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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)return nullptr;
        ListNode* current = head ;
        vector<ListNode*>dup;
        while(current != nullptr){
            dup.push_back(new ListNode(current->val));
            current = current->next;
        }
        vector<ListNode*>lt;
        for(auto item : dup){
            if(item->val < x)lt.push_back(item);
        }
        vector<ListNode*>gt;
        for(auto item : dup){
            if(item->val >= x)gt.push_back(item);
        }
        vector<ListNode*>answer;
        answer.insert(answer.end(),lt.begin(),lt.end());
        answer.insert(answer.end(),gt.begin(),gt.end());
        for(int i=1;i<answer.size();i++){
            answer[i-1]->next = answer[i]; 
        }
        return answer[0];
    }
};