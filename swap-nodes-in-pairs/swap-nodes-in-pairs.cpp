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
    ListNode* swapPairs(ListNode* head) {
        
        vector < ListNode* > v_odds ;
        vector < ListNode* > v_evens ;
        
        int counter = 1 ;
        ListNode *current = head ;
        
        while( current != nullptr ){
            
            if( counter % 2 == 1 ) v_odds.push_back( current );
            else v_evens.push_back( current );
            
            current = current -> next ;
            counter ++ ;
            
        }
        
        if( counter <= 2 ) return head ;
        
        ListNode *last = nullptr ;
        
        if( v_odds.size() != v_evens.size() ){
            
            last = v_odds[v_odds.size()-1];
            v_odds.pop_back();
            
        }
        
        int size = v_odds.size() + v_evens.size() ;
        
        int odd_pointer = 0 , even_pointer = 1 ;
        
        ListNode *result = v_evens[0];
        current = result ;
        
        for ( int i = 1 ; i <= size - 1 ; i++ ){
            
            if( i % 2 == 1){
                current -> next = v_odds[ odd_pointer ++ ] ;
            }
            else {
                current -> next = v_evens[ even_pointer ++ ] ;
            }
            
            current = current -> next ;
            
        }
        
        current -> next = nullptr ;
        
        if( last != nullptr ){
            
            current -> next = last ;
            last -> next = nullptr ;
            
        }
        
        return result ;
    }
};