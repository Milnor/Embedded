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
#include <stdlib.h>     // Is this against the rules? I want calloc/free.
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
    print_statistics(test, SIZE);
    printf("UNSORTED:\n");
    print_array(test, SIZE);
    printf("SORTED:\n");
    if (0 != sort_array(test, SIZE)) 
    {
        fprintf(stderr, "[-] sort failed\n");
    }
    else
    {
        print_array(test, SIZE);
    }
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char * array, size_t length)
{
    printf("Minimum = %d\n", find_minimum(array, length));
    printf("Maximum = %d\n", find_maximum(array, length));
    printf("Mean    = %d\n", find_mean(array, length));
    printf("Median  = %d\n", find_median(array, length));
}

void print_array(unsigned char * array, size_t length)
{
    printf("Array of size %zu:\n", length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
        if (0 == (length % 16)) // line wrap
        {
            printf("\n");
        }
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

// TODO: optimize me! this is effectively bubblesort from Schaffer, p. 236
int sort_array(unsigned char * array, size_t length)
{
    if (NULL == array)
    {
        return 1;
    }

    for (size_t i = 0; i < (length - 1); i++)
    {
        for (size_t j = (length - 1); j > i; j--)
        {
            if (array[j] > array[(j-1)])
            {
                /* swap! */
                unsigned char temp = array[j];
                array[j] = array[(j-1)];
                array[(j-1)] = temp;
            }
        }
    }
    return 0;
}

unsigned char find_median(unsigned char * array, size_t length)
{
    /* Probably cleaner to copy the array than to mess with the
     * original array*/
    unsigned char median = 0;
    unsigned char * copy = calloc(length, sizeof(unsigned char));
    if (NULL == copy)
    {
        fprintf(stderr, "[-] calloc failed\n");
        goto fail;
    }
    for (size_t i = 0; i < length; i++)
    {
        copy[i] = array[i];
    }

    if (0 != sort_array(copy, length))
    {
        goto fail;
    }

    if (1 == (length % 2))
    {
        // odd number of elements
        median = array[(length / 2) +1];
    }
    else
    {
        // even number of elements
        size_t middle = length / 2;
        unsigned int sum = array[middle] + array [middle - 1];
        median = sum / 2;
    }
    free(copy);

    return median;

fail:
    /* no error return value available due to API limitation */
    fprintf(stderr, "[-] median failed\n");
    return (unsigned char) -1;    
}

