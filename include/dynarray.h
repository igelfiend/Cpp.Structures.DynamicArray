#include <stdio.h>

#include <iostream>

class DynArray
{
private:
    double _coefIncreaseBuffer;
    double _coefDecreaseBuffer;
    int _minCapacity;

public:
    int count;
    int capacity;
    int *array;  // stores positive values
    DynArray():
        _coefIncreaseBuffer( 2.0 ),
        _coefDecreaseBuffer( 1.5 ),
        _minCapacity( 16 ),
        count   ( 0 ),
        capacity( 0 ),
        array   ( nullptr )
    {
        count = 0;
        make_array(16);
    }

    void make_array(int new_capacity)
    {
//        std::cout << "make_array: started called with capacity " << new_capacity << std::endl;
//        std::cout << "make_array: setting capacity " << new_capacity << std::endl;

        //! Check with lower bound
        if( new_capacity < _minCapacity )
        {
            new_capacity = _minCapacity;
        }

        //! Check for reassign same capacity
        if( new_capacity == capacity )
        {
//            std::cout << "make_array: Same capacity, return\n";
            return;
        }

        //! Checking if we trying to set new capacity less then count of items
        if( count > new_capacity )
        {
            count = new_capacity;
        }

        //! Relocate array with new capacity
        int *newArray = new int[ size_t( new_capacity ) ];
        for( int i = 0; i < count; ++i )
        {
            newArray[ i ] = array[ i ];
        }

//        std::cout << "make_array: deleting old array";
        //! Clear old memory
        delete[] array;

        //! Update pointer
        array = newArray;

        capacity = new_capacity;
//        std::cout << "make_array: successfully finished\n";
    }

    int get_item(int index) const
    {
        if(  ( index >= 0 )
          && ( index < count ) )
        {
            return array[ index ];
        }
        else
        {
            return -1;
        }
    }

    void append(int value)
    {
        increaseBuffer();
        array[ count ] = value;
        ++count;
    }

    void insert(int value, int index)
    {
        //! Check if index is out of bounds
        if(   ( index < 0 )
           || ( index > count ) )
        {
            return;
        }

//        //! Check if we trying to add element in the end of array
//        if( index == count )
//        {
//            append( value );
//            return;
//        }


        increaseBuffer();

        //! Shift all elements to the right
        for( int i = count; i > index; --i )
        {
            array[ i ] = array[ i-1 ];
        }

        array[ index ] = value;
        ++count;
    }

    void remove(int index)
    {
        //! Check if index is out of bounds
        if(   ( index < 0 )
           || ( index >= count ) )
        {
            return;
        }

        for( int i = index; i < count-1; ++i )
        {
            array[ i ] = array[ i+1 ];
        }

        decreaseBuffer();

        --count;
    }

private:
    /**
     * @brief Checks if we need to increase capacity size (and perform it)
     */
    void increaseBuffer()
    {
        //! Check if we reach max capacity
        if( count == capacity )
        {
            //! Increase capacity
            make_array( int( _coefIncreaseBuffer * capacity ) );
            return;
        }
    }

    /**
     * @brief Checks if we need to decrease capacity size (and perform it)
     */
    void decreaseBuffer()
    {
        //! Check if we capacity dropped down, so we can decrease it
        int capacityDecreaseSize = int( capacity / _coefDecreaseBuffer );
        if( count < capacityDecreaseSize )
        {
            //! Decrease capacity
            make_array( capacityDecreaseSize );
        }
    }
};
