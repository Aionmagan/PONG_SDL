#ifndef _DEBOUT_
#define _DEBOUT_

#include <stdio.h>

class Debug
{
    FILE *file;
    const char *s = "DebugOutput.txt";
public :  
    Debug(){file = fopen(s, "w");}
    ~Debug(){fclose(file); fflush(file);}
    template<typename T>
    void Log(T *data)const
    {
        fputs((char *)data, file);
    }
    void Error();
};

#endif //_DEBOUT_