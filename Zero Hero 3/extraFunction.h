#ifndef EXTRAFUNCTION_H
#define EXTRAFUNCTION_H

void sleep(int s) 
{ 
    for(int i = 0; i < s * 499999999; i++); 
} 


#endif
