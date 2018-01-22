# Download

Clone first
then pull

### GCC Command
To compile the cpp by using gcc you need
```
-lstdc++
```
After gcc filename.


### sharing friend function

`class HeroStatus` and `class EnemeyStatus` share same friend function `void battleAnimation(HeroStatus*, EnemeyStatus*);` two classes are in different file.

because two `class` do not define varible they just take para for function

all have to do is to give prototype at begining of each file 

### save load

friend ostream& operator <<(ostream& output, const class& );

friend istream& operator >>(istream& input, class& );

### for member function

if you dont have member function instead of general function 

you have to type the prototype on each file



# Failure list
Unable to workout reading without `enter` in c++


# Version:
### Alpha 1.8
Basic movement

Map

add status bar

generate enemy and battle animation battle algorithm

add mainlist and new folder `bagInfo` to contain the bag item

finish basic bag structure

add battle reward

add save option and load

change gcc compiler to CMake

---

### Beta 1.2.1

add tutourial update guiden character

add MP feature

update skill feature

add skill detail

### Beta 1.2.2 2018.1.17

updata the input interface 

only accept one input per time

### Beta 1.2.3 2018.1.19

update the random algorithm using time to generate first location

and update random algorithm to generation all basic status

### Beta 1.2.4 2018.1.20

working on the skill in battle

fix all bugs and memory leak

### Beta 1.2.5 2018.1.21

add the enemyHpNow and change all corrosponding variable in battle

remove the local varibal enemyHpnow

fix the bug of two locations when loading the save





