# all:
# 	# g++ -g -Wall -I${CURDIR}/Catch/include/ ${CURDIR}/HashTable/test.cpp -o ${CURDIR}/HashTable/assoc.out && valgrind --tool=callgrind --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes ${CURDIR}/HashTable/assoc.out
# 	g++ -pg -O -Wall -I${CURDIR}/Catch/include/ ${CURDIR}/tests/test_spec.cpp ${CURDIR}/Model/*.cpp ${CURDIR}/Model/Book/*.cpp ${CURDIR}/lib/Config.cpp -o ${CURDIR}/shhh && ${CURDIR}/shhh

#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = -I${CURDIR}/Catch/include/

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS =

# define the C source files
SRCS = tests/test_spec.cpp Collection/Collection.cpp Collection/Books.cpp Model/Model.cpp Model/Book.cpp Model/Book/Periodical.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

MAIN = shhh

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#
#
.PHONY: depend clean

all:	$(MAIN)
		@echo  shhh has been compiled

$(MAIN):	$(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) ./*/*/*.o ./*/*.o *.o *~ $(MAIN)

depend:	$(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
