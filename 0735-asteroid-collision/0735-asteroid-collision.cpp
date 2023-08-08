class Solution {
           
struct MyListNode{
    int val;
    bool pos;
    MyListNode* next;
    MyListNode* prev;
    MyListNode() : next(NULL), prev(NULL){}; 
    MyListNode(int val, bool pos) : val(val), pos(pos), next(NULL), prev(NULL){};
};

public:
    vector<int> asteroidCollision(vector<int>& a) {
        // Encounter smallest + - first.

        MyListNode *head = new MyListNode(0, false);        
        MyListNode* curr = head;

        int n = a.size();

        for(int i = 0; i < n; ++i) {
            MyListNode *node = new MyListNode(abs(a[i]), a[i] > 0);
            curr -> next = node;
            node -> prev = curr;
            curr = node;
        }

        MyListNode *tail = new MyListNode(0, true);
        curr -> next = tail;
        tail -> prev = curr;

        curr = head;
        while(curr != tail) {
            // We need to go back if this operatons leads a neg
            // and we have atlest 1 pos behind.
            // else if prev is negative we go forward.
            if(curr -> pos) {
                // cout << (curr == tail) << " ";
                auto nextNode = curr -> next;
                if(nextNode -> pos) {
                    curr = nextNode;
                } 
                else {
                    if(nextNode -> val == curr -> val) {
                        auto prevNode = curr -> prev;
                        auto delete1 = curr;
                        auto delete2 = curr -> next,
                        nextNode = delete2 -> next;
                        prevNode -> next = nextNode;
                        nextNode -> prev = prevNode; 
                        curr = prevNode;
                        delete(delete1);
                        delete(delete2);
                    }else if(nextNode -> val > curr -> val){
                        auto prevNode = curr -> prev;
                        prevNode -> next = nextNode;
                        nextNode -> prev = prevNode;
                        auto to_delete = curr;
                        if(prevNode -> pos) curr = curr -> prev;
                        else curr = curr -> next;
                        delete(to_delete);
                    } else {
                        auto to_delete = nextNode;
                        nextNode = nextNode -> next;
                        curr -> next = nextNode;
                        nextNode -> prev = curr;
                        // explore current once again.
                    }
                }
            }
            // Simple go forward if the node is negative.
            else {
                curr = curr -> next;
            }             
        }
        vector<int> ans;
        curr = head -> next;
        while(curr != tail) {
            int value = curr -> pos ? curr -> val : -curr -> val;
            ans.push_back(value);
            curr= curr -> next;
        }
        return ans;
        

    }
};