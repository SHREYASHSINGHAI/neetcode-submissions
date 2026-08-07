/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node* , Node*> m;
        Node* newHead = new Node(head->val);
        Node* newtemp = newHead;
        Node* oldtemp = head->next;
        while(oldtemp !=NULL){
            Node* copyNode=new Node(oldtemp->val);
            newtemp ->next = copyNode;
            newtemp = newtemp->next;
            oldtemp = oldtemp->next;
        }
        oldtemp = head;
        newtemp=newHead;
        while(oldtemp != NULL){
            m[oldtemp]=newtemp;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp=newHead;
        while(newtemp != NULL){
            newtemp->random=m[oldtemp->random];
            newtemp=newtemp->next;
            oldtemp= oldtemp->next;
        }

        return newHead;
    }
};
