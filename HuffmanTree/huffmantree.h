#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;

template<class T> class HuffmanTreeNode;
template<class T> class HuffmanTree;


template<class T>
class HuffmanTreeNode
{
public:
	friend class HuffmanTree<T>;
	HuffmanTreeNode() :data(0), pparent(NULL), plchild(NULL), prchild(NULL) {}
	HuffmanTreeNode(T d, int w) :pparent(NULL), plchild(NULL), prchild(NULL), data(d), weight(w) {}
	T getdata()const;
	int getweight()const;
private:

	HuffmanTreeNode<T> *pparent, *plchild, *prchild;
	T data;
	int weight;
};

template<class T>
inline T HuffmanTreeNode<T>::getdata() const
{
	return	this->data;
}

template<class T>
inline int HuffmanTreeNode<T>::getweight() const
{
	return this->weight;
}



template<class T>
class HuffmanTree
{
public:
	HuffmanTree(int num_node, const T *hfmchar, const  int* hfmweight);
	void treetoFile(fstream &hfmtreefile);
	void treetoCode(fstream &hfmcode);

private:
	deque<HuffmanTreeNode<T> *> hfmforest;
	HuffmanTreeNode<T> *root;
private:

	void treetoFile(HuffmanTreeNode<T> *cnode, fstream &hfmtreefile);
	void treetoCode(HuffmanTreeNode<T> *cnode, fstream &hfmcode, string str);



private:
	//!!!!!!!!!!!!!!!!!!!!!!!!!!
	//在类内声明比较函数需要静态!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!
	static bool compare(HuffmanTreeNode<T> *treea, HuffmanTreeNode<T> *treeb) {
		return (treea->getweight()) < (treeb->getweight());
	}

};

template<class T>
inline HuffmanTree<T>::HuffmanTree(int num_node, const T * hfmchar, const int * hfmweight)
{
	//将数据存入结点森林
	for (int i = 0; i < num_node; i++)
	{
		HuffmanTreeNode<T> *ptr = new HuffmanTreeNode<T>(hfmchar[i], hfmweight[i]);
		hfmforest.push_front(ptr);
	}
	//建立HuffmanTree
	while (hfmforest.size() > 1)
	{
		//cout << hfmforest[i] << " " << hfmforest[i]->getdata() << " " << hfmforest[i]->getweight() << endl;
		sort(hfmforest.begin(), hfmforest.end(), compare);

		HuffmanTreeNode<T> *pnewNode = new HuffmanTreeNode<T>();
		pnewNode->weight = hfmforest.at(0)->getweight() + hfmforest.at(1)->getweight();
		hfmforest.at(0)->pparent = pnewNode;
		hfmforest.at(1)->pparent = pnewNode;
		pnewNode->plchild = hfmforest.at(0);
		pnewNode->prchild = hfmforest.at(1);
		hfmforest.pop_front();
		hfmforest.pop_front();
		hfmforest.push_back(pnewNode);
	}
	root = hfmforest.front();
	//cout << root->getweight() << endl;

}

template<class T>
inline void HuffmanTree<T>::treetoFile(fstream &hfmtreefile)
{
	treetoFile(root, hfmtreefile);
}

template<class T>
inline void HuffmanTree<T>::treetoCode(fstream & hfmcode)
{
	treetoCode(root, hfmcode, "");
}

template<class T>
inline void HuffmanTree<T>::treetoFile(HuffmanTreeNode<T>* cnode, fstream &hfmtreefile)
{
	if (cnode == NULL)
	{
		return;
	}
	else
	{
		hfmtreefile << cnode->getdata() << " " << cnode->getweight() << endl;
		treetoFile(cnode->plchild, hfmtreefile);
		treetoFile(cnode->prchild, hfmtreefile);
	}
}

template<class T>
inline void HuffmanTree<T>::treetoCode(HuffmanTreeNode<T>* cnode, fstream & hfmcode, string str)
{
	if (cnode == NULL)
	{
		return;
	}
	else
	{
		if (cnode->data != 0)
		{
			hfmcode << cnode->getdata() << " " << str << endl;
		}
		treetoCode(cnode->plchild, hfmcode, str + "0");
		treetoCode(cnode->prchild, hfmcode, str + "1");
	}
}




