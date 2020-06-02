//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_LINKEDLIST_H
#define NEURONET_LINKEDLIST_H

class LinkedList{
private:
    class ListItem{
    public:
        ListItem(void* v , ListItem *n, ListItem *p):value(v),next(n),prev(p){}
        void* value;
        ListItem *next;
        ListItem *prev;
    };

    ListItem *head;
    ListItem *tail;
    ListItem *sentinel;
    int size;

    void swap(ListItem &l1, ListItem &l2);
    ListItem* pos(int pos);
    ListItem* val(void* value,bool doAssert= false);
    void unlink(ListItem *p);



public:
    void add(void* value);
    void addAt(int pos, void* value);
    void removeAt(int pos);
    void remove(void* value);
    void *pop( void* value);
    void *popAt(int i);
    void *get(int pos);
    void set(int pos, void* value);
    void clear();
    void sort(int (*comp)(void* l,void* r));
    bool isEmpty();
    int getSize();




};
#endif //NEURONET_LINKEDLIST_H
