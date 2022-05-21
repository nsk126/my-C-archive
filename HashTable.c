/**
 * @author: Suresh
 * @socials: https://twitter.com/SKrish_K
 * @contact: ksuresh3141@gmail.com
 * 
 * @brief: A very short hashtable implentation. Probably not ideal for applications.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 7

typedef struct
{
    char name[256];
    int age;

}HashTable;

HashTable * hash_table[TABLE_SIZE];
 
unsigned int hash(char *name)
{
    int length = strlen(name);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    
    return hash_value;
}

void init_hash(){
    
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    
}

void print_table(){
    
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] == NULL ? printf("\t%i\t---\n", i) : printf("\t%i\t%s\n", i, hash_table[i] -> name);

    }
    printf("\n");
}

bool hash_table_insert(HashTable * p)
{
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL)
    {
        return false;
    }
    hash_table[index] = p;
    return true;
}

HashTable * hash_delete(char *name)
{
    int index = hash(name);
    if(hash_table[index] != NULL &&
        strncmp(hash_table[index] -> name, name, TABLE_SIZE) == 0){
            HashTable *t1 = hash_table[index];
            hash_table[index] = NULL;
            return t1;
        } else {
            return NULL;
        }
}

HashTable * hash_lookup(char *name)
{
    int index = hash(name);
    if(hash_table[index] != NULL &&
        strncmp(hash_table[index] -> name, name, TABLE_SIZE) == 0){
            return hash_table[index];
        } else {
            return NULL;
        }

}

int main(void)
{
    init_hash();
    print_table();

    HashTable joshua = {.name = "Joshua", .age = 25};
    HashTable spring = {.name = "Spring", .age = 23};
    HashTable april = {.name = "April", .age = 31};
    HashTable lemon = {.name = "Lemon", .age = 29};
    
    hash_table_insert(&joshua);
    hash_table_insert(&spring);
    hash_table_insert(&lemon);
    print_table();

    HashTable *t1 = hash_lookup("Joshua");
    if (t1 == NULL)
    {
        printf("Not found\n");
    } else {
        printf("Found %s\n", t1 -> name);
    }

    t1 = hash_lookup("Melon");
    if (t1 == NULL)
    {
        printf("Not found\n");
    } else {
        printf("Found %s\n", t1 -> name);
    }
    
    t1 = hash_delete("Joshua");
    print_table();

    hash_table_insert(&april);
    print_table();
    
    
    return 0;
}
