// Двухсвязный список
// Каждый узел содержит элемент и два указателя, на следующий и предыдущий.

/* Операции : + 1) Создание пустого
              + 2) Проверка на пустоту
              + 3) Очистка всего списка
              + 4) Добавление после заданного
              + 5) Добавление перед заданным
              + 6) Удаление после заданного
              + 7) Удаление перед заданным
              + 8) Удаление текущего
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

void printDList(const DList& head, const DList& tail) {
  DList temp = head;
  if (!isEmpty(head)) {
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  } else {
    cout << "Empty list";
  }
}

void addAfterNode(const DList& curNode, DList& tail, const dtype& elem) {
  DList newNode = new Node_d(elem);

  newNode->next = curNode->next;
  curNode->next = newNode;
  newNode->prev = curNode;

  if (curNode == tail) {
    tail = newNode;
  } else {
    newNode->next->prev = newNode;
  }
}

void addBeforeNode(const DList& curNode, DList& head, const dtype& elem) {
  DList newNode = new Node_d(elem);

  newNode->next = curNode;
  newNode->prev = curNode->prev;
  curNode->prev = newNode;

  if (curNode == head) {
    head = newNode;
  } else {
    newNode->prev->next = newNode;
  }
}

void addToHead(DList& head, DList& tail, const dtype& elem) {
  if (isEmpty(head)) {
    head = new Node_d(elem);
    tail = head;
  } else {
    addBeforeNode(head, head, elem);
  }
}

void deleteAfterNode(const DList& curNode, DList& tail) {
  DList delNode = curNode->next;
  if (delNode != nullptr) {
    curNode->next = delNode->next;
    if (delNode == tail) {
      tail = curNode;
    } else {
      delNode->next->prev = curNode;
    }

    delNode->next = nullptr;
    delNode->prev = nullptr;
    delete delNode;
    delNode = nullptr;
  }
}

void deleteBeforeNode(const DList& curNode, DList& head) {
  DList delNode = curNode->prev;
  if (delNode != nullptr) {
    curNode->prev = delNode->prev;
    if (delNode == head) {
      head = curNode;
    } else {
      delNode->prev->next = curNode;
    }

    delNode->next = nullptr;
    delNode->prev = nullptr;
    delete delNode;
    delNode = nullptr;
  }
}

void deleteCurrentNode(DList* head_ref, DList delNode) {
  if (*head_ref == nullptr || delNode == nullptr) return;

  if (*head_ref == delNode) *head_ref = delNode->next;

  if (delNode->next != nullptr) delNode->next->prev = delNode->prev;

  if (delNode->prev != nullptr) delNode->prev->next = delNode->next;

  delete delNode;
}

void Clear(DList& head, DList& tail) {
  while (!isEmpty(head)) {
    deleteCurrentNode(&head, head);
  }
}

int main() {
  DList head, tail;
  init(head, tail);
  addToHead(head, tail, 4);
  addToHead(head, tail, 3);
  addToHead(head, tail, 2);
  addToHead(head, tail, 1);
  addAfterNode(tail, tail, 5);
  printDList(head, tail);
  deleteAfterNode(tail, tail);
  printDList(head, tail);
  deleteAfterNode(tail->prev, tail);
  printDList(head, tail);
  deleteBeforeNode(head, head);
  printDList(head, tail);
  deleteBeforeNode(head->next, head);
  printDList(head, tail);
  deleteCurrentNode(&head, head);
  printDList(head, tail);
}
