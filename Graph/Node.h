//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_NODE_H
#define NEURONET_NODE_H


#include "Functions/IFunction.h"

template<typename Definitionsbereich,typename Gradient>
class Node {
    //Definitionsbereich kann mehrdimensional sein und muss operator+() Implementieren
    IFunction<Definitionsbereich,double,Gradient> *f;
    Definitionsbereich bias;

public:
    explicit Node(IFunction<Definitionsbereich,double,Gradient> *function, Definitionsbereich bias):f(function),bias(bias){};
    double apply(Definitionsbereich d){
        return f->f(d+bias);
    }
};




#endif //NEURONET_NODE_H
