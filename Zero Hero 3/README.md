# Reminder
### Upload and DownLoad
Before push and pull 

Clone first

### GCC Command
To compile the cpp by using gcc you need
```
-lstdc++
```
After gcc filename.

### file include
remember a include b, b include c

when a need use function c,

we don't have to a include c 

### sharing friend function

`class HeroStatus` and `class EnemeyStatus` share same friend function `void battleAnimation(HeroStatus*, EnemeyStatus*);` two classes are in different file.

because two `class` do not define varible they just take para for function

all have to do is to give prototype at begining of each file 

# Failure list
Unable to workout reading without `enter` in c++


# TO DO
 - change the battle algorithm(srand())
 - change the coin bar in  battle engage
 - change the phy and mag defence calculation



# Version:
### Alpha 1.6
Basic movement

Map

add status bar

generate enemy and battle animation battle algorithm

add mainlist and new folder `bagInfo` to contain the bag item

finish basic bag structure

add battle reward

add save option