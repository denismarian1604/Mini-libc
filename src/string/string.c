// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    // no memory is allocated for destination string
    if (destination == NULL)
        return NULL;

    // pointer to original address of destination & source
    char *init_dest = destination;
    const char *init_source = source;

    // copy the data
    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    // end the newly created string
    *destination = '\0';

    // reset destination & source addresses to the initial ones
    destination = init_dest;
    source = init_source;

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    // no memory is allocated for destination or source string
    if (destination == NULL || source == NULL)
        return NULL;

    // pointer to original address of destination & source
    char *init_dest = destination;
    const char *init_source = source;

    // copy the data
    while (*source && len)
    {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    // end the newly created string
    if (len > 0)
        *destination = '\0';

    // reset destination & source addresses to the initial ones
    destination = init_dest;
    source = init_source;

    return destination;
}

char *strcat(char *destination, const char *source)
{
    // no memory is allocated for destination string
    if (!destination)
        return NULL;

    // pointer to original address of destination & source
    char *init_dest = destination;
    const char *init_source = source;

    // move destination at its end
    destination += strlen(destination);

    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    // end the newly created string
    *destination = '\0';

    // reset destination & source addresses to the initial ones
    destination = init_dest;
    source = init_source;

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    /// no memory is allocated for destination string
    if (!destination)
        return NULL;

    // pointer to original address of destination & source
    char *init_dest = destination;
    const char *init_source = source;

    // move destination at its end
    destination += strlen(destination);

    while (*source && len)
    {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    // end the newly created string
    *destination = '\0';

    // reset destination & source addresses to the initial ones
    destination = init_dest;
    source = init_source;

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
    // while neither strings ended
    while (*str1 && *str2)
    {
        // if characters differ
        if (*str1 != *str2)
            break;

        str1++;
        str2++;
    }

    // check which string is "bigger"
    if (*(const unsigned char *)str1 > *(const unsigned char *)str2)
        return 1;
    else if (*(const unsigned char *)str1 == *(const unsigned char *)str2)
        return 0;
    else
        return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    // while neither strings ended
    while (*str1 && *str2 && len > 1)
    {
        // if characters differ
        if (*str1 != *str2)
            break;

        str1++;
        str2++;
        len--;
    }

    // check which string is "bigger"
    if (*(const unsigned char *)str1 > *(const unsigned char *)str2)
        return 1;
    else if (*(const unsigned char *)str1 == *(const unsigned char *)str2)
        return 0;
    else
        return -1;
}

size_t strlen(const char *str)
{
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c)
{
    // narrow the character we got as int to char
    char cChar = (char)c;

    // while the string hasn't ended
    while (*str)
    {
        // if the character is found, return the address to it
        if (*str == cChar)
            return ((char *)str);

        str++;
    }

    // if the character isn't found, return NULL
    return NULL;
}

char *strrchr(const char *str, int c)
{
    // narrow the character we got as int to char
    char cChar = (char)c;
    // pointer to retain newest occurence of cChar in str
    char *found = NULL;

    // while the string hasn't ended
    while (*str)
    {
        // if the character is found, return the address to it
        if (*str == cChar)
            found = (char *)str;

        str++;
    }

    // if the character occured at least once, return the address to it
    if (found)
        return found;

    // if the character isn't found, return NULL
    return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    // while the haystack string is not finished
    while (*haystack)
    {
        if (*haystack == *needle)
        {
            // copies to the original pointers
            const char *init_haystack = haystack;
            const char *init_needle = needle;

            // while the strings exist
            while (*haystack && *needle)
            {
                // if there is a mismatch, break the loop
                if (*haystack != *needle)
                    break;

                haystack++;
                needle++;
            }

            // if the needle has ended, it means it has been found
            if (*needle == '\0')
                return (char *)init_haystack;

            // if this point is reached, needle is yet to be found
            haystack = init_haystack + 1;
            needle = init_needle;
        }

        haystack++;
    }

    // if this point is reached, needle wasn't found
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    // while the haystack string is not finished
    char *last_occurence = NULL;

    while (*haystack)
    {
        if (*haystack == *needle)
        {
            // copies to the original pointers
            const char *init_haystack = haystack;
            const char *init_needle = needle;

            // while the strings exist
            while (*haystack && *needle)
            {
                // if there is a mismatch, break the loop
                if (*haystack != *needle)
                    break;

                haystack++;
                needle++;
            }

            // if the needle has ended, it means it has been found
            if (*needle == '\0')
                last_occurence = (char *)init_haystack;

            /*
            if this point is reached, needle either wasn't found or
            was found at least once before
            */
            haystack = init_haystack + 1;
            needle = init_needle;
        }

        haystack++;
    }

    // if we have at least one occurence of needle
    if (last_occurence)
        return last_occurence;
    else
        return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    /*
    convert source and destination to char *
    as it is the only data type represented on one byte
    */
    char *src = (char *)source;
    char *dest = (char *)destination;

    // copy each byte
    for (size_t cnt = 0; cnt < num; cnt++)
        dest[cnt] = src[cnt];

    // return the destination
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    /*
    convert destination to char *
    as it is the only data type represented on one byte
    */
    char *dest = (char *)destination;

    // use temp to prevent data loss from source
    const size_t kCnt = num;
    char temp[kCnt];

    memcpy((void *)temp, (const void *)source, num);

    // copy each byte
    for (size_t cnt = 0; cnt < num; cnt++)
        dest[cnt] = temp[cnt];

    // return the destination
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    /*
    convert ptr1 and ptr2 to char *
    as it is the only data type represented on one byte
    */
    char *ptr1_char = (char *)ptr1;
    char *ptr2_char = (char *)ptr2;

    // compare each byte until a difference is found
    size_t cnt;

    for (cnt = 0; cnt < num; cnt++)
        if (ptr1_char[cnt] != ptr2_char[cnt])
            break;

    if (cnt == num)
        cnt--;
    // return the comparing result
    if (ptr1_char[cnt] > ptr2_char[cnt])
        return 1;
    else if (ptr1_char[cnt] == ptr2_char[cnt])
        return 0;
    else
        return -1;
}

void *memset(void *source, int value, size_t num)
{
    // convert source to char * to work with each byte
    char *src = (char *)source;
    // convert value to unsinged char
    unsigned char val = (unsigned char)value;

    // copy val num times
    while (num)
    {
        *src = val;
        src++;
        num--;
    }

    return source;
}
