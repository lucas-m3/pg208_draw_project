#include "Pool.h"

Pool::Pool() {}

// Pool::~Pool() {
//     for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
//         delete (*it);
//     }
//     _array.clear();
// }

void Pool::add(Forme *f) {
    _array.push_back(f);
}
void Pool::del(Forme *f) {
    //TODO search f in array and _array.erase() it
}

void Pool::dessiner(CImage *img) {
    for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
        (*it)->dessiner(img);
    }
}
