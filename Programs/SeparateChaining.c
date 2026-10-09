#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
// Node structure for linked list
typedef struct Node {
int data;
struct Node* next;
} Node;
// Hash table: array of pointers to linked lists
Node* hashTable[TABLE_SIZE];
// Hash function
int hash(int key) {
return key % TABLE_SIZE; }
// Insert a key into the hash table
void insert(int key) {
int index = hash(key);
Node* newNode = (Node*)malloc(sizeof(Node));
if (!newNode) {
printf("Memory allocation failed\n");
return;
}
newNode->data = key;
newNode->next = hashTable[index];
hashTable[index] = newNode;
printf("Inserted %d at index %d\n", key, index);
}
// Search for a key in the hash table
int search(int key) {
int index = hash(key);
Node* temp = hashTable[index];
while (temp) {
if (temp->data == key)

return 1;
temp = temp->next;

}
return 0;
}
// Delete a key from the hash table
void delete(int key) {
int index = hash(key);
Node* temp = hashTable[index];
Node* prev = NULL;
while (temp) {
if (temp->data == key) {

if (prev)
prev->next = temp->next;

else
hashTable[index] = temp->next;

free(temp);
printf("Deleted %d from index %d\n", key, index);

return;
}
prev = temp;
temp = temp->next;

}
printf("Key %d not found\n", key);
}
// Display the hash table
void display() {
for (int i = 0; i < TABLE_SIZE; i++) {
printf("Index %d:", i);
Node* temp = hashTable[i];
while (temp) {
printf(" %d ->", temp->data);
temp = temp->next;
}
printf(" NULL\n");
}
}
// Main function to demonstrate the hash table operations
int main() {
// Initialize hash table
for (int i = 0; i < TABLE_SIZE; i++)
hashTable[i] = NULL;
// Sample operations
insert(15);
insert(25);
insert(35);
insert(20);
insert(30);
display();
printf("Search for 25: %s\n", search(25) ? "Found" : "Not Found");
printf("Search for 40: %s\n", search(40) ? "Found" : "Not Found");
delete(25);
delete(40);
display();
return 0;
}
