#include "Pool.h"

Pool::Pool() {}

Pool::~Pool() {
    for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
        delete (*it);
    }
    _array.clear();
}

void Pool::add(Forme *f) {
    _array.push_back(f);
}
void Pool::del(Forme *f) {
    //TODO search f in array and _array.erase() it
}

void Pool::sort_by_z() {
    Forme* tmp;
    for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
        for(vector<Forme*>::iterator it_comp = _array.begin(); it_comp != _array.end(); it_comp++) {
            if( (*it_comp)->get_z_index() > (*it)->get_z_index() ) {
                tmp = *it_comp;
                *it_comp = *it;
                *it = tmp;
            }
        }
    }
}

void Pool::dessiner(CImage *img) {
    sort_by_z();
    for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
        (*it)->dessiner(img);
    }
}

void Pool::print_pool() {
    cout << "Pool: tag (z_index)" << endl;
    for(vector<Forme*>::iterator it = _array.begin(); it != _array.end(); it++) {
        cout << "\t" << (*it)->get_tag() << " (" << (*it)->get_z_index() << ") "<< endl;
    }
}
