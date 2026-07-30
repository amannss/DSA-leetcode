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
typedef pair< int , ListNode* > p ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL  ; int n = lists.size() ;
        priority_queue< p, vector<p>  , greater<p>> pq; 
        for(int i =0 ;i<n;i++)
        {   
            ListNode* x = lists[i] ;

            if(x!=NULL)
            pq.push({x->val , x }) ;// pushing first value of eaach row 
        }
        ListNode* temp ;
        while(!pq.empty())
        {   
            p tops = pq.top() ;pq.pop() ;
            ListNode* curr = tops.second ;
            if(head ==NULL)
            {
                head = curr; 
            }
            else temp->next = curr ;
            temp= curr ;
            ListNode* next = curr->next ;
            if(next!=NULL) pq.push({next -> val , next }) ;
        }
        return head ;
    }
};