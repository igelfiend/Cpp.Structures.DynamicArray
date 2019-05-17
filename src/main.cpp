#include <iostream>

#include "dynarraytest.h"

using namespace std;

int main()
{
    DynArrayTest dynTest;

    //! Test "append" operator
    dynTest.testAppendCaseNormal();
    dynTest.testAppendCaseCapacityExceeded();

    //! Test "get_item" operator
    dynTest.testGetItemCaseNormal();
    dynTest.testGetItemCaseNegativeIndex();
    dynTest.testGetItemCaseTooLargeIndex();

    //! Test "insert" operator
    dynTest.testInsertCaseNormal();
    dynTest.testInsertCaseTooLowIndex();
    dynTest.testInsertCaseTooBigIndex();
    dynTest.testInsertCaseEndOfArray();
    dynTest.testInsertCaseBufferIncreased();

    //! Test "remove" operator
    dynTest.testRemoveCaseNormal();
    dynTest.testRemoveCaseNegativeIndex();
    dynTest.testRemoveCaseTooLargeIndex();
    dynTest.testRemoveCaseDecreaseBuffer();
    dynTest.testRemoveCasePreventBufferDecreasingWithMinCapacity();

    //! Show total results
    dynTest.showResult();

    return 0;
}
