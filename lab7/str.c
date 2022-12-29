/**
 * @file str.c.c
 *
 * @author Caleb Krcil
 *
 * @date 10/30/2021
 *
 * Assignment: Lab 7
 *
 * @brief pointer versions of c library string functions used in test.c and
 * dynamic.c
 *
 * @bug none
 * 
 * @todo none
 */#include "str.h"
#include <stdio.h>

/**
 * pointer version of strlen
 * @param i iterating value
 */
int str_len(char *s)
{
	char *i = s;
	for(; *i != '\0'; i++){}

    return (i - s);
}

/* array version */
/* concantenate t to the end of s; s must be big enough */
void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') 	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/* array version */
void squeeze(char s[], int c)
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}


void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
}

/* copy n chars of src into dest */
/**
 * pointer version of strncpy
 * @param i iterating value
 */
void pstr_ncpy(char *dest, char *src, int n)
{
	int i;
	for(i = 0; i < n; i++){
		*dest = *src;
		dest++;
		src++;
	}

}

/* concantenate t to the end of s; s must be big enough! */
/**
 * pointer version of strcat
 */
void pstr_cat(char *s, char *t)
{
	while (*s) 	/* find end of s */
		s++;
	while ((*s++ = *t++)) /* copy t */
		;

}

/**
 * pointer version of strncmp
 * @param i iterating value
 */
int pstr_ncmp(char *s, char *t, int n)
{
	int i;
	i = 0;
	while((*s != '\0' && *t != '\0') && (*s == *t) && (i < n - 1)){
		s++;
		t++;
		i++;
	}
	if(*s == *t){
		return 0;
	}
	else{
		return (*s - *t);
	}
}

/**
 * pointer version of index
 * @param i iterating value
 */
char *pindex(char *s, int c)
{
	int i;
	i = 0;
	while(*s != '\0'){
		s++;
		if(*s == c){
			return s;
		}
	}
	return NULL;	
}

/**
 * pointer version of squeeze
 * @param h space
 */
void psqueeze(char *s, int c)
{	
	char h = ' ';
	for (; *s != '\0'; s++)
		if (*s == c)
			*s++ = h;

}

/**
 * swapping function
 * @param tmp temporary value
 */
void cswap(char *c, char *d)
{
	int tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * pointer version of reverse
 * @param i iterating value
 * @param j iterating value
 */
void preverse(char *s)
{
	int i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ){
		/* change this so it calls cswap */
		cswap(&*(s+i), &*(s+j));
	}
}