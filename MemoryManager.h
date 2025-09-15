#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#define MAX_VALUE 100
#define PI 3.14159

// Declare global variables (use 'extern' keyword)
extern int globalVariable;
extern const char* programName;

// Declare function prototypes
void myFunction(int arg1, char* arg2);
int calculateSum(int a, int b);

// Define structures or enums
typedef struct {
    int id;
    char name[50];
} MyStruct;

typedef enum {
    STATUS_OK,
    STATUS_ERROR
} StatusCode;

#endif // MY_HEADER_FILE_H
