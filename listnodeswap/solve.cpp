//runtime: 0ms.   撒花庆祝ing
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        else {
            if(head->next==NULL)
                return head;
            ListNode *prehead=new ListNode(-1);
            prehead->next=head;
            ListNode *left=prehead;
            ListNode *middle=head;
            ListNode *right=head->next;
            while(middle!=NULL&&middle->next!=NULL){
                middle->next=right->next;
                left->next=right;
                right->next=middle;
                
                left=middle;
                middle=middle->next;
                if(middle!=NULL)
                    right=middle->next;
            }
            return prehead->next;
        }
        
    }
};
