
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>

#define WSZ 256
#define HSZ 8191

int h(char *p, int m)
{
    int flip = 0;
    int len = 0;
    int s = 0;
    int shortcnt = 0;
    unsigned short *sp = NULL;

    len = strnlen(p, WSZ);
    shortcnt = len / 2;
    sp = (unsigned short *)p;
    unsigned short hval = 0x5ab6;

    /* folding the string by twos */
    for (s = 0; s < shortcnt; s++)
    {
        unsigned short newv;
        newv = *sp;
        if (flip)
        {
            newv <<= 1;
        }
        flip = !(flip);
        hval ^= newv;
        sp++;
    }
    /* if odd size string double up last char */
    if (len & 0x0001)
    {
        hval ^= ((((short)(p[len-1])) << 8) | (short)(p[len-1]));
    }
    return (int)hval % m;
}

int main(int argc, char **argv)
{
    char buff[WSZ] = "thequickbrownfoxjumpedoverthelazydog";
    int hval;
    hval = h(buff, HSZ);
    printf("buff = %s >>>> hval = %d\n", buff, hval);
}
