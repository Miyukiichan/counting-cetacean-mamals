Readme for CS23820 Assignment - Counting the Cetacean Mammals of Cardigan Bay
Author Sam Matthews - sam82

Introduction:
This is a school project based around parsing text data, storing it in appropriate data structures and subsequently processing it. It demonstrates the use of C/C++ and an understanding of standard libraries and ADT's. More information can be found in the writeup.

Files:
Each half of the assignment is located in their own separate folders.
The C and C++ programs are located in C_Program and CPP_Program respectively.

The file "writeup.pdf" contains the writeup for the assignment which explains
what I have done and provides justifications for my design.

The file "screencast.mp4" is a screencast showing the building and running of 
both programs.

C_Program:
This is an CLion project containing the following .c and .h files
- main.c = location of the main function
- functions.h = function declarations
- shared.h = declaration of shared global variables
- insert_observers.c = function for reading observer data
- insert_sightings.c = function for reading sighting data
- print_observers.c = function for printing observer data
- print_sightings.c = function for printing sighting data

The file CMakeLists.txt has been modified to include "target_link_libraries(C_Program m)" This is necessary for building the program using the math.h standard
library. The way to fix this when building from the command line would be to 
add "-lm" to the end of the command

The specified CLion version is version 3.9 and the ANSI C standard used is C11.

The standard libraries that have been included in the files previously 
mentioned are as follows
- stdio.h
- stdlib.h
- string.h
- math.h

CPP_Program:
This is a CLion project containing the following .cpp and .h files
- main.cpp = location of the main function as well as some supporting functions
- Locations.h = header file of provided Location class (not my own work)
- Location.cpp = implementation of Location.h (not my own work)
- Mammal.h = header file for the Mammal class
- Mammal.cpp implementation of Mammal.h

The specified CLion version is version 3.9 and the C++ standard used is ISO 
C++11.

The standard libraries that have been included in the files previously 
mentioned are as follows
- cstdlib
- iostream
- math.h
- fstream
- vector
- string
