#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directls.h"
// #include "sort.h"

static int compare_dir(const void *key1, const void *key2) {
    int retval;
    if((retval = strcmp(((const Directory *)key1) -> name, ((const Directory *) key2) -> name)) > 0) {
        return 1;
    } else if(retval < 0) {
        return -1;
    } else {
        return 0;
    }
}

int directls(const char *path, Directory **dir) {
    DIR *dirptr;
    Directory *temp;
    struct dirent *curdir;
    int count, i;
    if((dirptr = opendir(path)) == NULL) {
        return -1;
    }
    *dir = NULL;
    count = 0;
    while((curdir = readdir(dirptr)) != NULL) {
        count++;
        if((temp = (Directory *) realloc(*dir, count * sizeof(Directory))) == NULL) {
            free(*dir);
            return -1;
        } else {
            *dir = temp;
        }
        strcpy(((*dir)[count - 1]).name, curdir->d_name);
    }
    closedir(dirptr);
    return count;
}
   
int main() {
    Directory *d1;
    // d1 = malloc(sizeof(Directory));
    // strcpy(d1 -> name, "test_directory");
    // struct Directory d1;
    // d1.name = "test_directory";
    int dirSize = directls("/home/kiki/git", &d1);
    printf("%d\n", dirSize);
    // printf("%s\n", d1->name);
    // printf("%s\n", (d1 + 1)->name);
    // printf("%s\n", (d1 + 2)->name);
    for(int i = 0; i < dirSize; i++) {
        printf("%s\n", (d1 + i)->name);
    }
    return 0;
}