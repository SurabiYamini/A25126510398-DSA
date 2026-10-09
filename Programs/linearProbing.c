/* Linear probing */ 
#include <stdio.h> 
#include <stdlib.h> 
#define TABLE_SIZE 5 
#define EMPTY -1 
#define DELETED -2 
int hashTable[TABLE_SIZE]; 
void initializeHashTable() 
{ 
 for (int i = 0; i < TABLE_SIZE; i++) 
 { 
 hashTable[i] = EMPTY; 
 } 
} 
int hashFunction(int key) 
{ 
 return (key % TABLE_SIZE); 
} 
void insert(int key) 
{ 
 int index = hashFunction(key); 
 int original_index = index; 
 while (hashTable[index] != EMPTY && hashTable[index] != DELETED)  { 
 if (hashTable[index] == key) 
 { 
 printf("Key %d already exists.\n",key); 
 return; 
 } 
 index = (index + 1) % TABLE_SIZE; 
 if (index == original_index) 
 { 
 printf("\nHash table is full.Cannot insert %d.\n", key); 
 return; 
 } 
 } 
 hashTable[index] = key; 
 printf("Key %d inserted at index %d.\n", key, index); 
} 
int search(int key) 
{ 
 int index = hashFunction(key); 
 int original_index = index; 
 while (hashTable[index] != EMPTY) 
 { 
 if (hashTable[index] == key)
 return index; 
 index = (index + 1) % TABLE_SIZE;
 if (index == original_index) 
 break; 
 } 
 return -1; 
} 
void delete_hash(int key) 
{ 
 int index = search(key); 
 if (index!= -1) 
 { 
 hashTable[index] = DELETED; printf("Key %d deleted from index %d.\n",key,  index); 
 } else 
 { 
printf("Key %d not found in hash table.\n",  key); 
 } 
} 
void display() 
{ 
 printf("\nHash Table:\n"); 
 for (int i = 0; i < TABLE_SIZE; i++)  { 
 if (hashTable[i]==EMPTY) 
 printf("Index %d: EMPTY\n", i);  else if (hashTable[i]==DELETED)  printf("Index %d: DELETED\n", i);  else 
 printf("Index %d: %d\n", i, 
 hashTable[i]); 
 } 
 } 
int main() 
{ 
 initializeHashTable(); 
 insert(5); insert(15); 
 insert(25); insert(6); 
 insert(16); insert(26); insert(33); 
 /* insert(43); 
 insert(31); 
 insert(32); 
 insert(62); 
 */ 
 display(); 
 int search_key = 15; 
 int found_index = search(search_key);  if (found_index != -1) {
 printf("\nKey %d found at index %d.\n",search_key, found_index); 
 } 
 else
{ 
 printf("\nKey %d not found.\n", search_key);  } 
 delete_hash(15); 
 display(); 
 search_key = 15; 
 found_index = search(search_key); 
 if (found_index != -1) { 
 printf("\nKey %d found at index %d.\n", 
 search_key, found_index); 
 } else { 
 printf("\nKey %d not found.\n", 
 search_key); 
 } 
 return 0; 
} 
