# Functions list

Input

> prompt qui attend la cmd (avec readline ?)
> 

> historique des cmds
> 

---

Parser

> gerer le single ' et double quote "
> 

> redirections < > << >> (gestion des redirections entre les pipes ?)
> 

> gerer les env variables avec $
> 
> 
> Recuperation des variables d’env dans le main :
> 
> ```c
> int	main(int ac, char **av, char **envp)
> ```
> 

> 
> 

---

Execution

> fork & pipes
> 

> execution avec env / absolute or relatif path
> 

> signaux
> 

> exit code d'une cmd $?
> 

---

## Bonus

> && et || aveec ( )
> 
> - arbre binaire
> - AST
> - sub shell
> - on balade l’exit code mdr

> wildcards * only for current dir
> 
> - struct readdir()

---

## Autre

- Garbage collector - Collecter les pointeurs a free (mais il y a une methode plus propre - demander a Gus)
- UTILISER CALLOC
- Liste noire valgrind (cacher certaines erreurs)
- Var globale : pour le code d’erreur ?

---

### [**Shell expansion**](https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_03_04.html)

## **Fonctions autorises**

with test code  ← description only ← with a russian test ← not yet tested ← empty

Useful

Not useful

For bonuses

Doubt 

---

### Readline

[Man readline](https://web.mit.edu/gnu/doc/html/rlman_2.html)

- readline (on doit pas gerer les leaks de readline)
    
    Un readline rudimentaire
    
    ```c
    int	builtins(char *buf)
    {
    	if (!strcmp(buf, "exit"))
    		return (0);
    	return (1);
    }
    
    char	*free_buf(char *buf)
    {
    	if (buf)
    	{
    		free(buf);
    		buf = NULL;
    		return NULL;
    	}
    	return (buf);
    }
    
    char	*ft_get_line(char *buf)
    {
    	if (free_buf(buf))
    		return NULL;
    	buf = readline("mini_mishell$ ");
    	if (!buf)
    		return (NULL);
    	add_history(buf);
    	printf("%s\n", buf);
    	if (!builtins(buf))
    		return (free_buf(buf));
    	return (buf);
    }
    
    int	main(int ac, char **av, char **envp)
    {
    	(void)av;
    	(void)envp;
    	(void)ac;
    
    	char	*buf;
    	while (1)
    	{
    		buf = ft_get_line(buf);
    		if (!buf)
    			break;
    	}
    	return (1);
    }
    ```
    
- rl_on_new_line (pour passer a une nouvelle ligne askip)
    
    [Les tests d’un russe](https://questu.ru/questions/68003253/) (signal ^\c)
    
    ```c
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    ```
    
    /* Tell the update routines that we have moved onto a new (empty) line. */
    
    ```c
    841 rl_on_new_line ()
    
    842 {
    
    843   if (visible_line)
    
    844     visible_line[0] = '\0';
    
    845
    
    846   _rl_last_c_pos = _rl_last_v_pos = 0;
    
    847   _rl_vis_botlin = last_lmargin = 0;
    
    848   return 0;
    
    849 }
    ```
    
    ```c
    **/* The last left edge of text that was displayed.  This is used when
    
    127    doing horizontal scrolling.  It shifts in thirds of a screenwidth. */
    
    128 static int last_lmargin = 0;
    
    /* Pseudo-global variables declared here. */
    
    118 /* The visible cursor position.  If you print some text, adjust this. */
    
    119 int _rl_last_c_pos = 0;
    
    120 int _rl_last_v_pos = 0;
    
    121
    
    122 /* Number of lines currently on screen minus 1. */
    
    123 int _rl_vis_botlin = 0;**
    ```
    
- rl_replace_line
    
    [Code source de bcp de rl](https://www.opencoverage.net/bash/index_html/function_tree.p21A0.html) 
    
- rl_redisplay (met a jour l'affichage du terminal)
    
    [Source code on line 651](https://www.opencoverage.net/bash/index_html/source_93.html#line649) 
    
- add_history
    
    
- rl_clear_history
    
    

---

### Files descriptors / Pathnames

- access : check si on peut acceder a un fichier / dossier
    
    ```c
    // [**int access(const char *pathname, int mode);](https://man7.org/linux/man-pages/man2/access.2.html)**
    // SUCCESS 0 / ERROR -1
    
    // /!\ use stat() before to check if pathname is file or directory
    // as access() doesnt know
    // [**stackoverflow.com/check-if-file-is-executable**](https://stackoverflow.com/questions/4629643/implementing-a-unix-shell-in-c-check-if-file-is-executable)
    
    char *pathname = "/dev/random";
    
    	if (0 > access(pathname, F_OK | W_OK))
    		printf("%s dont exist or cant be writed\n", pathname);
    	if (0 > access(pathname, F_OK | R_OK))
    		printf("%s dont exist or cant be read\n", pathname);
    	if (0 > access(pathname, F_OK | X_OK))
    		printf("%s dont exist or cant be executed\n", pathname);
    ```
    
- open : ouvre un fd
    
    ```c
    // [**int open(const char *pathname, int flags, mode_t mode);](https://man7.org/linux/man-pages/man2/open.2.html)**
    // SUCCESS fd >= 0 / ERROR -1
    
    /*
    O_RDONLY : permission de lecture
    O_WRONLY : permission d'ecriture
    O_CREAT : creer le fichier si il n'existe pas
    O_TRUNC : écrase le fichier
    O_APPEND : ajoute a la fin
    
    O_NONBLOCK : /!\ evite des bugs sur les fichiers speciaux / man > NOTES
    			"Under Linux, the O_NONBLOCK flag is sometimes used in cases where
           one wants to open but does not necessarily have the intention to
           read or write.  For example, this may be used to open a device in
           order to get a file descriptor for use with ioctl(2)."
    */
    ```
    
- read : lit sur un fd (utile pour GNL ?)
    
    ```c
    // [**ssize_t read(int fd, void *buf, size_t count);**](https://man7.org/linux/man-pages/man2/read.2.html)
    // SUCCESS number of bytes read, 0 EOF / ERROR -1
    ```
    
- close : ferme un fd
    
    ```c
    // [**int close(int fd);**](https://man7.org/linux/man-pages/man2/close.2.html)
    // SUCCESS 0 / ERROR -1
    ```
    
- unlink : supprime un fichier
    
    ```c
    // [**int unlink(const char *pathname);](https://man7.org/linux/man-pages/man2/unlink.2.html)**
    // SUCCESS 0 or positive / ERROR -1
    ```
    
- ioctl : permet de recuperer des infos sur les fichiers speciaux / de peripheriques
    
    ```c
    // [**int ioctl(int fd, unsigned long request, ...);](https://man7.org/linux/man-pages/man2/ioctl.2.html)**
    // SUCCESS 0 or positive / ERROR -1
    
    **// [IBM-character-special-file](https://www.ibm.com/docs/en/zos/2.3.0?topic=csf-character-special-files)s
    
    // [sys/ioctl.h](https://unix.superglobalmegacorp.com/Net2/newsrc/sys/ioctl.h.html)**
    
    ```
    
- isatty : le fd est il un terminal
    
    ```c
    // [**int isatty(int fd);**](https://www.man7.org/linux/man-pages/man3/isatty.3.html)
    *// SUCCESS 0 / ERROR -1
    
    for (int i = -1; i < 5; i++)
    		printf("isatty(%d) : %d\n", i, isatty(i));*
    ```
    
- ttyname : recupere le chemin complet du terminal actuel
    
    ```c
    // [**char *ttyname(int fd);**](https://man7.org/linux/man-pages/man3/ttyname.3.html)
    *// SUCESS match name / ERROR NULL*
    	
    for (int i = -1; i < 5; i++)
    	printf("tty_name(%d) : %s\n", i, ttyname(i));
    ```
    
- ttyslot : trouve la position du terminal dans un fichier
    
    ```c
    // [**int ttyslot(void);**](https://man7.org/linux/man-pages/man3/ttyslot.3.html)
    // SUCESS valid position / ERROR -1
    
    printf("ttyslot() : %d\n", ttyslot());
    ```
    
- stat / lstat / fstat : retourne une structure qui contient des infos sur un fichier
    
    ```c
    // [**int stat(const char *restrict pathname, struct stat *restrict statbuf);](https://man7.org/linux/man-pages/man2/lstat.2.html)**
    // SUCCESS 0 / ERROR -1
    
    // int fstat(int fd, struct stat *statbuf);
    // pareil avec un fd
    
    // int lstat(const char *restrict pathname, struct stat *restrict statbuf);
    // pareil sauf en cas de liens symboliques, donne des infos sur ces derniers
    
    // pas de permission du fichier necessaire mais x sur tous les dir parents
    ```
    
- chdir : permet de changer de dossier courant
    
    ```c
    // **[int chdir(const char *path);](https://man7.org/linux/man-pages/man2/chdir.2.html)**
    // SUCCESS 0 / ERROR -1
    
    // builtin cd
    ```
    
- opendir
- readdir : recupere la struct d’un fichier de dir je crois je suis pas certain
    
    ```c
    // **[struct dirent *readdir(DIR *dirp);](https://man7.org/linux/man-pages/man3/readdir.3.html)**
    // SUCCESS a pointer to a dirent structure or NULL to end / ERROR NULL
    
    /* /!\ Return value
    			"To distinguish end of stream from an error,
    			set errno to zero before calling readdir()
           and then check the value of errno if NULL is returned."
    */
    
    /*
    struct dirent {
                   ino_t          d_ino;       // Inode number
                   off_t          d_off;       // Not an offset; see below
                   unsigned short d_reclen;    // Length of this record
                   unsigned char  d_type;      // Type of file; not supported
                                                  by all filesystem type
                   char           d_name[256]; // Null-terminated filename
               };
    */
    ```
    
- closedir
- getcwd : retourne le path absolu du dossier courant
    
    [getcwd 2](Functions%20list%2022f290cb30f04d8e96e97ce71f69e500/getcwd%202%204c870844e6a34c698b684b2931d13281.md)
    
    Utiliser une boucle pour augmenter le buf
    Mettre un gros buffer ? QU’EST CE QU’IL SE PASSE
    
    [Examples](https://pubs.opengroup.org/onlinepubs/9699919799/functions/getcwd.html)
    
    [Man](https://man7.org/linux/man-pages/man3/getcwd.3.html)
    
    ```c
    // [**char *getcwd(char *buf, size_t size);**](https://man7.org/linux/man-pages/man3/getcwd.3.html)
    // SUCCESS the current directory / ERROR NULL
    
    // /!\ buf doit etre free() ssi getcwd echoue
    ```
    

---

### Child process / Execution

- getenv : permet de recuperer une env variable
    
    ```c
    // [**char    *getenv(const char *name);**](https://man7.org/linux/man-pages/man3/getenv.3.html)
    *// SUCCESS value | ERROR NULL*
    
    printf("terminal_name : %s\n", getenv("TERM"));
    printf("env var PATH : %s\n", getenv("PATH"));
    ```
    
- fork
    
    
- pipe
- dup / dup2
- wait / waitpid
- wait3 / wait4 : un peu comme waitpid mais retourne des infos en plus
    
    ```c
    // [**pid_t wait3(int * wstatus , int options , struct rusage * rusage );**](https://man7.org/linux/man-pages/man2/wait3.2.html) 
    // n'importe quel enfant
    
    // pid_t wait4(pid_t pid , int * wstatus , int options , struct rusage * rusage );
    // un enfant précis
    
    // SUCCESS ptr rusage and return pid | ERROR rusage NULL and return -1
    ```
    
- execve

---

### Signals

On utilise signal uniquement, on envoie pas de signal (kill),  et on a pas besoin de recuperer des infos supplementaires sur l’origin du signal (sigaction, sigemptyset, sigaddset)

- signal
    
    [video intro](https://www.youtube.com/watch?v=83M5-NPDeWs)
    
- sigaction
- sigemptyset
- sigaddset
- kill

---

### Termcap library

On risque de ne pas s’en servir, Readline fait deja tout 

[`**https://linux.die.net/man/3/tgetflag**`](https://linux.die.net/man/3/tgetflag)

[`**https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html**`](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html)

[`**https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/**`](https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/)

- tcsetattr
- tcgetattr
- tgetent
- tgetflag
- tgetnum
- tgetstr
- tgoto
- tputs

---

### Error Handling

[Intro video](https://www.youtube.com/watch?v=IZiUT-ipnj0)

errno (errno.h)

En vrai, on utilise que perror 

- perror
    
    
- strerror
    
    strerror(error number)
    
    gives short explanation of the error in a char* (useful to store the errors ?)