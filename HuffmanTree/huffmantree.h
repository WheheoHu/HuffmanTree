#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class HuffmanTreeNode
{
public:
	HuffmanTreeNode() :pparent(NULL), plchild(NULL), prchild(NULL) {}
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
