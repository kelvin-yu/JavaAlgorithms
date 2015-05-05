#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int nodeCount = 0;
int root = -1;

struct node
{
    int data, left, right, sizeOfRight, sizeOfLeft;
} tree[MAXN + 1];

int createNode(int data)
{
    nodeCount++;
    tree[nodeCount].data = data;
    tree[nodeCount].left = tree[nodeCount].right = -1;
    return nodeCount;
}

int add(int index, int data)
{
    if(index == -1)
        return createNode(data);
    else
    {
        if(data > tree[index].data)
        {
            tree[index].sizeOfRight++;
            tree[index].right = add(tree[index].right, data);
        }
        else
        {
            tree[index].sizeOfLeft++;
            tree[index].left = add(tree[index].left, data);
        }
    }
    return index;
}

int find_min(int index)
{
    while(tree[index].left != -1)
    {
        index = tree[index].left;
    }
    return index;
}

int remove(int index, int data)
{
    if(index == -1)
    {
        return index;
    }
    if(data > tree[index].data)
    {
        tree[index].sizeOfRight--;
        tree[index].right = remove(tree[index].right,data);
    }
    else if(data < tree[index].data)
    {
        tree[index].sizeOfLeft--;
        tree[index].left = remove(tree[index].left, data);
    }
    else
    {
        if(tree[index].left == -1 && tree[index].right == -1)
        {
            return -1;
        }
        else if(tree[index].left == -1)
        {
            return tree[index].right;
        }
        else if(tree[index].right == -1)
        {
            return tree[index].left;
        }
        else
        {
            tree[index].data = tree[find_min(tree[index].right)].data;
            tree[index].right = remove(tree[index].right, tree[index].data);
            if(tree[index].right != -1)
            {
                tree[index].sizeOfRight = tree[tree[index].right].sizeOfLeft + tree[tree[index].right].sizeOfRight + 1;
            }
            else
            {
                tree[index].sizeOfRight = 0;
            }
        }
    }
    return index;
}

int k;
void kthGreatest(int index)
{
    if(tree[index].sizeOfRight + 1 == k)
    {
        printf("%d\n", index);
    }
    else if(k <= tree[index].sizeOfRight)
    {
        kthGreatest(tree[index].right);
    }
    else if(k > tree[index].sizeOfRight)
    {
        k -= tree[index].sizeOfRight + 1;
        kthGreatest(tree[index].left);
    }
}

int main()
{
    root = add(root, 1000);
    root = add(root, 2000);
    root = remove(root, 1000);
}
