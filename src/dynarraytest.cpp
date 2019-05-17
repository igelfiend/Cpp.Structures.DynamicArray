#include "dynarraytest.h"

#include <iostream>

#define TEST_START(x) string testName((x)); _countTests++
#define TEST_RESULT(x) _fTotalResult &= x;\
    _countSuccess += int(x);\
    cout << ((x) ? " Passed" : " Failed")<< " Test: " << testName << endl

using namespace std;

DynArrayTest::DynArrayTest():
    _fTotalResult( true ),
    _countTests  ( 0 ),
    _countSuccess( 0 )
{

}

void DynArrayTest::reset()
{
    _fTotalResult = true;
    _countTests   = 0;
    _countSuccess = 0;
}

void DynArrayTest::testAppendCaseNormal()
{
    TEST_START("Append case normal");

    DynArray array = prepareArray( 6 );

    array.append( 10 );

    bool result =   ( array.capacity == 16 )
                 && ( array.count    == 7  );

    TEST_RESULT(result);
}

void DynArrayTest::testAppendCaseCapacityExceeded()
{
    TEST_START("Append case capacity exceeded");
    DynArray array = prepareArray( 16 );

    array.append( 42 );

    bool result =   ( array.count == 17 )
                 && ( array.capacity == 32 );

    TEST_RESULT(result);
}

void DynArrayTest::testGetItemCaseNormal()
{
    TEST_START("Get item case normal");

    DynArray array = prepareArray( 10 );

    bool result = ( array.get_item( 5 ) == 5 );

    TEST_RESULT(result);
}

void DynArrayTest::testGetItemCaseNegativeIndex()
{
    TEST_START("Get item case negative index");

    DynArray array = prepareArray( 10 );

    bool result = ( array.get_item( -2 ) == -1 );

    TEST_RESULT(result);
}

void DynArrayTest::testGetItemCaseTooLargeIndex()
{
    TEST_START("Get item case to large index");

    DynArray array = prepareArray( 10 );

    bool result = ( array.get_item( 10 ) == -1 );

    TEST_RESULT(result);
}

void DynArrayTest::testInsertCaseNormal()
{
    TEST_START("Insert case normal");

    DynArray array = prepareArray( 4 );

    //! Insert "5" on 2 pos
    array.insert( 5, 2 );

    int checkArray[] = {0, 1, 5, 2, 3};
    bool result =   compareArray( array, checkArray, 5 )
                 && ( array.capacity == 16 );

    TEST_RESULT(result);
}

void DynArrayTest::testInsertCaseTooLowIndex()
{
    TEST_START("Insert case too low index");

    DynArray array = prepareArray( 4 );

    //! Insert "5" on -2 pos
    array.insert( 5, -2 );

    int checkArray[] = {0, 1, 2, 3};
    bool result = compareArray( array, checkArray, 4 );

    TEST_RESULT(result);
}

void DynArrayTest::testInsertCaseTooBigIndex()
{
    TEST_START("Insert case to big index");

    DynArray array = prepareArray( 4 );

    //! Insert "5" on 5 pos
    array.insert( 5, 5 );

    int checkArray[] = {0, 1, 2, 3};
    bool result = compareArray( array, checkArray, 4 );

    TEST_RESULT(result);
}

void DynArrayTest::testInsertCaseEndOfArray()
{
    TEST_START("Insert case end of array");

    DynArray array = prepareArray( 4 );

    //! Insert "5" on 4 pos
    array.insert( 5, 4 );

    int checkArray[] = {0, 1, 2, 3, 5};
    bool result =   compareArray( array, checkArray, 5 )
                 && ( array.capacity == 16 );

    TEST_RESULT(result);
}

void DynArrayTest::testInsertCaseBufferIncreased()
{
    TEST_START("Insert case buffer increased");

    DynArray array = prepareArray( 15 );

    //! Insert "5" on 5 pos
    array.insert( 5, 4 );

    //! Insert "7" on 10 pos
    array.insert( 7, 10 );

    int checkArray[] = {0,  1,  2,  3,  5,
                        4,  5,  6,  7,  8,
                        7,  9,  10, 11, 12,
                        13, 14};
    bool result =   compareArray( array, checkArray, 17 )
                 && ( array.capacity == 32 );

    TEST_RESULT(result);
}

