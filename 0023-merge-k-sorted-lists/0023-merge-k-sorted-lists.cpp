/**
 * Definition for singly-linked list.
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Comparator class for min-heap
    class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap: smaller value has higher priority
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store ListNode pointers ordered by value
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push head of each list into the heap (if not null)
        for (ListNode* node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }

        // Dummy node to help build result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Extract smallest nodes from heap and build merged list
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next; // Return head of merged list
    }
};
