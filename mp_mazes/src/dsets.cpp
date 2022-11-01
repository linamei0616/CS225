/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num) {
    for (int i = 0; i < num; i++) {        
        djset_.push_back(-1);
    }
}
int DisjointSets::find(int elem) {
    if (djset_[elem] < 0) { 
        return elem; 
    }
    return find(djset_[elem]);
}
void DisjointSets::setunion(int a, int b) {
    int aset = find(a);
    int bset = find(b);

    if (aset == bset) {
        // djset_[bset] = aset;
        return;
    }

	int newSize = djset_[aset] + djset_[bset];

	if (djset_[aset] <= djset_[bset]) { 
		djset_[bset] = aset; 
		djset_[aset] = newSize;
        return;
	}
    djset_[aset] = bset; 
    djset_[bset] = newSize; 
}
int DisjointSets::size(int elem) {
    while (djset_[elem] >= 0) {
        elem = djset_[elem];
    }
    return djset_[elem] * -1;
}
