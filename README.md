# Lem-in

### About Lem-in :

* The goal of this project is to move ants throughs multiple path.
* In this project, I need to find the path I can use and then move my ants in the best way possible
* Each time the program will move an ant it will print it as follow : Lx-room_name with x being the number of the ant. if multiple ants are moved at the same time, it will all be printed in one line.

### Map :

* The first part of the map is an integer which represent the number of ants we have in the starting room
* The second part of the map is the name of the room followed but it's coordinates x and y
* The ##start and ##end indicate that the room below is the starting/ending point
* The third and last part represent the link between the room
* The link between room must be formated as follow : room1_name-room2_name

### Map example :
```
100
##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
#C'est la fin
6-5
#autre commentaire
```

### Usage :

* make : create the binary
* make clean : delete the .o file
* make fclean : delete the .o and binary file
* make re : use 'make fclean' and then use 'make'
* ./lem-in my_map

### To do :

* Optimization to make it work on big map
