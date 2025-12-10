#include <iostream>
#include <string>
using namespace std;

struct ChildNode
{
    string name;
    ChildNode* next;
};

struct ParentNode
{
    string name;
    ChildNode* childHead;
    ParentNode* next;
};

ParentNode *createParent(string info)
{
    ParentNode* newNode = new ParentNode;
    newNode->name = info;
    newNode->childHead = NULL;
    newNode->next = NULL;
    return newNode;
}

ChildNode *createChild(string info)
{
    ChildNode* newNode = new ChildNode;
    newNode->name = info;
    newNode->next = NULL;
    return newNode;
}

void insertParent(ParentNode*& head, string info)
{
    ParentNode *newNode = createParent(info);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ParentNode* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertChild(ParentNode *head, string parentInfo, string childInfo)
{
    ParentNode *p = head;
    while (p != NULL && p->name != parentInfo)
    {
        p = p->next;
    }

    if(p != NULL)
    {
        ChildNode *newChild = createChild(childInfo);
        if (p->childHead == NULL)
        {
            p->childHead = newChild;
        }
        else
        {
            ChildNode *c = p->childHead;
            while (c->next != NULL)
            {
                c = c->next;
            }
            c->next = newChild;
        }
    }
}

void printAll(ParentNode *head)
{
    ParentNode *p = head;
    while (p != NULL)
    {
        cout << p->name;
        ChildNode *c = p->childHead;
        if (c != NULL)
        {
            while (c != NULL)
            {
                cout << " ->" << c->name;
                c = c->next;
            }
        }
        cout << endl;
        p = p->next;
    }
};

int main()
{
    ParentNode *list = NULL;

    insertParent(list, "Parent Node 1");
    insertParent(list, "Parent Node 2");

    printAll(list);
    cout << "\n";

    insertChild(list, "Parent node 1", "Child Node A");
    insertChild(list, "Parent node 1", "Child Node B");
    insertChild(list, "Parent node 2", "Child Node C");

    printAll(list);

    return 0;
}