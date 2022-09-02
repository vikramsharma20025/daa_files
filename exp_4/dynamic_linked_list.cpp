#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class final_list_constructed{
    public:
        Node * head  = NULL;
        void push(int val){
            Node *n = new Node(val);
            if(head == NULL){
                head = n;
            }else{
                Node *temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = n;
            }
        }
        int nth_node_in_list(int val){
            Node * temp = head;
            int count = 1;
            while (temp!=NULL){
                   if(count == val){
                    return (temp->data);
                   }
                   temp = temp->next;
                   count++;
            }
            cout<<"Number too large"<<endl;
        }
        int length_of_loop(){
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
            while (slow != fast){
                count++;
                slow = slow->next;
                fast = fast->next->next;
            }
            return count;
        }
        int nth_node_from_tail(int val){
            Node* main = head;
            Node* to_tail = head;
            int count = 1;
            while (to_tail!=NULL){
                if(count == val){
                    break;
                }
                to_tail = to_tail->next;
                count++;
            }
            while(to_tail->next!=NULL){
                main = main->next;
                to_tail = to_tail->next;
            }
            return (main->data);
        }
        int count_this_number(int val){
            Node* curr = head;
            int count = 0;
            while (curr!=NULL){
                if(curr->data == val){
                    count++;
                }
                curr = curr->next;
            }
            return count;
        }
        int middle_node_listed(){
            Node* middle = head;
            Node* last = head;
            while(last!=NULL && last->next!=NULL){
                middle = middle->next;
                last = last->next->next;
            }
            return (middle->data);
        }
        void print_list(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
        void delete_an_node(int key){
            Node* temp = head;
            Node * curr = head->next;
            if(head->data==key){
                head = head->next;
                delete temp;
            }
            while (curr!=NULL){
                if(curr->data==key){
                    temp->next = curr->next;
                }
                temp = temp->next;
                curr = curr->next;
            }
            delete curr;
        }
        void delete_at_head(){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void delete_at_tail(){
            Node* temp = head;
            Node* curr = head->next;
            if(head->next==NULL){
                delete temp;
                return;
            }
            while(curr->next!=NULL){
                curr = curr->next;
                temp =  temp->next;
            }
            temp->next = NULL;
            delete curr;
        }
};

int main(){
    final_list_constructed first;
    first.push(1);
    first.push(2);
    first.push(3);
    first.push(3);
    first.push(3);
    first.push(3);
    first.push(4);
    first.push(5);
    first.print_list();
    first.delete_an_node(1);
    first.push(6);
    first.print_list();
    first.delete_at_head();
    first.print_list();
    first.delete_at_tail();
    first.print_list();
    cout<<first.count_this_number(3)<<endl;
}