//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_NODE_H
#define NEURONET_NODE_H
class Node{
private:
    double (*func)(double weight);
public:
    Node(double (*f)(double) );



};

#endif //NEURONET_NODE_H
