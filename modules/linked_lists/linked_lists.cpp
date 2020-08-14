// Copyright 2020 Vikhrev Ivan

#include <initializer_list>
#include "../../modules/linked_lists/linked_lists.h"

List::List(int n, int d) {
    head = new Node;
    Node* curr = head;
    int i = 0;
    while (i < n) {
        curr->data = d;
        if (i == n - 1) {
            curr->next = nullptr;
        } else {
            curr->next = new Node;
        }
        curr = curr->next;
        ++i;
    }
}

List::List(const std::initializer_list<int>& lst) {
    head = new Node;
    Node* curr = head;
    size_t i = 0;
    for (auto el : lst) {
        curr->data = el;
        if (i == lst.size() - 1) {
            curr->next = nullptr;
        } else {
            curr->next = new Node;
        }
        curr = curr->next;
        ++i;
    }
}

List::~List() {
    Node* curr = head;
    while (curr) {
        curr = head->next;
        delete head;
        head = curr;
    }
}

int List::back() const {
    if (head) {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        return curr->data;
    }
    return 0;
}

void List::push_back(int d) {
    if (head) {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(d);
    } else {
        head = new Node(d);
    }
}
