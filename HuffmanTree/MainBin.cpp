//I： 初始化。从终端读入字符集大小 n ，及 n 个字符和 n 个权值，建立哈夫曼树，并将其存于文件hfmtree中。
//C： 编码。利用已建好的哈夫曼树（如不在内存，则从文件hfmtree中读入），对文件tobetrans中的正文进行编码，然后将结果存入文件codefile中。
//D： 译码。利用已建好的哈夫曼树将文件codefile中的代码进行译码，结果存入文件textfile中。
//P： 打印代码文件。将文件codefi1e以紧凑格式显示在终端上, 每行50个代码。同时将此字符形式的编码文件写入文件codeprint中。
//T：打印哈夫曼树。将已在内存中的哈夫曼树以直观的方式（树或凹凸表形式）显示在屏幕上，同时将此字符形式的哈夫曼树写入文件treeprint中。

#include <fstream>
#include "huffmantree.h"

using namespace std;

int main() {

}