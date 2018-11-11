#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <iterator>
#include <sstream>

// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers


using namespace std;

// ################ TEST FUNCTIONS ################ //

// Inheritance
void workWithAnimals();

/* ####### Design Patterns ####### */

// Chain of Responsibility
void testChainOfResponsibility();

// Command
void testCommandPattern();

// Interpreter
void testInterpreterPattern();

// Iterator 
void testIteratorPattern();


/* ####### Algorithms ####### */

// Basics
void testKaratsuba();

// Dynamic programming
void testKnapsack();

// Sorting 
void testQuickSort();
void testMergeSort();
void testBubbleSort();
void testSelectionSort();
void testInsertionSort();

// Basic 
void testQuickSelect();

// Hashing
void testHashing();

void testPriorityQueues();

/* ####### Misc ####### */

// Helper 
void print1DArray(int *arr, int n);
void print1DArray(int *arr, int low, int high);

void swap(int *numbers, int a, int b);

// Class for InterviewBit 

// For the template 
int  tmain();

