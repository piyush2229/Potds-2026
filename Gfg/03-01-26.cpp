/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        Node*dummy=new Node(0);
        Node* temp=dummy;
        Node* curr=root;
        priority_queue<int, vector<int>, greater<int>>pq;
        while(curr){
            Node* temp1=curr;
            while(temp1){
                pq.push(temp1->data);
                temp1=temp1->bottom;
            }
            curr=curr->next;
        }
        while(!pq.empty()){
            Node* newnode=new Node(pq.top());
            pq.pop();
            temp->bottom=newnode;
            temp=temp->bottom;
        }
        return dummy->bottom;
    }
};
// Time Complexity: O(N log N) where N is the total number of nodes in the linked list
// Space Complexity: O(N) for the priority queue and the new linked list