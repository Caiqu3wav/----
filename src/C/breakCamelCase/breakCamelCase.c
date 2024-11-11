#include <stddef.h> // NULL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  int charLength = strlen(camelCase);
  
  char *result = malloc(charLength * 2);

  int j = 0;

  for (int i = 0; i < charLength; i++) {
    if (camelCase[i] >= 'A' && camelCase[i] <= 'Z' && i != 0) {
        result[j++] = ' ';
    }
       result[j++] = camelCase[i];
  }
  result[j] = '\0';

  return result;
  free(result);
}