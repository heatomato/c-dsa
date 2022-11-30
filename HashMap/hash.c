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

typedef struct NODE {
	char *key;
	char *value;
	//int hash;
	struct NODE *next;
} NODE;

typedef struct HashMap {
	NODE **entries;
	size_t entriesCount;
	size_t size;
} HashMap;

HashMap * initHashMap(int tableSize) {

	// Allocate the map
	HashMap *map = malloc(sizeof(HashMap));


	if (map == NULL) return NULL;
	printf("HashMap initialized\n");

	map->entriesCount = tableSize;


	map->entries = calloc(map->entriesCount, sizeof(NODE*) * map->entriesCount);
	if (map->entries == NULL) {
		printf("Failed HashMap initialization\n");
		free(map);
		return NULL;
	}

	map->size = tableSize;
	for (int i = 0; i < map->size; i++) {
		map->entries[i] = NULL;
	}

	printf("HashMap initialized\n");

	return map;

}

void printMap(HashMap *map) {
	printf("printing hashmap %ld \n",  map->size);
	for (int i = 0; i < map->size; i++) {

		NODE *node = map->entries[i];

		if (node != NULL) {
			//printf("%i - [%s]:[%p]\n",i, (char *) map->entries[i]->key, map->entries[i]->value );
			for (;;) {
				printf("%i - [%s]:[%p]\n",i, (char *) node->key, node->value );

				if(node->next == NULL) break;
				node = node->next;
			}
		} else {
			printf("%i - null\n",i);
		}
	}
}


unsigned int hash(char *key, int tableSize) {
	unsigned int length = strlen(key);
	unsigned int hashValue = 0;

	for (int i = 0; i < length; i++) {
		hashValue = hashValue * 37 + key[i];
	}
	hashValue = hashValue % tableSize;
	printf("hashValue:%u\n", hashValue);
	return hashValue;
}

bool hset(HashMap *map, char* key, char *value) {

	unsigned int slot = hash(key, map->size);

	// Find out if entry exist
	NODE *entry = map->entries[slot];
	if (entry == NULL) {
		// Empty slot, insert
		NODE *node = malloc(sizeof(NODE)  * 1);
		node->value = malloc(strlen(value) +1);
		node->key = malloc(strlen(key) + 1);
		node->next = NULL;

		strcpy(node->key, key);
		strcpy(node->value, value);

		// Save that entry
		map->entries[slot] = node;
		printf("inserted new node: %s,%s\n", map->entries[slot]->key, map->entries[slot]->value);
		return true;

	} else {
		// Two keys whith same hash or collition
		NODE *prev = NULL;
		while (entry != NULL) {
			// Check key
			if (strcmp(entry->key, key) == 0) {
				free(entry->value);
				entry->value = malloc(strlen(value) +1);
				strcpy(entry->value, value);
				printf("same key, updating value: %s,%s\n", entry->key, entry->value);
				return true;
			}

			// Walk to next
			prev = entry;
			entry = prev->next;
		}

		// End for chain add new pair because collision
		NODE *node = malloc(sizeof(NODE) * 1);
		node->key = malloc(strlen(key) +1);
		node->value = malloc(strlen(value) +1);
		node->next = NULL;

		strcpy(node->key, key);
		strcpy(node->value, value);
		prev->next = node;
		printf("different key, updating value: %s,%s\n", node->key, node->value);
		return false;
	}

}



/*
 *
 *
 * void initHashTable() {
     memset(hashTable, 0, TABLE_SIZE -1);
}

unsigned int hashNumber(int value) {
	unsigned int index = value;
	index = value % TABLE_SIZE;
	return index;
}
unsigned int hashChar(char character) {
	unsigned int hashValue = 0;
	hashValue = character - 'a'; // a -> 0, z -> 25
	return hashValue;
}

char *hashNumberHex( int value ) {
    static char valueString[12];
    memset(valueString, 0, 12);

    if (value < 0) {
        sprintf(valueString, "%x\n", value*-1 + 100);
    }  else {
        sprintf(valueString, "%x\n", value);
    }

    printf("hashNumberHex: %s\n", valueString);

    return valueString;
}

unsigned int hashString( char *valueString, int mapSize ) {
	int length = strlen(valueString);
	unsigned int hashValue = 0;
	for (int i = 0; i < length; i++) {
		hashValue += valueString[i];
		hashValue = (hashValue * valueString[i]) % mapSize;
	}

    printf("valueString:%s %d\n", valueString, hashValue);

    return hashValue;
}

bool hput( int value ) {
	unsigned int index = hashString(hashNumberHex(value), 100);
	if (hashTable[index] != hashString(hashNumberHex(value), 100)) {
		return false;
	} else {
		hashTable[index] = value;
		return true;
	}
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

void countCharacters(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		printf("string:%c, hash:%i\n ", string[i], hashChar(string[i]) );
		unsigned int index = hashChar(string[i]);
		hashTable[index] += 1;
	}

}



void printTable() {

	for (int i = 0; i < TABLE_SIZE; i++) {
		printf("[%i]:%i\n", i, hashTable[i]);
	}
}

*/

bool containsDuplicate( int* nums, int numsSize ){
    // Create a hashmap
    int size = 1000;
   HashMap *map = initHashMap(size);

    /*
     hset(map, "1", "1");
     hset(map, "1", "1");

     hset(map, "2", "1");
     hset(map, "-1", "-1");
     hset(map, "-3", "-3");
    */


    // Iterate over nums array
    // Check if num exist in hashmap
    /**/
    char hexString[12];
    char valueString[12];
    bool repeated = false;
    for (int i = 0; i < numsSize; i++) {
        //printf("nums[%i]:%i\n", i, nums[i]);

        sprintf(hexString,"%x", nums[i]);
        sprintf(valueString, "%x", nums[i]);

        bool result = hset(map, hexString, valueString);
        if (result == false) {
            repeated = true;
            break;
        }

    }

   //printMap(map) ;

    // Add num as index in hashmap
    return repeated;

}


void hashTask() {

	HashMap *map = initHashMap(5);
	//printMap(map);

	/**/
	hset(map, "israel", "somethisn");
	hset(map, "nelly", "other2");

	hset(map, "israel", "somethisn2");

	hset(map, "manuel", "como");
	hset(map, "wendo", "peraza");
	hset(map, "henry", "cabil");
	hset(map, "zazil", "alheli");
	hset(map, "cire", "rojas");

	printMap(map);

	char hex[12];
	memset(hex, 0, 12);

	sprintf(hex, "%X", 1);
	hset(map, hex, hex);

	sprintf(hex, "%X", 2);
	hset(map, hex, hex);

	sprintf(hex, "%X", 3);
	hset(map, hex, hex);
	sprintf(hex, "%X", 4);
	hset(map, hex, hex);

	sprintf(hex, "%X", 1);
	hset(map, hex, hex);

	sprintf(hex, "%X", -1);
	hset(map, hex, hex);

	sprintf(hex, "%X", -3);
	hset(map, hex, hex);


    //hset(map, "hexString", "valueString");
    //hset(map, "hexStrin2g", "valueString");
    //hset(map, "hexSt2ring", "valueString");

	printMap(map);

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
	//countCharacters("abcdz");


	//hashNumberHex(1);
	//hashNumberHex(2);
	//hashNumberHex(3);
	//hashNumberHex(1);
	//hashNumberHex(-3);

	//hput(0);
	//hput(1);
	//hput(2);
	//hput(3);



	//printTable();







}
