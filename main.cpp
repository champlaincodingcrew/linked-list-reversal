#include <iostream>

struct Node {
  public:
    Node* mNext;
    int mData;

    Node(int data, Node* next = nullptr);
    Node();
};

Node::Node(int data, Node* next) {
  mData = data;
  mNext = next;
}

class LinkedList {
  public:
    Node* mHead;
    void reverse();
};

void LinkedList::reverse() {
	if (mHead->mNext == nullptr)
		return;
    
	Node* current = mHead->mNext;
	Node* last = mHead;
	
	mHead->mNext = nullptr;

	while (current != nullptr)
	{
		Node* tmp = current->mNext;
		current->mNext = last;
		last = current;
		current = tmp;
	}

	mHead = last;
}

void fillNodes(LinkedList& list) {
  int i = 0;
  Node* node = new Node(i);
  list.mHead = node;

  for (i = 1; i < 10; i++) {
    node->mNext = new Node(i);
    node = node->mNext;
  }
}

int main() {
  LinkedList list;

  fillNodes(list);

  list.reverse();

  Node* current;
  current = list.mHead;
  while(current != nullptr)
  {
    std::cout<< current->mData << " ";
    current = current->mNext;
  }

  return 0;
}