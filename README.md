# graph-drawer
give a function and watch the magic.(it is just a calculator written in c++)

//what it does:
it draws a graph for the function given, use basic math, as example: x+2*x4/5-6;

//rules and usage:
'*' for multiplication,
'/' for division,
'+' for addition,
'-' for substraction.
Only use x as a variable cause this a function defined as f(x).
Don't use the number 120 as it will be read as the variable x, use workarounds if you want to do so.
Don't use as -2+5 if you want to do substraction start with positive number as 5-2.
Always end functions with ';'

//linux:
To run on linux you should use terminal do not run it by double clicking it needs terminal.
to run in terminal wright ./a.out on the directory that the a.out file is found.
It will ask for 2 inputs. First one for spacing between each integer, second one the function itself.

//windows:
it does not support windows yet but if you compile it yourself it might.

//what are the plans for forward:
* windows support
* file input support
* settings
* more functionality towards being a graphic calculator while also being lightweight
 
//files:
main.cpp is main file and functions.h and functions.cpp has the structs and functions.

//libraries:
SDL2
fstream
string
iostream
