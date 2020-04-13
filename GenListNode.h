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

		GenListNode(){
      data = NULL;
      next = NULL;
      prev = NULL;
    };

		GenListNode(T d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
		~GenListNode()
		{
			if (next != NULL)
			{
				next = NULL;
				prev = NULL;
				delete next;
				delete prev;
			}
		}
};
