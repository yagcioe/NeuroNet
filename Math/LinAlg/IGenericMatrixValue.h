//
// Created by Oemer on 05.06.2020.
//

#ifndef NEURONET_IGENERICMATRIXVALUE_H
#define NEURONET_IGENERICMATRIXVALUE_H

#include <c++/4.8.3/string>

class IGenericMatrixValue{
public:
    virtual std::string *toString();
    virtual IGenericMatrixValue operator*(IGenericMatrixValue &o);
    virtual void operator=(IGenericMatrixValue &o);
    virtual IGenericMatrixValue clone();
};
#endif //NEURONET_IGENERICMATRIXVALUE_H
