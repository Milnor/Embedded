/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Display stats of a char array.
 *
 * Given an array of unsigned chars, print out the minimum, maximum, mean,
 *  and median.
 *
 * @author Milnor
 * @date April 30, 2022
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
    
    print_array(test, SIZE);
    printf("min = %d\n", find_minimum(test, SIZE));
    printf("max = %d\n", find_maximum(test, SIZE));
    printf("mean = %d\n", find_mean(test, SIZE));
}

/* Add other Implementation File Code Here */

// TODO: wrap to max of 16 per line
void print_array(unsigned char * array, size_t length)
{
    printf("Array of size %zu:\n", length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Assumes integer division is desired behavior */
unsigned char find_mean(unsigned char * array, size_t length)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / length;
}

unsigned char find_minimum(unsigned char * array, size_t length)
{
    unsigned char smallest = array[0];
    for (size_t i = 1; i < length; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
    }
    return smallest;
}

unsigned char find_maximum(unsigned char * array, size_t length)
{
    unsigned char biggest = array[0];
    for (size_t i = 1; i < length; i++)
    {
        if (array[i] > biggest)
        {
            biggest = array[i];
        }
    }
    return biggest;
}
