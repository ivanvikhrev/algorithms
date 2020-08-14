// Copyright 2020 Vikhrev Ivan

#include <initializer_list>
#ifndef MODULES_LINKED_LISTS_LINKED_LISTS_H_
#define MODULES_LINKED_LISTS_LINKED_LISTS_H_

struct Node {
    Node* next;
    int data;
    Node() : next(nullptr), data(0) {}
    explicit Node(int d) : next(nullptr), data(d) {}
    Node(Node* n, int d) : next(n), data(d) {}
    bool operator==(const Node& n) const { return (data == n.data && next == n.next); }
  bool operator!=(const Node& n) const { return !(*this == n); }
};

class List {
 private:
    Node* head;
 public:
    List() : head(nullptr) {}
    explicit List(int d) {head = new Node(d);}
    List(int n, int d);
    List(const std::initializer_list<int>& lst);
    ~List();
    Node* get_head() const { return head; }
    void push_front(int d) { head = new Node(head, d); }
    void push_back(int d);
    int front() const { return head ? head->data : 0; }
    int back() const;
    bool empty() const { return head; }
};

#endif  // MODULES_LINKED_LISTS_LINKED_LISTS_H_
