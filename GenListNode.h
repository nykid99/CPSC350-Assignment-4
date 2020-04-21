#include <iostream>
#include <string>
using namespace std;

template <class T>
class GenListNode
{
	public:
		T data;
    GenListNode<T> *next;
    GenListNode<T> *prev;
		GenListNode();
		GenListNode(T d);
		~GenListNode();


};
template <class T>
GenListNode<T>::GenListNode(){
	data = NULL;
	next = NULL;
	prev = NULL;
};
template <class T>
GenListNode<T>::GenListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}
template <class T>
GenListNode<T>::~GenListNode()
{
	if (next != NULL)
	{
		next = NULL;
		prev = NULL;
		delete next;
		delete prev;
	}
}
