#include <stdlib.h>
#include "main.h"

/**
 * wrdcnt - counts the number of words in a string
 * @s: string to count
 * Return: int of number of words
*/
int wrdcnt(char *s)
{
	int i, n = 0;
	for (i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
        {
            if (s[i + 1] != ' ' && s[i + 1] != '\0')
                n++;
        }
        else if (i == 0)
            n++;
    }
    n++;
    return (n);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
    int num_words;
    char **words;
    
    if (str == NULL || *str == '\0')
        return (NULL);
    
    num_words = wrdcnt(str);
    if (num_words == 1)
        return (NULL);
    
    words = (char **)malloc(num_words * sizeof(char *));
    if (words == NULL)
        return (NULL);
    words[num_words - 1] = NULL;
    
    int i=0, word_count = 0, word_start = -1;
    int word_length = 0; /** Declare word_length here */
    
    while (str[i])
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            word_start = i;
            int j; /** Declare j here */
            for (j = 0; str[i + j] != ' ' && str[i + j]; j++);
            word_length = j; /** Assign the value of word_length */
	    words[word_count] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_count] == NULL)
            {
                int k; /** Declare k here */
                for (k = 0; k < word_count; k++)
                    free(words[k]);
                free(words[num_words - 1]);
                free(words);
                return (NULL);
            }
            
            for (int l = 0; l < word_length; l++)
                words[word_count][l] = str[word_start + l];
            words[word_count][word_length] = '\0';
            word_count++;
            i += j;
        }
        else
        {
            i++;
        }
    }
    return (words);
}
