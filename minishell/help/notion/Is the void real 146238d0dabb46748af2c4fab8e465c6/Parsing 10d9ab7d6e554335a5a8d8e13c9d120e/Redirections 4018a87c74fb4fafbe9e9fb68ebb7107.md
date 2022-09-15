# Redirections

```bash

# on gere pas les 2> ou <1
# special files

< /dev/fd/0 cat -n
< /dev/fd/1 cat -n
< /dev/fd/2 cat -n

< /dev/stdin cat -n
< /dev/stdout cat -n
< /dev/stderr cat -n

< /dev/stdin cat -n
< /dev/stdout cat -n
< /dev/stderr cat -n

<< /dev/stdin cat -n
<< /dev/stdout cat -n
<< /dev/stderr cat -n

echo bonjour > /dev/stdout | jioj >> haa
echo bonjour > /dev/stdout | jioj 2>> haa
echo bonjour > | jioj 2>> haa

```

what works

```bash
./checker 4 5 6 < a
< a ./checker 4 5 6

ls > b
> b ls
```

Se poser la question du 

```bash
# nbr de lignes print par minishell depuis le debut
bash: warning: here-document at line 145 delimited by end-of-file (wanted `oui')
```

```bash
# multiples redirections

#
date >a

date >a>b>z

>a date >z

>a>b>c date >d>e>z

>a date                  >                       z

#wildcards *
(touch z1 z2 ; >a date >z*

```

Pour * cmd, si un fichier n’est pas accessible, on stop la commande

On ne peut pas rediriger vers l’entree standard de unset, echo, export et env  

Le simple prend le dessus sur le append 

Pour les redir sorties 

Prio au file de droite puis prio au simple sur append 

Donc, si 2 fichiers & simple ouvert pour les 2, le contenu du 2eme est ecrase

```bash
chsimon@e2r3p8:~/minishell/tries$ >>a echo bonjour bon  >b >>a oui >>b >a;
chsimon@e2r3p8:~/minishell/tries$ cat a
bonjour bon oui
chsimon@e2r3p8:~/minishell/tries$ cat b
```

---

ouvrir les fichiers dans les forks (s’il ya des pipes)

```c
chsimon@e2r5p14:~/mini_mishell/tries$ ls > test1 | cat < test1 || echo success
bash: test1: No such file or directory
success
chsimon@e2r5p14:~/mini_mishell/tries$ ls > test2 && cat < test2 || echo success
dadsad
test
test1
test2
```

---

HereDoc

Pas d’expand dans le HereDoc si t’as des “” ou ‘’ dans le EOF

```bash
bash-5.0$ <<end cat
> $USER
> end
chsimon

bash-5.0$ <<"end" cat
> $USER
> end
$USER
```