#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    // Return empty string if input array is empty
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    // Start with the first string as the initial prefix
    char* prefix = strs[0];
    int prefix_len = strlen(prefix);

    // Compare prefix with every other string in the array
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Match characters one by one
        while (j < prefix_len && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        // Shorten the prefix length to the matched length
        prefix_len = j;
        
        // Early exit if prefix becomes empty
        if (prefix_len == 0) {
            break;
        }
    }

    // Allocate exact memory for the result and copy it
    char* result = (char*)malloc(prefix_len + 1);
    strncpy(result, prefix, prefix_len);
    result[prefix_len] = '\0'; // Ensure null-termination

    return result;
}
