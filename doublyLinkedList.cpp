// Двухсвязный список
// Каждый узел содержит элемент и два указателя, на следующий и предыдущий.

/* Операции : 1) Создание пустого
              2) Проверка на пустоту
              3) Очистка всего списка
              4) Добавление после заданного
              5) Добавление перед заданным
              6) Удаление после заданного
              7) Удаление перед заданным
              8) Удаление текущего
*/
#include <iostream>

using namespace std;

typedef int dtype;

struct Node_d {
  dtype data;
  Node_d* next;
  Node_d* prev;

  Node_d(dtype elem) {
    data = elem;
    next = nullptr;
    prev = nullptr;
  }
};

typedef Node_d* DList;

void init(DList& head, DList& tail) {
  head = nullptr;
  tail = nullptr;
}

DList init(DList& head) {
  head = nullptr;
  return head;
}

bool isEmpty(const DList& head) { return head == nullptr; }

// void addToTail(dtype elem, DList& tail) {
//   DList p = new Node_d(elem);
//   tail->next = p;
//   p->next = tail;
//   tail = p;
// }

// void addAfterNode(DList pnode, dtype elem) {
//   DList p = new Node_d(elem);
//   p->next = pnode->next;
//   pnode->next = p;
//   p->prev = pnode;
//   p->next->prev = p;
// }

void addAfterNode(DList pnode, DList& tail, dtype elem) {
  DList p = new Node_d(elem);
  p->next = pnode->next;
  pnode->next = p;
  p->prev = pnode;
  if (pnode == tail) {
    tail = p;
  } else {
    p->next->prev = p;
  }
}

void addBeforeNode(DList pnode, DList& head, dtype elem) {}  // написать

void deleteAfterNode(DList pnode, DList& tail) {
  DList p = pnode->next;
  pnode->next = p->next;
  if (pnode->next != tail) {
    p->next->prev = pnode;
  } else {
    tail = pnode;
  }
  p->next = nullptr;
  p->prev = nullptr;
  delete p;
  p = nullptr;
}

void deleteBeforeNode(DList pnode, DList& head) {}  // написать

void deleteCurrent(DList &pnode, DList &head, DList &tail) {
  if (pnode != head) {
    pnode->prev->next = pnode->next;
  } else {
    head = pnode->next;
  }

  if (pnode != tail) {
    pnode->next->prev = pnode->prev;
  } else {
    tail = pnode->prev;
  }
  pnode->next = nullptr;
  pnode->prev = nullptr;
  delete pnode;
}

void Clear(DList& head, DList& tail) {
  while (!isEmpty(head)) {
    deleteCurrent(head, head, tail);
  }
}

int main() {
  DList head, tail;
  init(head, tail);

  cout << "123";
}
