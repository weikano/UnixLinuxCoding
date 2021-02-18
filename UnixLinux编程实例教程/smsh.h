char * next_cmd();
char ** spliline(char *);
void freelist(char**);
void *emalloc(size_t);
void *erealloc(void*, size_t);
int execute(char**);
void fatal(char*, char*, int);