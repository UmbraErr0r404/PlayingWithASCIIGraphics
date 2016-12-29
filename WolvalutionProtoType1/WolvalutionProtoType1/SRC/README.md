TODO
====

Easy
----
* review documentation
* typedef uint
* use initialize lists when possible
* finish creating doxygen comments
* remove per-file authors

Medium
------
* move data files to there own folder and write the code so VS can still find them
* make per object tests
* remove all calls to another object's members
* make a point object for better clarity

Hard
----
* remove all referenced to getch() from all files except WindowsConsole.cpp
* make PlayGame into a class for managing the menus
* separate the physic engine out of PlayGame and Map
* migrate to cmake or some other management system
