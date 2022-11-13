/*
 * hash.c
 *
 *  Created on: Nov 8, 2022
 *      Author: israel
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 100
#define NAME_SIZE 256

typedef struct {
	char name[NAME_SIZE];
	int age;
} NODE;


NODE *hashmap[TABLE_SIZE];
int hashTable[26];

void initHashMap() {
	/**/
	for (int i = 0; i < 26; i++) {
		//hashmap[i] = NULL;
		hashTable[i] = 0;

	}


}

unsigned int hash(char *name) {
	int length = strlen(name);
	unsigned int hashValue = 0;
	for (int i = 0; i < length; i++) {
		hashValue += name[i];
		hashValue = (hashValue * name[i]) % TABLE_SIZE;
	}
	return hashValue;
}

unsigned int hashChar(char character) {
	unsigned int hashValue = 0;
	hashValue = character - 'a'; // a -> 0, z -> 25
	return hashValue;
}


bool hset(NODE *n) {
	if (n == NULL) {
		return false;
	}

	int index = hash(n->name);

	if (hashmap[index] != NULL) {
		printf("Repeated key %d\n", index);
		return false;
	}

	hashmap[index] = n;

	return true;
}

NODE *hget(char *name) {
	// Get hashed index
	unsigned int index = hash(name);

	// Check if exits
	if ( hashmap[index] != NULL) {
		return hashmap[index];
	}else {
		return NULL;
	}
}

bool hdel(char *name) {
	unsigned int index = hash(name);

	// Check if exist
	if ( hashmap[index] != NULL) {
		hashmap[index] = NULL;
		return true;
	} else {
		// Doesn't exist
		return false;
	}

}


void printMap() {
	for (int i = 0; i < 26; i++) {
		if (hashmap[i] != NULL) {
			printf("%i:%s\n",i, hashmap[i]->name );
		} else {
			printf("%i:%s\n", i, hashmap[i]->name);
		}
	}
}

void printTable() {
	for (int i = 0; i < 26; i++) {
		printf("[%i]:%i\n", i, hashTable[i]);
	}
}

void countCharacters(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		printf("string:%c, hash:%i\n ", string[i], hashChar(string[i]) );
		unsigned int index = hashChar(string[i]);
		hashTable[index] += 1;
	}

}

void hashTask() {

	initHashMap();
	//printf("%s:%i\n", "Hello", hash("Hello"));
	//printf("%s:%i\n", "my", hash("my"));
	//printf("%s:%i\n", "Love", hash("Love"));

	//NODE israel = {.name="Israel", .age=34};
	//NODE nelly = {.name="Nelly", .age=34};
	//NODE aleli = { .name="Alheli", .age=32};

	//hset(&israel);
	//	hset(&nelly);
	//hset(&aleli);

	//printf("Searching %s = %s\n", "Nelly", hget("Nelly")->name);
	//printf("Searching %s = %s\n", "David", hget("David")->name);

	//hdel("Nelly");


	// Save number of characters in function
	countCharacters("abcdz");


	printTable();




}
