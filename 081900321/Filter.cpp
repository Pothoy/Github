#include <iostream>
#include <fstream>
#include <sstream>
#include "Filter.h"
#include "TranslatePY.h"

void Filter::load(const char* filePath) { //载入敏感词，并且建立字典树
    ifstream keywordsFile(filePath, ios::in);
    if (keywordsFile.is_open())
    {
        string custom[1000],buffer[1000],str;
        int count = 0;
        int offset = 0;
        while ((custom[offset] = keywordsFile.getline()) != EOF)
        {
            buffer[offset] = custom[offset];
            if (buffer[offset][0] >= 0x4e00 && buffer[offset][0] <= 0x9fa5) {
                TranslatePY(buffer[offset],str);
                buffer[offset] = str;
            }
            offset++;
            m_tree.insert(buffer[offset]);
        }
    }
    keywordsFile.close();
    m_initialized = true;
}

void Filter::check(string str,int index) {
    if (!m_initialized){
        cout << "没有载入关键词";
        return;
    }
    else
    {
        if (m_tree.find(str) != NULL) {
            ans[index]="Line"+to_string(index)+": <"+
        }
    }
}




            //for (int i = 0; i < buffer[offset].length(); i++) { //检查：如果是数字、字母、汉字则保留
            //    if ((buffer[offset][i] >= 'a' && buffer[offset][i] <= 'z') ||
            //        (buffer[offset][i] >= 'A' && buffer[offset][i] <= 'Z') ||
            //        (buffer[offset][i] >= '0' && buffer[offset][i] <= '9') ||
            //        (buffer[offset][i] >= 0x4e00 && buffer[offset][i] <= 0x9fa5))//如果是汉字
            //        continue;
            //    else //如果是其他符号，则替换为*
            //        buffer[offset][i] = '*';
            //}
            //string word1;
            //word1.assign(buffer, offset);
            //if (buffer[offset] == ',' && (offset % 2) == 0)
            //{
            //    string word;
            //    if (offset)
            //    {
            //        word.assign(buffer, offset);
            //        m_tree.insert(word);
            //    }
            //    offset = 0;
            //}
            //else
            //    offset++;