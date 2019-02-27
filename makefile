DEBUG ?= 1
ifeq (${DEBUG}, 1)
    CEXTFLAGS =-g3 -gdwarf-2 -DDEBUG
	TARGET =./debug
else
    CEXTFLAGS=-O3
	TARGET=./release
endif

INCLUDE=-I. \
		-I./incl

CXX 		= g++
CXXFLAGS 	= -std=c++11 ${CEXTFLAGS}
OBJDIR		= ${TARGET}/obj
main 	   ?= test/GraphTest.cpp
CCSRC 		= $(shell find ./src -name '*.cpp' -printf "src/%P ") 
OBJ			= $(CCSRC:%.cpp=${OBJDIR}/%.o)

LDFLAGS = -lGL -lglut -lpng -lz -lm

run: all
	./${TARGET}/test.elf


all: ${TARGET}/test.elf

${TARGET}/test.elf : ${TARGET}/obj/test.o ${OBJ}
	${CXX} ${CXXFLAGS} ${INCLUDE}  -o ${TARGET}/test.elf  ${OBJ} ${TARGET}/obj/test.o  

${TARGET}/obj/test.o: ${TARGET}/obj
	${CXX} ${CXXFLAGS} ${INCLUDE} -o $@ -c ${main}


${OBJDIR}/%.o: %.cpp ${TARGET}/obj
	mkdir -p ${TARGET}/obj/$(dir $*,o) ;\
	${CXX} ${CXXFLAGS} ${INCLUDE} -o $@ -c $<

${TARGET}/obj:
	@mkdir -p $@/obj

dbg_var:
	@echo "include dirs= ${INCLUDE}"
	@echo "c++ srcs    = ${CCSRC}"
	@echo "main        = ${main}"
	@echo "comp flags  = ${CXXFLAGS}"
	@echo "obj         = ${OBJ}"
	@echo "link flags  = ${LDFLAGS}"
	@echo "Debug       = ${DEBUG}"
	@echo "Target      = ${TARGET}"


clean:
	@rm -rf debug release