void DynArrayTest::testRemoveCaseNormal()
{
    TEST_START("Remove case normal");

    DynArray array = prepareArray( 25 );

    //! Remove at 7 pos
    array.remove( 7 );

    int checkArray[] = {0,  1,  2,  3,  4,
                        5,  6,  8,  9,  10,
                        11, 12, 13, 14, 15,
                        16, 17, 18, 19, 20,
                        21, 22, 23, 24};
    bool result =   compareArray( array, checkArray, 24 )
                 && ( array.capacity == 32 );

    TEST_RESULT(result);
}

void DynArrayTest::testRemoveCaseNegativeIndex()
{
    TEST_START("Remove case negative index");

    DynArray array = prepareArray( 25 );

    //! Remove at -2 pos
    array.remove( -2 );

    int checkArray[] = {0,  1,  2,  3,  4,
                        5,  6,  7,  8,  9,
                        10, 11, 12, 13, 14,
                        15, 16, 17, 18, 19,
                        20, 21, 22, 23, 24};
    bool result =   compareArray( array, checkArray, 25 )
                 && ( array.capacity == 32 );

    TEST_RESULT(result);
}

void DynArrayTest::testRemoveCaseTooLargeIndex()
{
    TEST_START("Remove case too large index");

    DynArray array = prepareArray( 25 );

    //! Remove at 30 pos
    array.remove( 30 );

    int checkArray[] = {0,  1,  2,  3,  4,
                        5,  6,  7,  8,  9,
                        10, 11, 12, 13, 14,
                        15, 16, 17, 18, 19,
                        20, 21, 22, 23, 24};
    bool result =   compareArray( array, checkArray, 25 )
                 && ( array.capacity == 32 );

    TEST_RESULT(result);
}

void DynArrayTest::testRemoveCaseDecreaseBuffer()
{
    TEST_START("Remove case decrease buffer");

    DynArray array = prepareArray( 20 );

    //! Remove at 10 pos
    array.remove( 10 );

    int checkArray[] = {0,  1,  2,  3,  4,
                        5,  6,  7,  8,  9,
                        11, 12, 13, 14, 15,
                        16, 17, 18, 19};
    bool result =   compareArray( array, checkArray, 19 )
                 && ( array.capacity == 21 );

    TEST_RESULT(result);
}

void DynArrayTest::testRemoveCasePreventBufferDecreasingWithMinCapacity()
{
    TEST_START("Remove case prevent buffer decreasing with min capacity");

    DynArray array = prepareArray( 10 );

    //! Remove at 5 pos
    array.remove( 5 );

    int checkArray[] = {0,  1,  2,  3,  4,
                        6,  7,  8,  9};
    bool result =   compareArray( array, checkArray, 9 )
                 && ( array.capacity == 16 );

    TEST_RESULT(result);
}

void DynArrayTest::showResult()
{
    cout << " ----------------------------------\n";
    cout << " Total tests: " << _countTests << endl;
    cout << " Passed: " << _countSuccess << endl;
    cout << " Failed: " << _countTests - _countSuccess << endl;
    cout << " Total result: " << ( ( _fTotalResult ) ? "Passed" : "Failed" ) << endl;
}

DynArray DynArrayTest::prepareArray(size_t count)
{
    DynArray result;

    for( size_t i = 0; i < count; ++i )
    {
        result.append( int( i ) );
    }

    return result;
}

bool DynArrayTest::compareArray(const DynArray &checkedArray, int correctArray[], size_t count)
{
    if( int(count) != checkedArray.count )
    {
        cout << "compareArray: failed. Arrays count different: "
             << count << " and " << checkedArray.count << endl;
        return false;
    }

    for( int i = 0; i < int( count ); ++i )
    {
        if( checkedArray.get_item( i ) != correctArray[ i ] )
        {
            cout << "compareArray: failed. At item " << i << " values are "
                 << checkedArray.get_item( i ) << " and " << correctArray[ i ] << endl;
            return false;
        }
    }

    return true;
}
