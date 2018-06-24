
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
		./DesignPatterns/Inheritance.cpp \
        ./DesignPatterns/Behavioural/Command.cpp \
		./DesignPatterns/Behavioural/Iterator.cpp \
		./DesignPatterns/Behavioural/Interpreter.cpp \
		./DesignPatterns/Creational/Singleton.cpp \
		./DesignPatterns/Creational/FactoryMethod.cpp \
		./DesignPatterns/Structural/Facade.cpp

# FILES += $(DATA_STRUCTS)
# FILES += $(DESIGN_PATTERNS)
FILES += $(DATA_STRUCTS)

FILES += ./Helper/Hacker.cpp
