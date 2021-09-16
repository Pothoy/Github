#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <assert.h>
#include "Filter.h"
#include "TranslatePY.h"
using namespace std;

Filter filter;
int TotalLine_of_org = 0, TotalLine_of_ans = 0;
string org[1000], ans[2000];//org存问题文件，ans暂时存检测出的敏感词信息然后outputFile << ans[i] << endl;

void readOrg(const char* file) { //读取目标(逐行)
	int offset= 0,flag=0;
	string s;
	ifstream infile;
	infile.open(file,"ccs=utf-8");
	assert(infile.is_open()); //若失败,则输出错误消息,并终止程序运行 
	while (getline(infile, s)) {
		org[offset] = s;
		buffer[offset] = s;
		if (buffer[offset][i] == q.content[j] && p.word[i + 1] == q.content[j + 1] && p.word[i + 2] == q.content[j + 2]) {
			TranslatePY(buffer[offset], buffer[offset]);
		}
		for (int i = 0; i < buffer[offset].length(); i++) { //检查：如果是数字、字母、汉字则保留
			if ((buffer[offset][i] >= 'a' && buffer[offset][i] <= 'z') ||
				(buffer[offset][i] >= 'A' && buffer[offset][i] <= 'Z') ||
				(buffer[offset][i] >= '0' && buffer[offset][i] <= '9'))
				continue;
			else //如果是其他符号，则替换为*
				buffer[offset][i] = '*';
		}
		offset++;
	}
	TotalLine_of_org = i;
	infile.close(); //关闭文件输入流 
}

void Search() {
	int cnt = 0;
	ofstream outputFile.open(argv[3]);
	for (int i = 0; i < TotalLine_of_org; i++) {
		filter.check(org[i]);
	}
	outputFile << "Total: " << cnt << endl;
	for (int i = 0; i < TotalLine_of_ans; i++) {
		outputFile << ans[i] << endl;
	}
	outputFile.close();
}


int main(int argc, char* argv[]) {
	filter.load(argv[1]); //构建敏感词字典树
	readOrg(argv[2]); //读取要检查的文档
	Search();
	return 0;
}