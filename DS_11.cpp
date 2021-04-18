#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

template <class T>
class DSLinkedList {
    // internal presentation of list node
    struct ListNode {
        T value;
        ListNode* next;
        ListNode(T value1, ListNode* next1 = NULL) {
            value = value1;   next = next1;
        }
    };
    ListNode* head;
    ListNode* tail;
    ListNode* curr;
    unsigned int num_elements;
public:
    DSLinkedList() {
        head = NULL;
        tail = NULL;
        curr = NULL;
        num_elements = 0;
    }

    T* front() {
        if (head == NULL) return NULL;
        curr = head->next;
        return &(head->value);
    }

    T* next() {
        if (curr == NULL) return NULL;
        ListNode* tmp = curr;
        curr = curr->next;
        return &(tmp->value);
    }

    bool del_first() {
        if (head == NULL) return false;
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        num_elements--;
        return true;
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
        num_elements++;
    }

    void prepend(T element) {
        ListNode* newNode = new ListNode(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        num_elements++;
    }

    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    unsigned int numelements() {
        return num_elements;
    }

    bool find(T needle) {
        ListNode* tp = head;
        while (tp != NULL) {
            if (tp->value == needle) return true;
            tp = tp->next;
        }
        return false;
    }

    bool remove(T element) {
        //Removes all instances of element
        bool found = false;
        ListNode* tpprev = NULL;
        ListNode* tp = head;
        while (tp != NULL) {
            if (tp->value == element) {
                found = true;
                ListNode* delme = tp;
                if (tpprev == NULL) {  // To check if current node is head node
                    head = tp->next;
                    tp = head;
                }
                else {
                    tpprev->next = tp->next;
                    tp = tpprev->next;
                }
                delete delme;
                num_elements--;
            }
            else {
                if (tpprev == NULL) {
                    tpprev = tp;
                    tp = tp->next;
                }
                else {
                    tp = tp->next;
                    tpprev = tpprev->next;
                }
                // If not found, move to the next
            }
        }
        return found;
    }

    ~DSLinkedList() {
        //cout << "Destructor called\n";
        ListNode* tmp = head;
        ListNode* prev;
        while (tmp) {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
};


template <class T>
class DSStack {
    //implements a stack using DSLinkedList
    DSLinkedList<T> impl;
public:
    void push(T myobj) {
        impl.prepend(myobj);
    }
    bool is_empty() { return(impl.numelements() == 0); }
    T pop() {
        T* myobjptr = impl.front();
        if (myobjptr == NULL) throw("Stack empty");
        T myobj = *(myobjptr);
        impl.del_first();
        return myobj;
    }

    void print()
    {
        impl.print();
    }

    T front()
    {
        return impl.front();
    }

    T next()
    {
        return impl.next();
    }
};

class Phonebook {

private: 
    struct ListNode {
        string name; int number;
        ListNode* next;
        ListNode(string n, int no, ListNode* next1 = NULL) {
            name = n; number = no; next = next1;
        }
    };
    ListNode* head[26] = { NULL };
    ListNode* tail[26] = {};
    ListNode* curr = NULL;
public:
    void add(string name, int phone) {
        ListNode* newNode = new ListNode(name, phone);
        if (head[name['a']] == NULL) {
            head[name['a'] ] = newNode;
            tail[name['a']]  = newNode;
        }
        else {
            tail[name['a']]->next = newNode;
            tail[name['a']] = newNode;
        }
    }
 
    int retrieve(string n) {
        ListNode* tp = head[n['a']];
        while (tp != NULL) {
            if (tp->name == n) return tp->number;
            tp = tp->next;
        }
        return 0;
    }
};


bool Pairs(char openP, char closedP)
{
    if (openP == '(' && closedP == ')') return true;
    else
        return false;
}

template <class T>
bool Check(string exp = "I am (Aman))")
{
    int i = 0; 
    DSStack<char>s;
    while (exp[i]) //loops untill it encounters '\0' character
    {
        if (exp[i] == '(')
        {
            s.push(exp[i]); // push to stack
        }
        if (exp[i] == ')')
        {
            if (s.is_empty() == true) // If we found closing brackets, but there is no unmatched opening, than brackets are not balanced
                return 0;
            else
            {
                char top_brace = s.pop();
                if (!Pairs(top_brace, exp[i]))
                    return 0;
            }
                          
        }
        i++;//loop to check next character instead of one over and over
    }
    if (s.is_empty() == true) // If there is no unmatched opening braces left, then brackets are balanced, else they are not.
        return 1;
    else
        return 0;
}

int main()
{

    bool ans = Check<char>();
    cout << "---------1 = parentheses balanced and 0 = Parentheses not balanced----------" << endl;;
    cout << "Answer: " << ans << endl;

    cout << endl;
    string sen;
   /* cout << "Please enter a setence in following structure with any value: \n";
    cout << "The value of Bitcoin was 8389.51, now it is 57625.40.";
    cout << endl;
    cout << "Enter: ";
    getline(cin, sen);*/
    sen = "The value of Bitcoin was 8389.51, now it is 57625.40.";  // For another value. please comment this line and uncomment the above lines.
    string hold = "The value of Bitcoin was ";
    string f1 = "The value of Bitcoin was ";
    string f2 = "now it is ";
    int start1 = sen.find(f1) + f1.length();
    int start2 = sen.find(f2) + f2.length();
    string rest1 = sen.substr(start1);
    string rest2 = sen.substr(start2);
    
    int end1 = rest1.find(",");
    int end2 = rest2.find(".");
    rest1 = rest1.substr(0, end1);
    rest2 = rest2.substr(0, end2);
    float ans1 = stof(rest1);
    float ans2 = stof(rest2);
    cout << "If you invested $100, the value would be " << (ans2 * 100) / ans1 << " now.";

    /*Phonebook contact;
    contact.add("Aman", 1211);
    contact.add("Pathak", 1321);
    cout << contact.retrieve("Aman");
    cout << endl;*/
    system("pause");
    return 0;
}
