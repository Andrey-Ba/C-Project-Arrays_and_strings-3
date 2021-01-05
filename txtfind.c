#include <stdio.h>
#include <string.h>

#define WORD 50
#define LINE 512

int Get_word_and_mode(char *word, char *mode)
{
    char ch = getchar();
    int i = 0;
    for(i = 0; ch != ' '; i++)
    {
        word[i] = ch;
        ch = getchar();
    }
    word[++i] = '\0';
    *(mode) = getchar();
    return i;
}

int similar(char* word1, char* word2)
{
    int diff = 0;
    int i = 0;
    int j = 0;
    while (word2[j] != 0)
    {
        if(word1[i] == word2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
            diff++;
            if(diff >1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int get_word(char *word, int *len)
{
    char ch;
    int i = 0;
    int status = scanf("%c",&ch);
    if(ch == 13)
    {
        ch = getchar();
    }
    while (i < WORD-1 && status!=EOF && ch != ' ' && ch != '\t' && ch != '\n')
    {
        word[i++] = ch;
        status = scanf("%c",&ch);
        if(ch == 13)
        {
        ch = getchar();
        }
    }
    word[++i] = '\0';
    *(len) = i;
    return status != EOF;
}

void check_words(char *word, int len)
{
    char word2[WORD] = {0};
    int len2 = -1;
    while (get_word(word2,&len2))
    {
        if((len == len2-1 || len == len2) && similar(word,word2))
        {
            printf("%s\n",word2);
        }
        memset(word2, 0, sizeof(word2));
    }
    if(len == len2-1 && similar(word,word2))
        {
            printf("%s\n",word2);
        }
}

int get_lines(char* line)
{
    char ch;
    int i=0;
    int status = scanf("%c",&ch);
    if(ch == 13)
    {
        ch = getchar();
    }
    while (i < LINE-1 && status != EOF &&ch!='\n')
    {
        line[i++] = ch;
        status = scanf("%c",&ch);
        if(ch == 13)
        {
            ch = getchar();
        }
    }
    line[++i] = '\0';
    return status != EOF;
}

int substrings(char *word1, char *word2)
{
    int i=0;
    int j=0;
    while (word2[i] && word2[j])
    {
        if(word1[i]==word2[j])
        {
            i++;
            j++;
            if(!word1[i])
            {
                return 1;
            }
        }
        else
        {
            i=0;
            j++;
        }
    }
    return 0;
}

int line_contains(char *word, char *line)
{
    return 0;
}


void check_lines(char* word)
{
    char line[LINE] = {0};
    while (get_lines(line))
    {
        if(substrings(word, line))
        {
            printf("%s\n",line);
        }
    }
    if(substrings(word, line))
    {
        printf("%s\n",line);
    }
}

int main()
{
    char word[WORD] = {0};
    char mode;
    int len = Get_word_and_mode(word, &mode);
    if(mode == 'a')
    {
        check_lines(word);
        
    }
    else if(mode == 'b')
    {
        check_words(word, len);
    }
    else
    {
        printf("Not a valid input\n");
    }
    
}