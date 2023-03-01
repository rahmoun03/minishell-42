#include "minishell.h"

char    *sp_split(char *str)
{
    int i;
    int len;
    int sp;
    char *ret;
    char cot;

    cot = 0;
    sp = 0;
    i = 0;
    len = ft_strlen(str);
    while (str[i])
    {
        if ((str[i] == '>' || str[i] == '<'))
        {
            while (str[i] && (str[i] == '>' || str[i] == '<'))
                i++;
            sp++;
        }
        i++;
    }
    len += (sp * 2);
    ret = (char *)malloc(len + 1);
    i = 0;
    sp = 0;
    while (i < len)
    {
        ret[sp] = str[i];
        sp++;
        if(str[i] == 34 || str[i] == 39)
        {
            cot = str[i++];
            while (str[i])
            {
                ret[sp] = str[i];
                sp++;
                if (str[i] == cot)
                    break;
                i++;
            }
        }
        if(str[i] != '<' && str[i] != '>' && (str[i + 1] == '<' || str[i + 1] == '>'))
        {
            ret[sp] = ' ';
            sp++;
        }
        else if((str[i] == '<' || str[i] == '>') && (str[i + 1] != '<' && str[i + 1] != '>'))
        {
            ret[sp] = ' ';
            sp++;
        }
        i++;
    }
    ret[sp] = '\0';
    free(str);
    return ret;
}