#include <iostream>

using namespace std;

class SanPham
{
public:
    int masp;
    string tensp;
    string chungloai[3];
    int namsx;
    int nambh;
};

struct Node
{
    SanPham data;
    Node* next;
};

Node* CreateNode(SanPham init_data)
{
    Node* node = new Node();
    node->data = init_data;
    node->next = NULL;
    return node;
}

struct ListSP
{
    Node* head;
    Node* tail;
};
void CreateList(ListSP& l)
{
    l.head = NULL;
    l.tail = NULL;
}

//cau 2
void SortListDescrease(ListSP & list)
{
    for (Node* i = list.head; i != NULL; i = i->next)
    {
        for (Node* j = i->next; j != NULL; j = j->next)
        {
            if (i->data.masp < j->data.masp) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            {
                SanPham tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

//cau 3
void XoaSPHetHan(ListSP &l)
{
    Node* node = l.head;
    while (node != NULL)
    {
        if (node->data.namsx + node->data.nambh > 2021)
            delete node;
    }
}


int main()
{

}