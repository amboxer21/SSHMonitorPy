#define _GNU_SOURCE

#define BUFFER 1024

typedef struct Arguments {
    int fd[2];
    int s_stdout;
    char *pkgconfig;
    char *output[BUFFER];
} Argument;

int length(char **array) {
     int len = *(&array + 1) - array;
     return len;
}

char *chomp(char *s) {

    char *n = malloc(strlen( s ? s : "\n"));

    if(s) {
        strcpy(n, s);
    }
    n[strlen(n)-1] = '\0';
    return n;
}

char *setpath(void) {

    char *path = getenv("PATH");

    size_t path_size  = strlen(path) + strlen("PATH=") + sizeof(char *);
    char *pathenv = (char *)malloc(path_size*sizeof(char *));
    snprintf(pathenv, path_size, "PATH=%s", path);

    char *ppath = pathenv;

    free(pathenv);

    return ppath;

}