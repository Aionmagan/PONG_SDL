#include "colorChange.h"
#include <stdio.h>

void ColorFileRead(char ColorC, unsigned int &r, unsigned int &g, unsigned int &b)
{
    FILE *file, *out;
    char ch;
    unsigned int rr = 0, gg = 0, bb = 0;;
        
    if((file = fopen("ColorPong.conf", "r")))
    {
        out = fopen("colorOutput.txt", "w");
        
        while(!feof(file))
        {
            fscanf(file, "%c:%d.%d.%d;", &ch, &rr, &gg, &bb);
            if(ch == ColorC)
            {
                fputs("found :", out);
                fputc(ch, out);
                r = rr; g = gg; b = bb;
                break;
            }   

            //fputs(s,out);
            fprintf(out, "%c:%d.%d.%d;", ch, rr, gg, bb);
        }
        fclose(file); 
        fclose(out);
        fflush(file); 
        fflush(out);
        
    }
    
   // r = &rr; g = &gg; b = &bb;
    
}