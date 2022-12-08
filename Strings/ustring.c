/*
 * ustring.c
 *
 *  Created on: Dec 1, 2022
 *      Author: featomato
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split(char *original, char *first, char *second) {


     char *place = strchr(original, '@');
     printf("%lu \n", strlen(place));
     strcpy(second, place);
     strncpy(first, original, strlen(original) - strlen(place));

     printf("%s %s %s\n", original, first, second);
}

void clean(char *local) {
    int writer = 0;
    int reader = 0;

    while (local[reader]) {
        if (local[reader] == '+') {
            local[writer++] = '\n';
            break;
        }

        if (local[reader] != '.') {
            local[writer++] = local[reader];
        }
        reader++;
    }
    local[writer] = 0;
}

void stringTask ( ) {

	printf("Hello string 0\n");
	char *first = calloc(100, sizeof(char));
	char *second = calloc(100, sizeof(char));

	split("email@domain.com", first, second);

	printf("first: %s\n", first);
	printf("second: %s\n", second);

}

