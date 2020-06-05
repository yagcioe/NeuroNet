//
// Created by Oemer on 05.06.2020.
//

#ifndef NEURONET_IMATRIXVALUE_H
#define NEURONET_IMATRIXVALUE_H


#include <string>

template<class thisClass>
class IMatrixValue{
public:

    virtual std::string *toString();
    virtual thisClass operator*(thisClass &o);
    virtual void operator=(thisClass &o);
    virtual bool operator==(thisClass &o);
    virtual thisClass clone();
};
#endif //NEURONET_IMATRIXVALUE_H
