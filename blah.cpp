
#include "backingStore.hpp"
#include "MemoryManager.hpp"
#include "MMU.hpp"
#include "RAM.hpp"
#include "Word.hpp"

using namespace std;

void test_MMU() {
    Address logAddr;
    logAddr.value_ = 123;
    MMU MemManagerUnit;
    
    MemManagerUnit.read(logAddr);

    cout << MemManagerUnit.return_test() << endl;
}