
# Input and output
FILES = ./Helper/Helper.cpp \
		./main.cpp


BASICS =  ./Algorithms/Dynamic\ Programming/Knapsack.cpp \
		./Algorithms/Basics/Karatsuba.cpp \
		./Algorithms/Basics/Quickselect.cpp

SORTING = ./Algorithms/Sorting/Quicksort.cpp \
		./Algorithms/Sorting/Mergesort.cpp \
		./Algorithms/Sorting/Bubble.cpp \
		./Algorithms/Sorting/Selection.cpp \
		./Algorithms/Sorting/Insertion.cpp

# Data structures
DATA_STRUCTS = ./DS/Hashing/Hashing.cpp \
        ./DS/Queues/PriorityQueuesList.cpp \
		./DS/Heaps/Heap.cpp \
		./DS/Heaps/HeapPriorityQueues.cpp \
		./DS/LinkedList/SinglyLinkedList.cpp \
		./DS/Graphs/MinimumCuts.cpp

GRAPS = ./DS/Graphs/BFS.cpp \
        ./DS/Graphs/DFS.cpp \
		./DS/Graphs/MinimumCuts.cpp

# Searching 
SEARCHING = ./Algorithms/Searching/BoyerMoore.cpp \
			./Algorithms/Searching/RobinKarp.cpp

# Design patterns
DESIGN_PATTERNS = ./DesignPatterns/Behavioural/ChainOfResponsibility.cpp \
		./Design\ Patterns/Inheritance.cpp \
        ./Design\ Patterns/Behavioural/Command.cpp \
		./Design\ Patterns/Behavioural/Iterator.cpp \
		./Design\ Patterns/Behavioural/Interpreter.cpp \
		./Design\ Patterns/Creational/Singleton.cpp \
		./Design\ Patterns/Creational/FactoryMethod.cpp \
		./Design\ Patterns/Structural/Facade.cpp

# Select what you want to compile here
# FILES += $(DATA_STRUCTS)
FILES += $(DESIGN_PATTERNS)
FILES += $(SORTING)

FILES += ./Helper/Hacker.cpp
