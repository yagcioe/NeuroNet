//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_IFUNCTION_H
#define NEURONET_IFUNCTION_H

template <class Defintionsbereich,class Bild>
class IFunction {
    virtual Bild f(Defintionsbereich x);
};


#endif //NEURONET_IFUNCTION_H
