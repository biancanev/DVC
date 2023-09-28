#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode *link;
};

/**
 * Assumption: the intergers in the list ar sorted
 * To insert the new node to the proper position in the list,
 * the integers must remain sorted
 * **/

/* Insert a new node to the proper position in the list. The integers must remain sorted.*/
void insertNode(ListNode *&, int);
void display(ListNode *);
void reverseList(ListNode *&);
void deleteList(ListNode *&);

int main()
{
    ListNode *head = nullptr;
    insertNode(head, 994);
    insertNode(head, 998);
    insertNode(head, 990);
    insertNode(head, 997);
    insertNode(head, 999);
    
    cout << "Display  990 -> 994 -> 997 -> 998 -> 999 -> nullptr" << endl;
    display(head);
    deleteList(head);
    insertNode(head, 222);
    reverseList(head);
    cout << "Display  222 -> nullptr" << endl;
    display(head);

    insertNode(head, 333);
    reverseList(head);
    cout << "Display  333 -> 222 -> nullptr" << endl;
    display(head);

    reverseList(head);
    insertNode(head, 111);
    cout << "Display  111 -> 222 -> 333 -> nullptr" << endl;
    display(head);

    reverseList(head);
    cout << "Display  333 -> 222 -> 111 -> nullptr" << endl;
    display(head);


    deleteList(head);
    cout << "Display -> nullptr" << endl;
    display(head);

    return 0;
}

void insertNode(ListNode *&head, int data)
{
    ListNode * newNode = new ListNode;
    newNode->data = data;
    newNode->link = nullptr;

    /// There are two cases here
    if (head == nullptr) /// Case 1, the linked list is empty
    {
        head = newNode;
        return;
    }
    /// Case 2, new node is less than the head
    if(newNode->data < head->data){
        newNode->link = head;
        head = newNode;
        return;
    }
    else{
        for(ListNode *node = head; node; node = node->link){
            //Case 3, new node is greater than all the nodes in the list
            if(node->link == nullptr){
                node->link = newNode;
                return;
            }
            //Case 4, new node is between two nodes in the list
            if(node->data <= newNode->data && newNode->data <= node->link->data){
                newNode->link = node->link;
                node->link = newNode;
                return;
            }
        }
    }


}

void display(ListNode *head)
{
    ListNode *p = head;
    if (head != nullptr) /// Do display only when head is not NULL,
        while (p != nullptr)
        {
            cout << p->data << "       -> ";
            p = p->link;
        }

    cout << " nullptr" << endl << endl;
    return;
}


void deleteList(ListNode *& head)
{
    /// ADD YOUR CODE HERE
    ListNode *p = head;
    while(p != nullptr){
        ListNode *q = p->link;
        delete p;
        p = q;
    }
    head = nullptr;
};

void reverseList(ListNode *& head)
{
    /// ADD YOUR CODE HERE
    /// CASE 1: 0 node or 1 node
    if(head == nullptr || head->link == nullptr){
        return;
    }
    /// CASE 2: 2 or more nodes
    //pointer for the previous, current and next node
    ListNode *prev = nullptr, *curr = head, *next = head->link;
    while(next != nullptr){
        //link the current node to the previous node
        curr->link = prev;
        //increment previous pointer
        prev = curr;
        //increment current pointer
        curr = next;
        //increment next pointer
        next = next->link;
    }
    //link the current node to the previous node for the last node
    curr->link = prev;
    //set the new head
    head = curr;
    return;
};