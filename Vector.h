//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_VECTOR_H
#define NEURONET_VECTOR_H
template <typename T>
class Vector{
private:
    T* values;
     dim;
public:
    Vector(T* arrOfValues);
    int getDim();
    T* getValues();
};
#endif //NEURONET_VECTOR_H
