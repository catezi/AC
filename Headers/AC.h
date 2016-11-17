#ifndef AC_H_INCLUDED
#define AC_H_INCLUDED



#endif // AC_H_INCLUDED
#define patternnum 4
#define ASCII 256


#include <iostream>
#include <string.h>
#include <malloc.h>
#include <queue>

extern const char pattern[patternnum][30];

typedef struct node{
    struct node *next[ASCII];
    struct node *par;
    struct node *fail;
    char inputchar[2];
    int patterTag;
    int patterNo;
}*Tree,TreeNode;

void startmatch(char *buff, int len, int successnum[]);
bool judge(int successnum[]);
