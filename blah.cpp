
#include "backingStore.h"
#include "MemoryManager.h"
#include "MMU.h"
#include "RAM.h"
#include "Word.h"

using namespace std;

void test_MMU() {
    Address logAddr;
    logAddr.value_ = 123;
    MMU MemManagerUnit;
    
    MemManagerUnit.read(logAddr);

    cout << MemManagerUnit.return_test() << endl;
}