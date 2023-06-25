# Project3

This is a CLI project that allows modular menu systems with easy file IO.

The modularity of the code was accomplished by using pointers to functions stored in a vector, 
  this allows the next programmer to only need to add the functionality within the Menus class, 
  then creating a reference of if in the vector.  This also elminated the need for if-else statements.

Currently, the function pointer vector is not currently static. This means that every menu object has duplicate vectors, 
  drastically increasing the size of objects, which increases memory use.

Original copies of the program, didn't focus on readability. Most everything was within the main function.
  A couple of refactors later and the main function just has the required lines without if-else and instead uses an index based system.
  This also made the code look a bit more "Pythonic", which is where my programming origins begin.
