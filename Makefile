
# Manual config
CPP=g++
CC=gcc
STRIP=objcopy --strip-all --strip-debug
FORMAT=indent

TARGET=assist
CPP_FLAGS=-g
CC_FLAGSS=-g
LDFLAGS=-g

# AUTO config
# - all *.c/*.cc are source, and header files are *.h
SRC_CC:=$(wildcard *.cc)
SRC_CC_OBJ:=$(patsubst %,out/%.o,${SRC_CC})

SRC_C:=$(wildcard *.c)
SRC_C_OBJ:=$(patsubst %,out/%.o,${SRC_C})

SRC_H:=$(wildcard *.[h|hpp])
ALL_SRC:=${SRC_CC} ${SRC_C} ${SRC_H}

out/%.c.o : %.c
	@mkdir -p `dirname $@`
	@$(CC) $(CPP_FLAGS) -c $< -o out/$<.o

out/%.cc.o : %.cc
	@mkdir -p `dirname $@`
	@$(CPP) $(CC_FLAGS) -c $< -o out/$<.o

# Public targets.

all:build

build: ${SRC_C_OBJ} ${SRC_CC_OBJ}
	@$(CPP) $(LDFLAGS) $^ -o out/${TARGET}.unstrip
	@$(STRIP) out/${TARGET}.unstrip out/${TARGET}

run: build
	@out/${TARGET}

clean:
	@rm -rf out *~

# format all sources.
format:
	./Lindent.sh ${ALL_SRC}
