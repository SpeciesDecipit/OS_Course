#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_SEP " \t\a\r\n"
#define LSH_TOK_BUFSIZE 64

void lsh_loop(void);

char *lsh_read_line(void);

char **lsg_split_line(char *line);

int lsh_execute(char **args);

int lsh_launch(char **args);

int lsh_cd(char **args);

int lsh_help(void);

int lsh_exit(char **args);

void lsh_pwd(char **args);

void lsh_top(char **args);

void lsh_ls(char **args);

char *builtin_str[] = {
        "cd",
        "help",
        "exit",
        "pwd",
        "top",
        "ls"
};

int (*builtin_func[])(char **) = {
        &lsh_cd,
        &lsh_help,
        &lsh_exit,
        &lsh_pwd,
        &lsh_top,
        &lsh_ls,
};


int lsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

void lsh_ls(char **args) {
    system("ls");
}

void lsh_top(char **args) {
    system("top");
}

void lsh_pwd(char **args) {
    char *cwd = (char *) malloc(sizeof(char) * LSH_RL_BUFSIZE);
    getcwd(cwd, sizeof(cwd));
    system("pwd");
}

int lsh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: ожидается аргумент для \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }

    return 1;
}

int lsh_help(void) {
    int i;
    printf("LSH Species_decipit\n");
    printf("Наберите названия программы, введите аргументы и нажмите Enter\n");
    printf("Вот список встроенных програм:\n");

    for (i = 0; i < lsh_num_builtins(); i++)
        printf(" %s\n", builtin_str[i]);

    printf("Используйте команду man для получения информации по другим программам\n");

    return 1;
}

int lsh_exit(char **args) {
    return 0;
}

int main(int argc, char **argv) {
    lsh_loop();

    return EXIT_SUCCESS;
}

void lsh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsg_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
}

char *lsh_read_line(void) {
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "lsh: ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = (char) c;
        }
        position++;

        if (position >= bufsize) {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, sizeof(char) * bufsize);
            if (!buffer) {
                fprintf(stderr, "lsh: ошибка выделения памяти\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **lsg_split_line(char *line) {
    int bufsize = LSH_TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "lsh: ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, LSH_TOK_SEP);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "lsh: ошибка выделения памяти\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_TOK_SEP);
    }
    tokens[position] = NULL;

    return tokens;
}

int lsh_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execlp(args[0], args) == -1)
            perror("lsh");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("lsh");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int lsh_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        return 1;
    }

    for (i = 0; i < lsh_num_builtins(); i++)
        if (strcmp(args[0], builtin_str[i]) == 0)
            return (*builtin_func[i])(args);

    return lsh_launch(args);
}
