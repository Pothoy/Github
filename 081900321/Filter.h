#include <string>
#include "Tree.h"

class Filter{
    private:
        Tree m_tree;
    public:
        void load(const char* fileName); //ͨ���ļ��������дʣ�������Tree
        bool m_initialized;
        void check(string org[]); //�����������дʹ���,source�������д���...
};
