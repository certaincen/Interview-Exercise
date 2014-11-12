#include <stdio.h>
#include <stdlib.h>
/*
 in tree ls means leftchild
 but in double link list ls means pre node .
 in tree rs means rightchild
 but in double link list rs means next node.
 */
struct BStreeNode
{
    int value;
    struct BStreeNode *ls;
    struct BStreeNode *rs;
};
struct BStreeNode *PreNode, *StartNode;
struct BStreeNode* root = NULL;
struct BStreeNode* new_node(int x)
{
    struct BStreeNode *tmp;
    tmp = (struct BStreeNode *)malloc(sizeof(struct BStreeNode));
    tmp -> value = x;
    tmp -> ls = NULL;
    tmp -> rs = NULL;
    return tmp;
}
void add_node(int x)
{
    if (root == NULL)
    {
        root = new_node(x);
        return ;
    }
    struct BStreeNode *p = root;
    struct BStreeNode *pre = p;
    int flag = 0;
    while (p != NULL)
    {
        pre = p;
        if (p->value>x)
        {
            p = p->ls;
            flag = 0;
        }
        else
        {
            p = p->rs;
            flag = 1;
        }
    }
    p = new_node(x);
    if (!flag)
    {
        pre->ls = p;
    }
    else
        pre->rs = p;
    return;
}
void change_to_link(struct BStreeNode *p)
{
    if (p->ls != NULL)
        change_to_link(p->ls);
    if (PreNode == NULL)
        StartNode = p;
    else
    {
        p->ls = PreNode;
        PreNode->rs = p;
    }
    PreNode = p;
    if (p->rs != NULL)
        change_to_link(p->rs);
    return;
}
void show_link()
{
    struct BStreeNode *p = StartNode;
    struct BStreeNode *pre = p;
    while (p != NULL)
    {
        pre = p;
        printf("%d->",p->value);
        p = p->rs;
    }
    printf("\n");
    while (pre != NULL)
    {
        printf("%d->",pre->value);
        pre = pre->ls;
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;

    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        add_node(x);
    }
    //show_node(root);
    change_to_link(root);
    show_link();
    return 0;
}
