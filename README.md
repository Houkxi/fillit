# fillit

## Grade	100	/100

### Mandatory	100 /100
No Bonus points in this project

## Description

The start of file parsing and algorithm optimization.
The project is about finding the smallest square possible to fit the tetris shaped pieces and in the order they have been given with them as top left as possible.
A file fool of these specificaly-parsed shapes is given to the fillit program.

Shape and file example :
```
.###
...#
....
....

.##.
..##
....
....

#...
#...
##..
....

..##
..##
....
....
```

The file is parsed this way :
- all shapes are in a 4x4 square with dots
- the shapes will be formed by ```#```
- each shape is seperated by one and only one new line except for the last shape
- there cannot be more then 26 shapes in one file

There will be no unexpected quits from the program (Segmentation fault, bus error, double free, etc).

## Usage

```C
prompt> ./fillit tetris.txt
CAAA
CBBA
CCBB
DD..
DD..
```
