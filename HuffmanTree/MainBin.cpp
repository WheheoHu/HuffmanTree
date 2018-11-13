//I： 初始化。从终端读入字符集大小 n ，及 n 个字符和 n 个权值，建立哈夫曼树，并将其存于文件hfmtree中。
//C： 编码。利用已建好的哈夫曼树（如不在内存，则从文件hfmtree中读入），对文件tobetrans中的正文进行编码，然后将结果存入文件codefile中。
//D： 译码。利用已建好的哈夫曼树将文件codefile中的代码进行译码，结果存入文件textfile中。
//P： 打印代码文件。将文件codefi1e以紧凑格式显示在终端上, 每行50个代码。同时将此字符形式的编码文件写入文件codeprint中。
//T：打印哈夫曼树。将已在内存中的哈夫曼树以直观的方式（树或凹凸表形式）显示在屏幕上，同时将此字符形式的哈夫曼树写入文件treeprint中。
//用户界面可以设计为“菜单”方式：显示上述功能号，再加上“E”表示结束运性行结束
//用户键入一个选择功能字符，则执行相应的功能，此功能执行完毕后再显示此菜单，直至用户选择了“E”为止。
//在程序的一次执行过程中，第一次执行了I、D 或 C 命令之后，哈夫曼树已经在内存中存在了，不必再读入。
//每次执行中不一定执行 I 命令，因为文件 hfmtree 可能早已建好。

#include <fstream>
#include <deque>
#include "huffmantree.h"

using namespace std;


int main() {
	fstream inputfile, tobetrans,hfmtree, hfmcode;
	
	inputfile.open("input", ios::in);
	tobetrans.open("tobetrans", ios::in);
	hfmtree.open("hfmtree", ios::out);
	hfmcode.open("hfmcode", ios::out);

	//输入
	int SIZEOFCODE = 0;
	inputfile >> SIZEOFCODE;
	char *hfmchar = new char[SIZEOFCODE];
	int *hfmweight = new int[SIZEOFCODE];
	for (int i = 0; i < SIZEOFCODE; i++)
	{
		inputfile >> hfmchar[i];
		inputfile >> hfmweight[i];
	}

	//j建立HuffmanTree
	HuffmanTree<char> huffmantree(SIZEOFCODE, hfmchar, hfmweight);
	huffmantree.treetoFile(hfmtree);
	huffmantree.treetoCode(hfmcode);




	//收尾

	inputfile.close();
	tobetrans.close();
	hfmtree.close();
	hfmcode.close();
	//system("pause");
	return EXIT_SUCCESS;
}