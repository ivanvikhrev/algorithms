// Copyright 2020 Vikhrev Ivan

#include <initializer_list>
#include <iostream>
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
    List(const List& l);
    List(const std::initializer_list<int>& lst);
    ~List();
    Node* get_head() const { return head; }
    void push_front(int d) { head = new Node(head, d); }
    void push_back(int d);
    int front() const { return head ? head->data : 0; }
    int back() const;
    bool empty() const { return !head; }
    bool operator==(const List& l) const;
    bool operator!=(const List& l) const {return !(*this == l);}
    friend std::ostream& operator<<(std::ostream& os, const List& l);
    void remove_duplicates1();
    void remove_duplicates2();
    void rearrangeBadImpl(int x);
    void rearrange(int x);
    int find_k_from_end(int k);
};

#endif  // MODULES_LINKED_LISTS_LINKED_LISTS_H_
