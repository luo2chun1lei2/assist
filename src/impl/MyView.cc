#include "MyView.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void MyView::show()
{
    // TODO fake

static const char * strings[] = {
"  digraph G {",
"      node1;",
"      node2;",
"      node3;",
"  ",
"      node1 -> node2 [label=\"edge_1_2\"];",
"      node1 -> node3 [label=\"edge_1_3\"];",
"      node2 -> node3 [label=\"edge_2_3\"];",
"    }"};

    char fn[] = "XXXXXX.dot";
    int fd = mkstemps(fn, 4);

    printf("create file name is %s", fn);

    close(fd);
    if (1)return;
    FILE * file = fopen(fn, "w+");

    for(uint i=0; i<sizeof(strings)/sizeof(strings[0]); i++) {
        fwrite(strings[i], strlen(strings[i]), 1, file);
    }

    fclose(file);


    //"dot -Tjpg test.dot -o test.jpg"
}
