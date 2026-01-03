/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        unordered_set<Node*>mpp;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1){
            mpp.insert(temp1);
            temp1=temp1->next;
        }
        while(temp2){
            if(mpp.count(temp2)) return temp2;
            temp2=temp2->next;
        }
        return nullptr;
    }
};
// Time Complexity: O(N + M) where N and M are the lengths of the two linked lists
// Space Complexity: O(N) where N is the length of the first linked list
