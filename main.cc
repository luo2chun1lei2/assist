#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "MyEngine.h"
#include "MyControl.h"
#include "MyStorage.h"
#include "MyView.h"

static const char *_sopts = "hf:u:r:t:l:w:a:";
static const struct option _lopts[] = { {"help", no_argument, 0, 'h'},
{"unitest", required_argument, 0, 'u'},
{"file", required_argument, 0, 'f'},
{"repeat", required_argument, 0, 'r'},
{"test_item", required_argument, 0, 't'},
{"load_by_haid", required_argument, 0, 'l'},
{"load_by_haid_wait", required_argument, 0, 'w'},
{"arg", required_argument, 0, 'a'},
{0, 0, 0, 0}
};

static const char *usage =
    "Usage: %s [options]\n"
    "\n"
    "options:\n"
    "  -h, --help            prints this message and exit\n"
    "  -a, --arg             start app with this argument.\n" "\n";

static void print_usage_and_exit(const char *prog, int code)
{
	fprintf(stderr, usage, prog);
	exit(code);
	
}

int main(int argc, char *argv[])
{
	printf("start assist\n");

	int c;
	int oidx = 0;

	while (1) {
		c = getopt_long(argc, argv, _sopts, _lopts, &oidx);
		if (c == -1)
			break;	/* done */

		switch (c) {
		case 'h':
			print_usage_and_exit(argv[0], EXIT_SUCCESS);
			break;
		default:
			print_usage_and_exit(argv[0], EXIT_FAILURE);
			break;
		}
	}

/**
    Dot dot;
    dot.create("invoke function");
    dot.show();
    dot.close(); */

	MyEngine engine;
	MyControl control;
	MyView view;
	MyStorage storage;
	
	engine.addControl(&control);
	engine.addView(&view);
	engine.addStorage(&storage);

	return 0;
}
