#ifndef __POOL_H_
#define __POOL_H_

#include <vector>
#include "Forme.h"

class Pool {
    private:
        vector<Forme*> _array;
    public:
        Pool();
        ~Pool();
        void add(Forme *f);
        void del(Forme *f);
        // void sort_by_z();
        void dessiner(CImage *img);
        void print_pool();
};


#endif // __POOL_H_
