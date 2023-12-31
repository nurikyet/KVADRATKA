#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cctype>
#include <assert.h>
#include <string.h>

const char* MyFile = "Onegin (1).txt";
const char* MyOutFile = "OneginFinal.txt";

void PrintSourceText(FILE *OneginFinal, char **text, int nrows);
void SortByQsort(char **text, int nrows);
void FillingText(char **text, char* buffer, int size);
void MyQuickSort(char **text, int nrows);
void PrintingOriginalText(FILE *OneginFinal, char *buffer, int size);

int  GetSizeFromFile(FILE *TextFile);
int  GetNumberOfRows(char *buffer, int size);
int  Compare(const void * x1, const void * x2);
int  LeftRight(const char* str1, const char* str2);

//=============================================================================

void Sort(char **text, int left, int right);

int  Partition(char **text, int first, int last);
int  Exchange(char **text, int left, int right);
int  Compare1(const void* x1, const void* x2);
int  RightLeft(const char* str1, const char* str2);
//=============================================================================

int main()
    {
    FILE *TextFile = fopen(MyFile, "rb");
    if (TextFile == NULL)
        {
        printf("Cannot open file.\n");
        return 1;
        }

    int size = GetSizeFromFile(TextFile);

    char *buffer = (char*) calloc(size+1, sizeof(char));
    size_t nread = fread(buffer, sizeof(char), size, TextFile);
    assert( nread <= size);

    int nrows = GetNumberOfRows(buffer, size);

    char **text = (char**) calloc(nrows, sizeof(char*));
    FillingText(text, buffer, size);

    SortByQsort(text, nrows);
    FILE *OneginFinal = fopen(MyOutFile, "w");
    PrintSourceText(OneginFinal, text, nrows);

    fprintf(OneginFinal, "\n");
    fprintf(OneginFinal, "\n");

    MyQuickSort(text, nrows);

    PrintSourceText(OneginFinal, text, nrows);

    fprintf(OneginFinal, "\n");
    fprintf(OneginFinal, "\n");

    PrintingOriginalText(OneginFinal, buffer, size);

    fclose(TextFile);
    fclose(OneginFinal);
    free(text);
    free(buffer);
    }

//-----------------------------------------------------------------------------

int GetSizeFromFile(FILE *TextFile)
    {
    struct stat buff = {};
    stat(MyFile, &buff);
    return buff.st_size;
    }

//-----------------------------------------------------------------------------

void PrintSourceText(FILE *OneginFinal, char **text, int nrows)
    {
    assert(*text != NULL);
    for (int i = 0; i < nrows; i++)
        {
        fprintf(OneginFinal, "%s\n", text[i]);
        }
    }

//-----------------------------------------------------------------------------

int GetNumberOfRows(char *buffer, int size)
    {
    assert(*buffer != NULL);
    int nrows = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            nrows++;
            }
        }
    return nrows;
    }

//-----------------------------------------------------------------------------

void FillingText(char **text, char* buffer, int size)
    {
    text[0] = buffer;
    int nline = 1;
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\n')
            {
            text[nline] = (buffer + i + 1);
            buffer[i] = '\0';
            nline++;
            }
        }
    }

//-----------------------------------------------------------------------------

void SortByQsort(char **text, int nrows)
    {
    qsort((void *)text, nrows, sizeof(char*), Compare);
    }

//-----------------------------------------------------------------------------

int Compare(const void * x1, const void * x2)
    {
    return LeftRight( * ( char** ) x1, * ( char** ) x2 );
    }

 //-----------------------------------------------------------------------------

void MyQuickSort(char **text, int nrows)
    {
    int first = 0;
    int last = nrows - 1;

    Sort(text, first, last);

    }


//-----------------------------------------------------------------------------


void Sort(char **text, int left, int right)
    {
    // printf("%d %d\n", left, right);
    if (left == right)
        {
        return;
        }
    else if (right - left == 1)
        {
        if (Compare1(text[left], text[right]) > 0)
            {
            Exchange(text, left, right);
            }
        }
    else
        {
        int mid = Partition(text, left, right);
        Sort(text, left, mid);
        Sort(text, mid + 1, right);
        }
    }

//-----------------------------------------------------------------------------

int Partition(char **text, int left, int right)
    {
    char *mid = text[(right - left) / 2 + left];
    while(left <= right)
        {
        while (Compare1(text[left], mid) < 0)
            {
            left++;
            }
        while (Compare1(text[right], mid) > 0)
            {
            right--;
            }
        if (left < right)
            {
            Exchange(text, left, right);
            left++;
            right--;
            }
        else
            {
            return right;
            }
        }

    return right;
    }

//-----------------------------------------------------------------------------

int Exchange(char **text, int left, int right)
    {
    char* third = text[left];
    text[left] = text[right];
    text[right] = third;

    return 0;
    }

//-----------------------------------------------------------------------------

int Compare1(const void* x1, const void* x2)
    {
    return RightLeft(( char* ) x1, ( char* ) x2 );
    }

//-----------------------------------------------------------------------------

int RightLeft(const char* str1, const char* str2)
    {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i = len1-1;
    int j = len2-1;

    while (true)
        {
        while (i > 0)
            {
            if (isalpha(str1[i])) break;
            i--;
            }
        if (isalpha(str1[i]) == 0)
            {
            i--;
            }

        while (j > 0)
            {
            if (isalpha(str2[j])) break;
            j--;
            }
        if (isalpha(str2[j]) == 0)
            {
            j--;
            }

        if (str1[i] > str2[j])
            {
            return 1;
            }
        else if (str1[i] < str2[j])
            {
            return -1;
            }
        else
            {
            i--;
            j--;
            }

        if ((i < 0) || (j < 0))
            {
                break;
            }
        }

    if ((i < 0) && (j >= 0))
        {
        return -1;
        }
    else if ((i >= 0) && (j < 0))
    {
    return 1;
    }
    else
    {
        return 0;
    }

    }


//-----------------------------------------------------------------------------

void PrintingOriginalText(FILE *OneginFinal, char *buffer, int size)
    {
    for (int i = 0; i < size; i++)
        {
        if (buffer[i] == '\0')
            {
            fprintf(OneginFinal,"%c", '\n');
            }
        else
            {
            fputc(buffer[i], OneginFinal);
            }
        }
    }


//-----------------------------------------------------------------------------


int LeftRight(const char* str1, const char* str2)
    {
    int first  = 0;
    int second = 0;
    while ( str1[first] != '\0' && towlower(str1[first]) == 0 && isalpha(str1[first]) == 0)
        {
        first++;
        }
    while (str2[second] != '\0' && towlower(str2[second]) == 0 && isalpha(str2[second]) == 0)
        {
        second++;
        }
    return (str1[first] - str2[second]);
    }
