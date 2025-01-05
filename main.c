#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "datatype.h"

// #define SA 1


void main()
{
    datatype * array1 = calloc(ARRAY_SIZE, sizeof(datatype));
    datatype * array2 = calloc(ARRAY_SIZE, sizeof(datatype));

    #ifdef SA
        int * tmpArray = calloc(ARRAY_SIZE, sizeof(int));
    #endif

    //fill array1 with data
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        array1[i].data = ARRAY_SIZE-i;
    }

    float startTime = (float)clock()/CLOCKS_PER_SEC;

    #ifdef SA
        //copy over data to small array
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
            tmpArray[i] = array1[i].data;
        }
        
        //copy over data from small array to big array
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
            array2[i].data = tmpArray[i];
        }
    #else
        //copy over data
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
            array2[i].data = array1[i].data;
        }
    #endif

    float endTime = (float)clock()/CLOCKS_PER_SEC;

    printf("time elapsed %f\n", endTime - startTime);

    srand ( time(NULL) );
    int index = rand() % ARRAY_SIZE;
    printf("array entry[%i]: %i\n", index, array2[index].data);
}