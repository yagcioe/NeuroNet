//
// Created by Oemer on 02.06.2020.
//

#include <c++/4.8.3/cassert>
#include <zconf.h>
#include "LinkedList.h"

//private Utility functions
void LinkedList::swap(LinkedList::ListItem &l1, LinkedList::ListItem &l2) {
    void *temp = l1.value;
    l1.value = l2.value;
    l2.value = temp;
}

LinkedList::ListItem *LinkedList::pos(int pos) {
    assert(pos > -size && pos < size && "Index out of Range");
    ListItem *p = head;
    if (pos < 0) {
        for (int i = pos; i != 0; i++) {
            p = p->prev;
        }
    } else {
        for (int i = pos; i != 0; i--) {
            p = p->next;
        }
    }
    return p;
}

LinkedList::ListItem *LinkedList::val(void *value, bool doAssert) {
    ListItem *l = head;
    for (int i = 0; i < size; ++i) {
        if (l->value == value) { return l; }
        l = l->next;
    }
    assert(doAssert && "Value not Found!");
    return sentinel;
}


//Main Methods
void LinkedList::add(void *value) {
    ListItem l(value, sentinel, tail);
    l.prev->next = &l;
    l.next->prev = &l;
    if (isEmpty()) {
        head = &l;
    }
    tail = &l;
    size++;
}

void LinkedList::addAt(int pos, void *value) {
    size++;
    ListItem *p = LinkedList::pos(pos);

    ListItem l(value, p->prev, p);
    if (size == 1) {
        head = &l;
    }
    if (pos == size - 1) {
        tail = &l;
    }
    p->next->prev = &l;
    p->next = &l;

}

void LinkedList::remove(void *value) {
    ListItem *p = val(value);
    if (p != sentinel) {
        unlink(p);
        size--;
        p->~ListItem();
    }
}

void LinkedList::removeAt(int pos) {
    ListItem *p = LinkedList::pos(pos);
    unlink(p);
    size--;
    p->~ListItem();
}

void *LinkedList::pop(void *value) {
    ListItem *p = val(value);
    if (p != sentinel) {
        void *temp = p->value;
        unlink(p);
        size--;
        p->~ListItem();
        return temp;
    }

    return nullptr;
}

void LinkedList::unlink(LinkedList::ListItem *p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;


}

void *LinkedList::popAt(int i) {
    return nullptr;
}











