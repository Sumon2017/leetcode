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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0 ;
        ListNode *current = head ;
        while( current != nullptr ){
            count ++ ;
            current = current -> next ;
        }
        if( count == n ){
            return head -> next ;
        }
        int el = count - n + 1 ;
        int steps = el -2 ;
        ListNode *preNode = head ;
        for ( int i = 1 ; i <= steps ; i ++ ){
            preNode = preNode -> next ;
        }
        if( n == 1 ){
            preNode -> next = nullptr ;
        }
        else{
            preNode -> next = preNode -> next -> next ;
        }
        return head ;
    }
};