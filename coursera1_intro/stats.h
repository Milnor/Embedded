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
 * @file stats.h 
 * @brief Functions to calculate and print stats.
 *
 * Given a char array as input, perform statistical analysis and print results.
 *
 * @author Milnor
 * @date April 26, 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the stats of an array.
 *
 * A function that prints the statistics of an array including
 *  minimum, maximum, mean, and median.
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the arrray
 *
 */
void print_statistics(unsigned char * arrray, size_t length);

/**
 * @brief Print an array to the screen.
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the array
 *
 */
void print_array(unsigned char * array, size_t length);

/**
 * @brief Calculate the median value.
 *
 * Given an array of data and a length, returns the median value.
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the array
 *
 * @return median element
 */
unsigned char find_median(unsigned char * array, size_t length);

/**
 * @brief Calculate the mean.
 *
 * Given an array of data and length, returns the mean.
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the array
 *
 * @return mean average
 */
unsigned char find_mean(unsigned char * array, size_t length);

/**
 * @brief Determine the maximum value.
 *
 * Given an array of data and a length, returns the maximum.
 *
 * @param array an arraya of unsigned chars
 * @param length number of elements in the array
 *
 * @return largest element in array
 */
unsigned char find_maximum(unsigned char * array, size_t length);

/**
 * @brief Determine the minimum value.
 *
 * Given an array of data and a length, returns the minimum.
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the array
 *
 * @return smallest element in array
 */
unsigned char find_minimum(unsigned char * array, size_t length);

/**
 * @brief Sort an array from largest to smallest.
 *
 * Given an array of data and a length, sorts the array from largest to
 * smallest. (Zeroth element is largest and last element (n-1) is
 * smallest).
 *
 * @param array an array of unsigned chars
 * @param length number of elements in the array
 *
 * @return 0 on success, 1 otherwise
 */
int sort_array(unsigned char * array, size_t length);

#endif /* __STATS_H__ */
