#include "MyView.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <limits.h>

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

    char *tmp_name = tempnam(NULL, NULL);
    char dot_path[PATH_MAX];
    sprintf(dot_path, "%s.dot", tmp_name);
    char out_path[PATH_MAX];
    sprintf(out_path, "%s.jpg", tmp_name);
    free(tmp_name);

    printf("dot file is %s,\njpg file is %s\n", dot_path, out_path);
    
    FILE * file = fopen(dot_path, "w+");

    for(uint i=0; i<sizeof(strings)/sizeof(strings[0]); i++) {
        fwrite(strings[i], strlen(strings[i]), 1, file);
    }

    fclose(file);


	// execute the dot.
    char command[PATH_MAX];
    sprintf(command, "dot -Tjpg %s -o %s", dot_path, out_path);
    int rc = system(command);
    if (!rc) {
		perror(NULL);
	}
	
	sprintf(command, "eog %s", out_path);
	
	rc = system(command);
    if (!rc) {
		perror(NULL);
	}
}
