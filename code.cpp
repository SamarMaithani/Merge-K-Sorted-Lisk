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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            ListNode* temp =new ListNode(-1);
            ListNode* head =new ListNode;
            head=temp;
            while(ans!=NULL && lists[i]!=NULL)
            {
                if(ans->val > lists[i]->val)
                {
                    temp->next = lists[i];
                    lists[i]=lists[i]->next;
                }
                else
                {
                    temp->next = ans;
                    ans=ans->next;
                }
                temp=temp->next;
            }
            while(lists[i]!=NULL)
            {
                temp->next = lists[i];
                lists[i]=lists[i]->next;
                temp=temp->next;
            }
            while(ans!=NULL)
            {
                temp->next=ans;
                ans=ans->next;
                temp=temp->next;
            }
            ans=head->next;
        }
        return ans;
    }
};
