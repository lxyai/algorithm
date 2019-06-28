#include <iostream>

using namespace std;

class ListNode
{
  public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
    void Print_ListNode(void);
    ListNode *MakeList(int);
};

void ListNode::Print_ListNode(void)
{
    ListNode *temp = this;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

ListNode *MakeList(int x)
{
    int temp_num = x;
    ListNode *temp_list = NULL;
    ListNode *start_list = NULL;
    while (temp_num != 0)
    {
        ListNode *node = new ListNode(temp_num % 10);
        if (temp_list == NULL)
        {
            temp_list = node;
            start_list = temp_list;
        }
        else
        {
            temp_list->next = node;
            temp_list = temp_list->next;
        }
        temp_num = temp_num / 10;
    }
    return start_list;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *tmp = NULL;
    ListNode *result = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = ((l1 == NULL) ? 0 : l1->val) + ((l2 == NULL) ? 0 : l2->val) + carry;

        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        if (tmp == NULL)
        {
            tmp = node;
            result = tmp;
        }
        else
        {
            tmp->next = node;
            tmp = tmp->next;
        }
        l1 = ((l1 == NULL) ? NULL : l1->next);
        l2 = ((l2 == NULL) ? NULL : l2->next);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    /* code */
    ListNode *list1 = MakeList(123);
    ListNode *list2 = MakeList(123);
    ListNode *list3 = addTwoNumbers(list1, list2);
    list3->Print_ListNode();
    return 0;

}
