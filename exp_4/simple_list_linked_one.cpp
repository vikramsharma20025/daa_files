#include <iostream>
#include <stack>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            data = value;
            next = NULL;
        }
};
void insert_at_head(Node*& head,int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

int linked_length(Node* head,int count = 0){
    Node* temp = head;
    if(temp!=NULL){
        count = count + 1;
    }
    return linked_length(temp->next,count);
}



void insert_after_this(Node*& head,int val,int key){
    Node* n = new Node(val);
    if(head->data == key){
        n->next = head->next;
        head->next = n;
        return;
    }
    Node* temp = head;
    while (temp->data!=key){
        temp = temp->next;
        if(temp->next==NULL){
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}

void delete_the_linked_list(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        Node* to_delete = temp;
        temp = temp->next;
        delete temp;
    }
}

void insert_at_tail(Node*& head,int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void print_list(Node*& head){
    Node *temp = head;
    while (temp->next != NULL){
        cout<<temp->data<<" + ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;

}
int length_of_loop(Node* head){
    Node* fast = head;
    Node* slow = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast != slow){
        fast = fast->next->next;
        slow = slow->next;
    }
    int count = 1;
    fast = fast->next->next;
    slow = slow->next;
    count++;
    while (slow != fast){
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }
    return count;
}
bool is_palindrome(Node* head){
    Node* temp = head;
    stack<int> temp_stack;

    while(temp!=NULL){
        temp_stack.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if((temp_stack.top())!=(temp->data)){
            temp_stack.pop();
            return false;
        }
        temp_stack.pop();
        temp = temp->next;
    }
    return true;
}
void remove_duplicates_from_a_sorted_linked_list(Node* head){
    Node* temp = head;
    Node* curr = head;
    Node* nexted = head->next;
    while (nexted != NULL){
        if(nexted == curr){
            curr->next = nexted->next;
            delete nexted;
            nexted = curr->next;
        }else if(nexted != curr){
            curr = curr->next;
            nexted = nexted->next;
        }
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(1);
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,2);
    insert_at_tail(head,2);
    insert_at_tail(head,3);

    print_list(head);
    remove_duplicates_from_a_sorted_linked_list(head);
    print_list(head);
    
}
