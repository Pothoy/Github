#include "Tree.h"
#include<iostream>

#define PACE 1    //�����Ҫ����Ӣ�Ļ���Ӣ�Ľ�ϵ��������PACE��Ϊ1�����������Ҫ�������޸�

TreeNode* Tree::insert(string& keyword) {
    return insert(&m_emptyRoot, keyword);
}

TreeNode* Tree::insert(const char* keyword)
{
    string wordstr(keyword);
    return insert(wordstr);
}


TreeNode* Tree::insert(TreeNode* parent, string& keyword) {
    if (keyword.size() == 0)
        return NULL;
    string firstChar = keyword.substr(0, PACE);
    TreeNode* firstNode = parent->findChild(firstChar);
    if (firstNode == NULL)
        return insertBranch(parent, keyword);
    string restChar = keyword.substr(PACE, keyword.size());
    return insert(firstNode, restChar);
}

TreeNode* Tree::insertBranch(TreeNode* parent, string& keyword) {
    string firstChar = keyword.substr(0, PACE);
    TreeNode* firstNode = parent->insertChild(firstChar);
    if (firstNode != NULL)
    {
        string restChar = keyword.substr(PACE, keyword.size());
        if (!restChar.empty())
            return insertBranch(firstNode, restChar);
    }
    return NULL;
}

TreeNode* Tree::find(string& keyword)
{
    return find(&m_emptyRoot, keyword);
}


TreeNode* Tree::find(TreeNode* parent, string& keyword) {
    string firstChar = keyword.substr(0, PACE); //�ָ�restChar�Ŀ�ͷ�����ַ�
    TreeNode* firstNode = parent->findChild(firstChar);
    if (firstNode == NULL)            //δ�ҵ�
    {
        count = 0;
        return NULL;
    }
    string restChar = keyword.substr(PACE, keyword.size());
    if (firstNode->m_map.empty())        //��Ӧ������������жϸô�Ϊ���д�
    {
        return firstNode;
    }
    if (keyword.size() == PACE)    //���һ����
        return NULL;
    count++;
    return find(firstNode, restChar);
}