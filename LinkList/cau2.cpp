#include <iostream>
using namespace std;

struct PS
{
    int tu;
    int mau;
    PS *next;
};

PS *createNode(int tu, int mau)
{
    PS *temp = new PS();
    if (mau < 0)
    {
        temp->tu = -1 * tu;
        temp->mau = -1 * mau;
    }
    else
    {
        temp->tu = tu;
        temp->mau = mau;
    }
    temp->next = NULL;
    return temp;
}

PS *addEnd(PS *p, int tu, int mau)
{
    PS *temp = createNode(tu, mau);
    PS *ptr = p;
    if (p == NULL)
    {
        ptr = temp;
        return ptr;
    }
    while ((ptr->next) != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return p;
}

void printfList(PS *p)
{
    PS *temp = p;
    while (temp != NULL)
    {
        cout << temp->tu << "/" << temp->mau << " ";
        temp = temp->next;
    }
    cout << endl;
}

int isPositive(PS *node)
{
    if (node->tu / node->mau >= 0)
    {
        return 1;
    }
    return 0;
}
int isBigger(PS *ps_1, PS *ps_2)
{
    float a = (float)ps_1->tu / ps_1->mau;
    float b = (float)ps_2->tu / ps_2->mau;
    return (a > b) ? 1 : 0;
}
void swap(PS *a, PS *b)
{
    PS *temp = new PS();
    temp->tu = a->tu;
    temp->mau= a->mau;
    a->tu = b->tu;
    a->mau = b->mau;
    b->tu = temp->tu;
    b->mau = temp->mau;
}

void sort(PS *list)
{
    for (PS *ptr_1 = list; ptr_1->next != NULL; ptr_1 = ptr_1->next)
    {
        if (isPositive(ptr_1))
        {
            for (PS *ptr_2 = ptr_1->next; ptr_2 != NULL; ptr_2 = ptr_2->next)
            {
                if (isPositive(ptr_2) && isBigger(ptr_1, ptr_2))
                {
                    swap(ptr_1, ptr_2);
                }
            }
        }
    }
}

int main()
{
    PS *list = NULL;
    list = addEnd(list, 2, 3);
    list = addEnd(list, 3, -4);
    list = addEnd(list, 3, 7);
    list = addEnd(list, -5, 6);
    list = addEnd(list, 11, 4);
    list = addEnd(list, 1, 4);
    cout<<"List: ";
    printfList(list);
    sort(list);
    cout<<"Sort: ";
    printfList(list);
    return 0;
}