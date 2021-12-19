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
        ListNode* result = new ListNode();
        ListNode* r = result ;
        ListNode* anchr ;
        int a,b,c = 0;
        while(1){
            if( l1 == nullptr )a = 0;
            else a = l1 -> val ;
            if( l2 == nullptr )b = 0;
            else b = l2 -> val ;
            c = a + b + c ;
            if( l1 != nullptr )
            l1 = l1 -> next ;
            if( l2 != nullptr )
            l2 = l2 -> next ;
            result -> val = c % 10 ;
            c = c / 10 ;
            result -> next = new ListNode();
            anchr = result ;
            result = result -> next ;
            if( l1 == nullptr && l2 == nullptr ) break ;
            
        }
        if( c == 0 ){
            delete result ;
            result = nullptr ;
            anchr -> next = nullptr ;
        }
        else {
            result -> val = c ;
        }
        return r ;
    }
};