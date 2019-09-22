#ifndef THESTRING_MYSTRING_H
#define THESTRING_MYSTRING_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct String{
    size_t size;
    size_t capacity;
    char* data;
} String;

String str_create(size_t capacity);

int free_string(String* string)
{
    free(string->data);
    string->data = 0;
    string->size = 0;
    string->capacity = 0;
    return 0;
}

//Print string
void strprint(const String* str);

//Compare two strings
int str_cmp(const String* str1, const String* str2);

//Compare first n elements of string
int strn_cmp(const String* str1, const String* str2, size_t n);

//Copy from k to n element of string
String strkn_cpy(const String* str, size_t k, size_t n);

//Copy first n elements
String strn_cpy(const String* str, size_t n);

//Copy full string
String str_cpy(const String* str);

//Add first n elements of one string to another
int strn_cat(String *str1, const String *str2, size_t n);

//Add two strings
int str_cat(String *str1, const String *str2);

//Convert string to lowercase
void str_lwr(String *str);

//Convert string to uppercase
void str_upr(String *str);

//Return the index of beginning of substring
size_t search_substr(const String *main_str, const String *sub_str);

//delete substring in string
int delete_substr(String* str, const String* substr);

size_t str_len(const String* str);

//Return index of char
size_t search_char(const String *str, char ch);

//Convert cstring to String
String from_cstring(const char* str);

//Convert String to cstring
char *to_cstring(const String *str);

//Compare String with cstring
int cstrcmp(const String *str1, const char* str2);


#endif //THESTRING_MYSTRING_H


