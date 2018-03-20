# This file should be called makefile
# Otherwise it wont compile
ODIR = Out

# Input and output
FILES = ./Helper/Helper.cpp \
		./main.cpp

FILES += ./Algorithms/Dynamic\ Programming/Knapsack.cpp \
		./Algorithms/Basics/Karatsuba.cpp \
		./Algorithms/Sorting/Quicksort.cpp \
		./Algorithms/Sorting/Mergesort.cpp \
		./Algorithms/Sorting/Bubble.cpp \
		./Algorithms/Sorting/Selection.cpp \
		./Algorithms/Sorting/Insertion.cpp

# Data structures
FILES += ./DS/Hashing/Hashing.cpp \
        ./DS/Queues/PriorityQueues.cpp \
		./DS/LinkedList/SinglyLinkedList.cpp

# Design patterns
# FILES += ./DesignPatterns/Behavioural/ChainOfResponsibility.cpp \
		./DesignPatterns/Inheritance.cpp \
        ./DesignPatterns/Behavioural/Command.cpp \
		./DesignPatterns/Behavioural/Iterator.cpp \
		./DesignPatterns/Behavioural/Interpreter.cpp

FILES += ./Helper/HackerRank.cpp \
        ./Helper/HackerEarth.cpp

OUT_EXE = out_exec

# define any directories containing header files other than /usr/include
INCLUDES = -I../Include

# define any compile-time flags
CFLAGS = -g

# Most makefiles have at least two basic components: macros and target definitions

############# MACROS ###################
# Macros are written in a simple x=y form. For instance, to set your C compiler to g++
CC = g++

#  To actually convert a macro into its value in a target, you simply enclose it within $(): 
# for instance, to convert CC into the name of the compiler
# $(CC) main.cpp

#	It is possible to specify one macro in terms of another; for instance, 
#  you could have a macro for the compiler options, OPT, and the compiler,
#  CC, combined into a compile-command, COMP:
COMP = $(CC) $(OPT)

############# TARGEt ###################

# Targets are the heart of what a makefile does: they convert a command-line input
# into a series of actions. For instance, the "make clean" command tells make to 
# execute the code that follows the "clean" target. Targets have three components: 
# the name of the target, the dependencies of the target, and finally the actions 
# associated with the target:

# target: [dependencies]
#        <command>
#        <command more>

# Typing "make" alone should generally result in some kind of reasonable behavior. 
# When you type "make" without specifying a target in the corresponding makefile, 
# 	it will simply execute the first target in the makefile

build: $(FILES)
	$(CC) $(CFLAGS) -o $(ODIR)/$(OUT_EXE) $(FILES)
	@echo  build is done

run:
	@echo  Running your program
	./$(ODIR)/$(OUT_EXE)


build_and_run: $(FILES)
	$(CC) $(CFLAGS) -o $(ODIR)/$(OUT_EXE) $(FILES)
	@echo  Build is done ...  running your program
	./$(ODIR)/$(OUT_EXE)

clean:
	rm -rf $(ODIR)/*.* *~ core $(INCDIR)/*~
