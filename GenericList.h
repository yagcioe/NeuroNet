//
// Created by Oemer on 03.06.2020.
//

#ifndef NEURONET_GENERICLIST_H
#define NEURONET_GENERICLIST_H


#include "LinkedList.h"
template <class T>
class GenericList : LinkedList::LinkedList{

    class Iterator:LinkedList::Iterator{
    public:
        T next() override;
    };

    bool deleteValue(void* value);
    bool deleteAt(int i);
    T *pop() override ;
    T *pop(void *value) override ;
    T *popAt(int i) override ;
    T *get(int i) override ;
};




#endif //NEURONET_GENERICLIST_H
