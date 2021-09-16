#include <string>
#include "Tree.h"

class Filter{
    private:
        Tree m_tree;
    public:
        void load(const char* fileName); //通过文件载入敏感词，并构建Tree
        bool m_initialized;
        void check(string org[]); //用来进行敏感词过滤,source包含敏感词则...
};
