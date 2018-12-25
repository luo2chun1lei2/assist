
# Manual config
CPP=g++
CC=gcc
STRIP=objcopy --strip-all --strip-debug
FORMAT=indent

TARGET=assist
CPP_FLAGS=-g
CC_FLAGSS=-g
LDFLAGS=-g

SRC_FOLDER=./ fwk impl

# AUTO config
# - all *.c/*.cc are source, and header files are *.h
SRC_CC:=$(foreach d,${SRC_FOLDER},$(wildcard ${d}/*.cc))
SRC_CC_OBJ:=$(patsubst %,out/%.o,${SRC_CC})

SRC_C:=$(foreach d,${SRC_FOLDER},$(wildcard ${d}/*.c))
SRC_C_OBJ:=$(patsubst %,out/%.o,${SRC_C})

SRC_H:=$(foreach d,${SRC_FOLDER},$(wildcard ${d}/*.[h|hpp]))
ALL_SRC:=${SRC_CC} ${SRC_C} ${SRC_H}

CC_FLAGS += $(foreach d,${SRC_FOLDER},-I${d})
CPP_FLAGS+= $(foreach d,${SRC_FOLDER},-I${d})

out/%.c.o : %.c
	@mkdir -p `dirname $@`
	@$(CC) $(CC_FLAGS) -c $< -o out/$<.o

out/%.cc.o : %.cc
	@mkdir -p `dirname $@`
	@$(CPP) $(CPP_FLAGS) -c $< -o out/$<.o

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
	../tools/Lindent.sh ${ALL_SRC}
