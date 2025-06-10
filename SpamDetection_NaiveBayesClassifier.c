#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXWORDS 1000   
#define MAXLINE 256  //max len of a line from a file

typedef struct {
    char word[30];
    int spamcount;
    int hamcount;
} WordStat;

WordStat vocab[MAXWORDS];
int vocabsize = 0, stotwords = 0, htotwords = 0, sdocs = 0, hdocs = 0;

void tcount(char *line, int isspam) 
{
    char *token = strtok(line, " ");
    while (token) 
    {
        int found = 0;
        for (int i = 0; i < vocabsize; i++) 
        {
            if (strcmp(vocab[i].word, token) == 0)  //if in vocab
            {
                if (isspam)
                    vocab[i].spamcount++;
                else
                    vocab[i].hamcount++;
                found = 1;
                break;
            }
        }
        if (!found && vocabsize < MAXWORDS)  //if not found and has space
        {
            strcpy(vocab[vocabsize].word, token);  //add it to vocab
            if (isspam)
                vocab[vocabsize].spamcount = 1;
            else
                vocab[vocabsize].hamcount = 1;
            vocabsize++;
        }

        if (isspam) 
            stotwords++;
        else 
            htotwords++;

        token = strtok(NULL, " ");  //to next word
    }
}

void train(const char *filename, int isspam) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        perror("File read error");
        exit(1);
    }

    char line[MAXLINE];
    while (fgets(line, sizeof(line), file)) 
    {
        if (isspam) sdocs++;
        else hdocs++;

        tcount(strtok(line, "\n"), isspam);
    }
    fclose(file);
}

double calcwordprob(char *word, int isspam) 
{
    int c = 0;
    int totalwords = isspam ? stotwords : htotwords;

    for (int i = 0; i < vocabsize; i++) 
    {
        if (strcmp(vocab[i].word, word) == 0)  //if in vocab, get count
        {
            c = isspam ? vocab[i].spamcount : vocab[i].hamcount;
            break;
        }
    }

    return (c + 1.0) / (totalwords + vocabsize);  //smoothed prob of the word
}

void testcase(const char *testfile) 
{
    FILE *file = fopen(testfile, "r");
    if (!file) 
    {
        perror("Test file read error");
        exit(1);
    }

    char line[MAXLINE];
    fgets(line, sizeof(line), file);

    printf("Testing line: \n");
    printf("%s\n", line);
    fclose(file);

    char *word = strtok(line, " ");
    double spamprob = log((double)sdocs / (sdocs + hdocs));  //log probabilities
    double hamprob = log((double)hdocs / (sdocs + hdocs));

    while (word)  //updates log probabilites using word probabilities
    {
        spamprob += log(calcwordprob(word, 1));
        hamprob += log(calcwordprob(word, 0));
        word = strtok(NULL, " ");  //to next word
    }

    printf("\nFinal Log Probability:\n");
    printf("Spam: %.4f\n", spamprob);
    printf("Ham : %.4f\n", hamprob);

    if (spamprob > hamprob)
        printf("\nResult: SPAM\n");
    else
        printf("\nResult: NOT SPAM\n");
}

int main()
{
    train("D:\\MyFolder\\c\\sem2pracques\\projectfiles\\spam.txt", 1);
    train("D:\\MyFolder\\c\\sem2pracques\\projectfiles\\ham.txt", 0);

    testcase("D:\\MyFolder\\c\\sem2pracques\\projectfiles\\test.txt");

    return 0;
}