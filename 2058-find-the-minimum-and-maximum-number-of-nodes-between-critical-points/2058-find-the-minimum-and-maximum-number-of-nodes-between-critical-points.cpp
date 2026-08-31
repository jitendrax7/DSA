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
    bool iscritical(ListNode* prev , ListNode* curr){
        return (curr->val<prev->val && curr->val<curr->next->val ) || 
            (curr->val>prev->val && curr->val>curr->next->val);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int stcritical = -1;            // start critical  point in list 
        int prevcritical = -1;          // just prev critical  point to a curr iterate idx or critical  point 

        ListNode* prev = head;          // prev node   
        ListNode* curr = head->next;   // curr node to iterate 

        int minDistance = INT_MAX;     // min distance of two cretical point    
        int maxDistance = INT_MIN;     // max distance of two cretical point 

        int idx = 1;                   // 1 based index of list 
        while(curr && curr->next){
            idx++;
            if(iscritical(prev,curr)){
                if(stcritical==-1 && prevcritical==-1){
                    stcritical = idx;
                    prevcritical = idx;
                }else{
                    minDistance = min(minDistance, idx-prevcritical);
                    maxDistance = max(maxDistance, idx-stcritical);

                    prevcritical = idx;
                }
            }

            prev = curr;
            curr = curr->next;
        }

        minDistance = minDistance==INT_MAX?-1:minDistance;
        maxDistance = maxDistance==INT_MIN?-1:maxDistance;

        return {minDistance,maxDistance};
    }
};