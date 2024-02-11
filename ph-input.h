#pragma once

#include <stdbool.h>

/**
 * Checks if string is valid ph value
 */
bool isValidPhValue(const char* str);

/**
 * Retrieves the pesos part of string
 *
 * @param str String to be retrieved 
 *
 * Example usage:
 * getPesos("125.32");  // Returns 125
 */
int getPesos(const char* str);

/**
 * Retrieves the centavos part of string
 *
 * @param str  String to be retrieved
 *
 * Example usage:
 * getCentavos("125.32"); // Returns 32
 */
int getCentavos(const char* str);
