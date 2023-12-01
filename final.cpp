#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n;
int *num = new int[n]();
void shuru();
struct TreeNode;
void ZhongxuBianli(TreeNode *root);

// 创建二叉树结点结构体
struct TreeNode
{
    int data;        // 结点值
    TreeNode *left;  // 左子树指针
    TreeNode *right; // 右子树指针
};

// 二叉树中创建新结点并初始化
TreeNode *createNode(int value)
{
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 在二叉排序树中插入新结点
TreeNode *IntoTree(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = IntoTree(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = IntoTree(root->right, value);
    }

    return root;
}

// 查找二叉搜索树中的最小结点
TreeNode *findMin(TreeNode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

// 删除二叉搜索树中的结点
TreeNode *deleteNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// 查找并删除指定值的结点
TreeNode *SearchAndDelete(TreeNode *root, int value)
{
    TreeNode *temp = root;
    bool found = false;

    // 迭代查找指定值的结点
    while (temp != nullptr)
    { 
        if (value < temp->data)
        {
            temp = temp->left;
        }

        else if (value > temp->data)
        {
            temp = temp->right;
        }

        else
        {
            found = true;
            break;
        }
    }

    // 如果找到则删除结点并输出中序遍历结果，否则输出“无x”
    if (found)
    { 
        cout << "找到值为 " << value << " 的结点，删除后中序遍历结果为: ";
        root = deleteNode(root, value);
        ZhongxuBianli(root);
        cout << endl;
    }

    else
    {
        cout << "无 " << value << endl;
    }

    return root;
}

int main()
{

    shuru();

    TreeNode *root = nullptr; // 初始化根结点

    // 遍历数组，创建结点
    for (int i = 1; i <= n; i++)
    { 
        root = IntoTree(root, num[i]);
    }

    cout << "该数列生成的二叉树中序遍历的结果为：" << endl;
    ZhongxuBianli(root); // 执行中序遍历并输出
    cout << endl;

    cout << "如果你需要删除某一结点，请你输入结点值x；如果输入内容非数字，则关闭程序" << endl;

    // 步骤2：输入x
    int x; 

    if (!(cin >> x))
    {
        cout << "程序结束";
        return 0;
    }
    cout << "你输入的x为：" << x << endl;

    root = SearchAndDelete(root, x);

    return 0;
}

// 步骤1：输入数组，数组存入num[i]，i从1开始，数量为n
void shuru()
{

    int i = 1 , a;
    cout << "请输入数列，以回车结束：" << endl;

    while (cin >> a)
    {
        num[i++] = a;
        if (cin.get() == '\n')      // 输入回车时停止，i即为数列个数
            break; 
    }

    n = i - 1;
    printf("该数列有%d个数:\n", n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", num[i]);
    }
    cout << endl;
}

// 中序遍历二叉排序树并打印结果
void ZhongxuBianli(TreeNode *root)
{

    if (root != nullptr)
    {
        ZhongxuBianli(root->left);
        cout << root->data << " ";
        ZhongxuBianli(root->right);
    }
}
