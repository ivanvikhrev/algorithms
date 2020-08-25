// Copyright 2020 Vikhrev Ivan

#include <initializer_list>
#include <unordered_set>
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

List::List(const List& l) {
    head = new Node;
    Node* curr1 = head;
    Node* curr2 = l.head;
    while (curr2) {
        curr1->data = curr2->data;
        if (curr2->next == nullptr)
            curr1->next = nullptr;
        else
            curr1->next = new Node;
        curr1 = curr1->next;
        curr2 = curr2->next;
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

bool List::operator==(const List& l) const {
    Node* curr1 = head;
    Node* curr2 = l.head;

    while (curr1 && curr2) {
        if ((*curr1).data == curr2->data) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else {
            return false;
        }
    }

    return curr1 == curr2;
}

void List::remove_duplicates1() {
    std::unordered_set<int> s;
    if (!empty()) {
        s.insert(head->data);
        Node* prev = head;
        Node* curr = head->next;
        while (curr) {
            if (s.find(curr->data) == s.end()) {
                s.insert(curr->data);
                prev = prev->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
    }
}

void List::remove_duplicates2() {
    if (!empty()) {
        Node* p1 = head, *prev = head;
        Node* p2;
        while (p1) {
            p2 = p1->next;
            while (p2) {
                if (p1->data == p2->data) {
                    prev->next = p2->next;
                } else {
                    prev = prev->next;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
            prev = p1;
        }
    }
}

// not stable
void List::rearrangeBadImpl(int x) {
    Node* start, *end, *curr;
    start = end = curr = head;
    curr = curr->next;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        if (tmp->data < x) {
            tmp->next = start;
            start = tmp;
        } else {
            end->next = tmp;
            end = tmp;
        }
    }
    end->next = nullptr;
    head = start;
}

// stable
void List::rearrange(int x) {
    if (head) {
        Node *lessHead = nullptr, *lessCurr = nullptr,
             *greaterHead = nullptr, *greaterCurr = nullptr,
             *curr = nullptr;

        curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            if (tmp->data < x) {
                if (!lessHead) {
                    lessHead = tmp;
                    lessCurr = lessHead;
                } else {
                    lessCurr->next = tmp;
                    lessCurr = lessCurr->next;
                }
                lessCurr->next = nullptr;
            } else {
                if (!greaterHead) {
                    greaterHead = tmp;
                    greaterCurr = greaterHead;
                } else {
                    greaterCurr->next = tmp;
                    greaterCurr = greaterCurr->next;
                }
                greaterCurr->next = nullptr;
            }
        }
        if (lessHead) {
            head = lessHead;
            lessCurr->next = greaterHead;
        } else {
            head = greaterHead;
        }
    }
}

// assuming that 0 from end is end
int List::find_k_from_end(int k) {
    Node* curr = head;
    Node* kth = head;
    int i = 0;

    while (curr) {
        if (i > k) {
            kth = kth->next;
        }
        ++i;
        curr = curr->next;
    }

    return kth->data;
}
std::ostream& operator<<(std::ostream& os, const List& l) {
    Node *curr = l.head;
    if (l.head) {
        int i = 0;
        while (curr) {
            if (curr->next == nullptr)
                os << curr->data;
            else
                os << curr->data << "-->";
            i++;
            curr = curr->next;
        }
    } else {
        os << "empty";
    }
    return os;
}
