#include "Trie.h"
using namespace std;

class Tree {
public:
    int count;    //��ǰ���ҵ�һ�����дʵ�����
    TreeNode* insert(string& keyword);
    TreeNode* insert(const char* keyword);
    TreeNode* find(string& keyword);
    Tree() {
        count = 0;
    };
private:
    TreeNode m_emptyRoot;
    int m_pace;
    TreeNode* insert(TreeNode* parent, string& keyword);
    TreeNode* insertBranch(TreeNode* parent, string& keyword);
    TreeNode* find(TreeNode* parent, string& keyword);
};
