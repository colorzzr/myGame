#ifndef EXTRAFUNCTION_H
#define EXTRAFUNCTION_H

void sleep(int s) 
{ 
    for(int i = 0; i < s * 1000000000; i++); 
} 


#endif
