# Errors

1. on recupere le statut chaque proc dans notre minishell parent avec [**waitpid**](http://manpagesfr.free.fr/man/man2/wait.2.html).

```c
#include <sys/wait.h>
pid_t waitpid(pid_t, int *status, int options);  // avec status

// options de waitpid ??

// si waitpid == -1 ??
```

1. on verifie si le proc a quitté normalement ou avec un signal et on recupere l’exitcode

```c
#include <sys/wait.h>

if status   // si status n'est pas null

	if WIFEXITED(status) // si le processus a quitté avec une erreur
		 exitcode = WEXITSTATUS(status);

	else if WIFSIGNALED(status) // si le proc a quitté à cause d'un signal
		exitcode = 128 + WTERMSIG(status);

	// si !WIFEXITED && !WIFSIGNALED ??

return (exitcode);

```

1. selon l’exitcode 0 or >0 et le prochain operateur && or || on crée ou non le prochain proc

---

[**A list of signals and what they mean**](https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf)

| EXITCODE TAB | EXECUTABLES | BUILTINS |
| --- | --- | --- |
| pour tout | [ 0 , 255 ] | [ 0 , 255 ] |
| SUCCESS | 0 | 0 |
| ∀ ERROR | [ 1 , 255 ] | [ 1 , 255 ] |
| GENERAL ERROR | 1 | 1 |
| BAD USE OPT/ARG | 1 | 2 |
| free | [ 3 , 125 ] | [ 3 , 125 ] |
| CANT EXEC | 126 |  |
| NOT FOUND | 127 |  |
| 128 ? |  |  |
| SIGNAL 128 + SIG | [ 129 ; 159 ] | [ 129 ; 159 ] |
| free | [ 160 ; 255 ] | [ 160 ; 255 ] |
| > 255 ⇒ exitcode%256 |  |  |

```bash
# $? execution

export oui=1
$oui
# >>> 1: command not found
# la commande "1" n'est pas trouvée => exitcode 127
echo $?

$?
# >>> 127: command not found
# la commande "127" n'est pas trouvée => exitcode 127
echo $?
```