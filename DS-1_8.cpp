#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

template <class T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T val1, ListNode* next1 = NULL)
    {
        val = val1; next = next1;
    }
    void user_input();
};
template <class T>
void ListNode<T>::user_input()
{
    ListNode* numberList = NULL;
    T number;
    cout << "Enter values (Press 0 to quit): ";
    while (cin >> number) {
        if (number == 0)
            break;
        else
        {
            numberList = new ListNode(number, numberList);
        }
    }
    cout << endl << "The contents of the list are: [  ";
    ListNode* ptr = numberList;
    while (ptr != nullptr) {
        cout << ptr->val << "  "; // Process node
        ptr = ptr->next;            // Move to next node
    }
    cout << "]\n";
}

int main()
{
    ListNode<int>* a = NULL;
    a->user_input();
    system("pause");
    return 0;
}

