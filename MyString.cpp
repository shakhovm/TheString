//
// Created by user on 21.09.2019.
//
#include "MyString.h"

String str_create(size_t capacity)
{
    char* new_data = (char*)malloc(capacity);
    String new_string = {0, capacity, new_data};
    return new_string;
}

int strn_cmp(const String* str1, const String* str2, size_t n)
{

    for(size_t i = 0; i < n; ++i)
    {
        if(i > str2->size)
        {
            return 1;
        }
        if(i > str1->size)
        {
            return -1;
        }
        if(str1->data[i] > str2->data[i])
        {
            return 1;
        }
        if(str1->data[i] < str2->data[i]){
            return -1;
        }
    }


    return 0;
}
int str_cmp(const String *str1, const String *str2)
{
    size_t size = str1->size > str2->size ? str1->size : str2->size;
    return strn_cmp(str1, str2, size);
}

String strkn_cpy(const String* str, size_t k, size_t n)
{
    size_t j = k;
    size_t new_size = n - k;
    String new_string = str_create(new_size*2);
    new_string.size = new_size;
    for(size_t i = 0; i < new_size; ++i)
    {
        new_string.data[i] = str->data[j++];
    }

    return new_string;
}

String strn_cpy(const String *str, size_t n)
{
    return strkn_cpy(str, 0, n);
}
String str_cpy(const String* str)
{
    return strn_cpy(str, str->size);
}


int strn_cat(String *str1, const String *str2, size_t n)
{
    size_t j = str1->size;
    size_t i = 0;
    str1->size += n;
    if(str1->size < str1->capacity)
    {
        while(i < n)
        {
            str1->data[j++] = str2->data[i++];
        }
        return 0;
    }

    str1->capacity = str1->size*2;

    char *string_place = (char*)malloc(sizeof(char)*(str1->capacity));
    for(size_t k = 0; k < j; ++k)
    {
        string_place[k] = str1->data[k];
    }

    while(i < n)
    {
        string_place[j++] = str2->data[i++];
    }

    str1->data = string_place;

    return 0;
}

int str_cat(String *str1, const String *str2)
{
    return strn_cat(str1, str2, str2->size);
}


void str_lwr(String *str)
{
    for(size_t i = 0; i < str->size; ++i)
    {
        if(isupper(str->data[i]))
        {
            str->data[i] = (char)tolower((size_t)str->data[i]);
        }
    }
}

void str_upr(String *str)
{
    for(size_t i = 0; i < str->size; ++i)
    {

        if(islower(str->data[i]))
        {
            str->data[i] = (char)toupper((size_t)str->data[i]);
        }
    }
}

size_t search_substr(const String *main_str, const String *sub_str)
{
    for(size_t i = 0; i < main_str->size; ++i)
    {
        String new_str = strkn_cpy(main_str, i, i + sub_str->size);
        if(str_cmp(&new_str, sub_str) == 0)
        {
            return i;
        }
    }
    return -1;
}
size_t str_len(const String* str)
{
    return str->size;
}


size_t search_char(const String *str, char ch)
{
    for(size_t i = 0; i < str->size; ++i)
    {
        if(str->data[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int delete_substr(String* str, const String* substr) {
    size_t index = search_substr(str, substr);
    if (index == -1) {
        return -1;
    }
    for (size_t i = index; i < str->size; ++i)
    {
        if(i + str_len(substr) < str->size)
        {
            str->data[i] = str->data[i + str_len(substr)];
            free(str->data + i + str_len(substr));
        }
        else
        {
            free(str->data + i);
        }

    }
    str->size -= substr->size;
    return 0;
}

char* to_cstring(const String* str)
{
    char *cstring = (char*)malloc(sizeof(char)*str->size + 1);
    for(size_t i = 0; i < str->size; ++i)
    {
        cstring[i] = str->data[i];
    }
    cstring[str->size] = '\0';
    return cstring;
}

String from_cstring(const char* str)
{
    size_t str_size = strlen(str);
    String new_string = str_create(str_size*2);
    new_string.size = str_size;
    for(size_t i = 0; i < str_size; ++i)
    {
        new_string.data[i] = str[i];
    }

    return new_string;
}

void strprint(const String* str)
{
    for(size_t i = 0; i < str->size; ++i)
    {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

int cstrcmp(const String *str1, const char* str2)
{
    return strcmp(to_cstring(str1), str2);
}
