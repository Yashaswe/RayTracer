/*
 * Light.cpp
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#include "Light.h"

ostream& operator<<(ostream& os , const Light& l ){
    os << "Light: " << l.pos << ", " << l.color;
    return os;
}

istream& operator>> (istream& is , Light& l){
    string word;
    is >> word ;
    is >> l.pos;
    is >> l.color;
    is >> word;

    return is;
}
