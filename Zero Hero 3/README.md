To compile the cpp by using gcc you need
```
-lstdc++
```
after gcc filename.

For reading the input without the enter key
screen clear here
```
	initscr();
```					

without cbreak() function user have to type enter for continue
```
	cbreak();					
```

read input without enter and input would show on the screen
```    
	noecho();
```

enable or disable scrolling on a window.
```
    scrollok(stdscr, TRUE);
```

control whether the input would show on the screen
```
    nodelay(stdscr, false);	
```

Test main loop
```
    while (true) {
        if (getch() == 'g') {
            printw("You pressed G\n");
        }
        napms(500);
        printw("Running\n");
    }
```