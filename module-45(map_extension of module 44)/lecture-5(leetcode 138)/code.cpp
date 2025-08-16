class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
        Node* temp1 = head;
        Node* copy_head = new Node(temp1->val);
        temp1 = temp1 -> next;
        Node* temp2 = copy_head;
        while(temp1 != NULL){
            Node* to_append = new Node(temp1->val);
            temp2->next = to_append;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = head;
        temp2 = copy_head;
        unordered_map<Node*,Node*> m;
        //main head , copy head
        while(temp1 != NULL){
            m[temp1] = temp2;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        for(auto x : m){
            Node* main_tree_node = x.first;
            Node* copy_tree_node = x.second;
            if(main_tree_node -> random != NULL){
            copy_tree_node -> random =  m[main_tree_node -> random];
            }
        }
        return copy_head;
    }
};