class Node{
public:
    int val = INT_MAX;
    int minimum = INT_MAX;
    Node* next = nullptr;

    Node(int t_val, Node* t_next){
        val = t_val;
        if(t_next){
            minimum = min(t_val, t_next->minimum);
        } else {
            minimum = t_val;
        }
        next = t_next;
    }
};

class MinStack {
public:

    Node* head = nullptr;

    MinStack() {
    }
    
    void push(int val) {
        head = new Node(val, head);
        cout << "cur val " << head->val << " cur min: " << head->minimum << endl;
    }
    
    void pop() {
        head = head->next;
    }
    
    int top(){
        return head->val;
    }
    
    int getMin() {
        return head->minimum;
    }

};