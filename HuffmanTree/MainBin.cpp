//I�� ��ʼ�������ն˶����ַ�����С n ���� n ���ַ��� n ��Ȩֵ��������������������������ļ�hfmtree�С�
//C�� ���롣�����ѽ��õĹ����������粻���ڴ棬����ļ�hfmtree�ж��룩�����ļ�tobetrans�е����Ľ��б��룬Ȼ�󽫽�������ļ�codefile�С�
//D�� ���롣�����ѽ��õĹ����������ļ�codefile�еĴ���������룬��������ļ�textfile�С�
//P�� ��ӡ�����ļ������ļ�codefi1e�Խ��ո�ʽ��ʾ���ն���, ÿ��50�����롣ͬʱ�����ַ���ʽ�ı����ļ�д���ļ�codeprint�С�
//T����ӡ�����������������ڴ��еĹ���������ֱ�۵ķ�ʽ������͹����ʽ����ʾ����Ļ�ϣ�ͬʱ�����ַ���ʽ�Ĺ�������д���ļ�treeprint�С�
//�û�����������Ϊ���˵�����ʽ����ʾ�������ܺţ��ټ��ϡ�E����ʾ���������н���
//�û�����һ��ѡ�����ַ�����ִ����Ӧ�Ĺ��ܣ��˹���ִ����Ϻ�����ʾ�˲˵���ֱ���û�ѡ���ˡ�E��Ϊֹ��
//�ڳ����һ��ִ�й����У���һ��ִ����I��D �� C ����֮�󣬹��������Ѿ����ڴ��д����ˣ������ٶ��롣
//ÿ��ִ���в�һ��ִ�� I �����Ϊ�ļ� hfmtree �������ѽ��á�

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

	//����
	int SIZEOFCODE = 0;
	inputfile >> SIZEOFCODE;
	char *hfmchar = new char[SIZEOFCODE];
	int *hfmweight = new int[SIZEOFCODE];
	for (int i = 0; i < SIZEOFCODE; i++)
	{
		inputfile >> hfmchar[i];
		inputfile >> hfmweight[i];
	}

	//j����HuffmanTree
	HuffmanTree<char> huffmantree(SIZEOFCODE, hfmchar, hfmweight);
	huffmantree.treetoFile(hfmtree);
	huffmantree.treetoCode(hfmcode);




	//��β

	inputfile.close();
	tobetrans.close();
	hfmtree.close();
	hfmcode.close();
	//system("pause");
	return EXIT_SUCCESS;
}