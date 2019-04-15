# NanoTekSpice

## What to know ?
1. Epitech 2nd year project.
2. All written in C++.
3. NanoTekSpice is a logic simulator that builds a graph (the nodes of which will be simulated digital electroniccomponents, inputs or outputs) from a configuration file, and injects values into that graph to get results

## Test the project
1. Clone the repository using SSH or direct Download.
2. Use the makefile to build (`make`).
3. Create a configuration file (help at the bottom of this file).
4. Execute the program (`./nanotekspice <cfg.nts> [optional params]`).
5. This project is design to work only on linux platform.

## Configuration Files

TODO: Rewrite the configuration parser.

Configuration is in 2 parts: 
* `.chipsets:` where you declare your components
* `.links:` where you declare the links between the components.

For now the config parser do not support spaces at the end of the categories delimiter (`.chipsets:` or `.links`). Furthermore it is recomended to test with nothing else on the line than the delimiter as is:

```
.chipsets:
input i1
output s
.links:
i1:1 s:1
```
### Components

for the moment only the following components are implemented:
* Input
* Output
* Clock
* True
* False
* comp4081 : 2 input AND
* comp4001 : 2 input NOR
* comp4011 : 2 input CMOS NAND
* comp4071 : 2 input OR
* comp4030 : 2 input EXCLUSIVE-OR

## Commands

Once the nanotekspice simulation launched it starts a shell and you can still control the simulation through this shell.

* `display`: will display the current state of the result
* `simulate`: will simulate a new result
* `loop`: will loop on the current state
* `dump`: will show the state of all components.
* `exit`: exit the program

you can reasign a value of a component by using this synthax in the shell `<name of the component> = <value>`.

For example given this configuration:
```
.chipsets:
input a
input b
4071 or
output s
.links:
a:1 or:1
b:1 or:2
or:3 s:1
```
Here is the execution:
```
~/E/cpp_nanotekspice> ./nanotekspice tests/_test_simple.nts  a=0 b=0
s=0
> dump
a:
0
b:
0
or:
0
s:
0
> a=1 //here I change the value of input a to 1
> b=0 //here I change the value of input b to 0 (already 0)
> display // i call the command to display the result
s=1
> ...
```