#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());

    //test extra
    smm.add(1, 2);
    smm.add(1, 3);
    smm.add(1, 4);
    smm.add(1, 5);
    smm.add(2, 6);
    smm.add(3, 7);
    smm.add(3, 8);
    smm.add(3, 9);
    smm.add(3, 10);
    smm.add(3, 11);
    smm.add(3, 12);
    smm.add(3, 13);
    smm.add(4, 14);
    smm.add(4, 15);
    smm.add(4, 16);
    smm.add(4, 17);
    smm.add(4, 18);
    //std::cout<<smm.trimValues(3);
    assert(smm.trimValues(3)==7);

}

