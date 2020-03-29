README

This collection of files implements a Tree-like data structure
that stores keys and values.

The header file tree.hh contains the declaration of types
and functions to be used with the struct. The underlying implementations
of these functions are written in tree.cc. All methods written run in either 
constant or linear time. Finally, the unit test file, test_tree.cc, was used 
to test the implementation of the new data structure.

Importantly, this data structure is not ordered and does not
rely on values to determine the location of the next connection.
It is simply an iterative representation of a binary tree.

To compile these scripts together: 
g++ -g -Wall -Wextra -std=c++17 tree.cc test_tree.cc -o test_tree

To run them:
./test_tree

There is a multiple definition error that is still in debugging process.
This error argues that the methods in tree.cc are already defined
in a file in the folder "/tmp" on my Linux machine. I'm hoping that
this is a problem unique to my machine and filesystem, and it is
the only compiling error unsolved so far.