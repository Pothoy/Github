#include <iostream>
#include "Trie.h"
using namespace std;

string TreeNode::getCharacter() const
{
    return m_character;
}

TreeNode::TreeNode(string character)
{
    if (character.size() == 2)
        m_character.assign(character);
    else
        cout << "error";
}

TreeNode* TreeNode::findChild(string& nextCharacter)
{
    _TreeMapIterator TreeMapIt = m_map.find(nextCharacter);    //����map/unordered_map���в���
    return (TreeMapIt == m_map.end()) ? NULL : &TreeMapIt->second;
    return NULL;
}

TreeNode* TreeNode::insertChild(string& nextCharacter)
{
    if (!findChild(nextCharacter))    //��ӽڵ㣬�����ؽڵ�λ��
    {
        m_map.insert(pair<string, TreeNode>(nextCharacter, TreeNode(nextCharacter)));
        return &(m_map.find(nextCharacter)->second);
    }
    return NULL;
}