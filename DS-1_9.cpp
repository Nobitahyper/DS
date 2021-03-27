#include <iostream>
#include <string>

using namespace std;

template <class T>
class DSLinkedList {
    /* internal presentation of list node*/
    struct ListNode {
        T value;
        ListNode* next;
        ListNode(T value1, ListNode* next1 = NULL) {
            value = value1;   next = next1;
        }
    };
    ListNode* head; // List head pointer
    ListNode* tail;
public:
    DSLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void append(T val) {
       ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void prepend(T val) {
        ListNode* tp = new ListNode(val);
        tp->value = val;
        tp->next = head;
        head = tp;
    }
    
    bool find(T needle) {
        ListNode* tp = head;
        while (tp != NULL)
        {
         if (tp->value == needle) return true;
         tp = tp->next;
        }
        return false;
    }
    bool remove(T element) {
        ListNode* nodeptr, * prevnodeptr = head;
        
        if (head->value == element) {
            nodeptr = head;
            head = head->next;
            delete nodeptr;
            return true;
        }
        else
        {
            nodeptr = head;
            while (nodeptr != nullptr && nodeptr->value != element)
            {
                prevnodeptr = nodeptr;
                nodeptr = nodeptr->next;
            }
            if (nodeptr) {
                prevnodeptr->next = nodeptr->next;
                delete nodeptr;
                return true;
            }
        }
        return false;
    }

    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }
    unsigned int numelements() {
        int count = 0;
        ListNode* current = head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    ~DSLinkedList() {
        cout << "Destructor called\n";
        ListNode* tmp = head;
        ListNode* prev;
        while (tmp) {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
};

int main() {
    DSLinkedList<int> myll;
    myll.append(1);
    myll.append(2);
    myll.append(3);
    myll.prepend(4);
    myll.print();
    cout << "The number of elements in the list are " << myll.numelements() << endl;
    if (myll.find(1)) cout << "Found 1\n";
    if (!myll.find(1)) cout << "Not Found 1\n";
    if(myll.remove(1)) cout << "Deleted 1\n";
    if (!myll.find(100)) cout << "Not deleted 100\n";
    myll.print();
    cout << "The number of elements in the list are " << myll.numelements() << endl;
    system("pause");
    return 0;
}