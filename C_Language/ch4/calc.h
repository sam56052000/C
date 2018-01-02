#define NUMBER '0'

void push(double);
double pop(void);
double print_top(void);
void swap_top2(void);
void clear_stack(void);

int getch(void);
void ungetch(int);
void ungets(char *s);
void unget(char c);

int getop(char []);
int getop_line(char s[]);
int getop_static(char s[]);
int get_line(char s[], int lim);
