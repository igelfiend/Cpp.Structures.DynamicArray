#ifndef DYNARRAYTEST_H
#define DYNARRAYTEST_H

#include "dynarray.h"
#include <string>

//!
//! \brief The DynArrayTest class used for testing DynArray class
//!
class DynArrayTest
{
public:
    DynArrayTest();
    void reset();

    void testAppendCaseNormal();
    void testAppendCaseCapacityExceeded();

    void testGetItemCaseNormal();
    void testGetItemCaseNegativeIndex();
    void testGetItemCaseTooLargeIndex();

    void testInsertCaseNormal();
    void testInsertCaseTooLowIndex();
    void testInsertCaseTooBigIndex();
    void testInsertCaseEndOfArray();
    void testInsertCaseBufferIncreased();

    void testRemoveCaseNormal();
    void testRemoveCaseNegativeIndex();
    void testRemoveCaseTooLargeIndex();
    void testRemoveCaseDecreaseBuffer();
    void testRemoveCasePreventBufferDecreasingWithMinCapacity();

    void showResult();

private:
    bool compareArray( const DynArray &checkedArray, int correctArray[], size_t count );
    DynArray prepareArray(size_t count);

    bool _fTotalResult;
    int  _countTests;
    int  _countSuccess;
};

#endif // DYNARRAYTEST_H
