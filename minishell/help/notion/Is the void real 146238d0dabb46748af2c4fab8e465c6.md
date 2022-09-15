# Is the void real?

@Christopher Simon 

## [Excalidraw](https://excalidraw.com/#room=743fe581be26e8d3f1ea,EUQ0KV_-rznqwG9VzUtcJw)

[***The Big Scheme***](https://excalidraw.com/#room=05f68e30319766f49640,4odiAlx5wdDRrWH3lL5j4g)

Biblio

Maybe REDIR 

- [x]  Read Man

[Functions list](Is%20the%20void%20real%20146238d0dabb46748af2c4fab8e465c6/Functions%20list%2022f290cb30f04d8e96e97ce71f69e500.md)

[Builtins](Is%20the%20void%20real%20146238d0dabb46748af2c4fab8e465c6/Builtins%201d3c80bbb374473090efaf74f692b9c3.md)

[Parsing](Is%20the%20void%20real%20146238d0dabb46748af2c4fab8e465c6/Parsing%2010d9ab7d6e554335a5a8d8e13c9d120e.md)

[Execution](Is%20the%20void%20real%20146238d0dabb46748af2c4fab8e465c6/Execution%2092d0afa9b9b7412da94ff20b53c501e4.md)

 **🪤** [Subject](https://cdn.intra.42.fr/pdf/pdf/47577/en.subject.pdf) @

- Implémentation
    
    
    - [x]  afficher un prompt
    - [x]  historique
    - [ ]  chercher l’éxécutable sur $PATH ou sur un chemin relatif ou absolu
    - [x]  quote ‘
    - [x]  quote “
    - [ ]  redirection < (open read)
    - [ ]  redirection > (open write / trunc)
    - [ ]  redirection >> (open write / append)
    - [ ]  redirection <<  (open write fichier tmp heredoc →readline stdin → unlink)
    - [ ]  pipes |
    - [x]  env var $VAR
    - [x]  variable $?
    - [x]  fd tab
    - [x]  pid tab
    - [ ]  while fork
    - [x]  waitpid_status
    - [x]  pathfinder
    - [ ]  execve error leaks

'||', '&&', '&', ';', ';;', ';&', ';;&', '|', '|&', '(', ou ')'

```bash

```

A edit

Retour exitcode ERR-REDIR (253 ?)

ctrl-d : mettre builtin exit

wildcard “”*

(Le truc de l’expand avec les espaces et des guillemets chelou, mais pour moi balek)

Le “leak” de readline avec les heredoc (deux à la suite et ctrld, pas fsanitize, et pas de suppress valgrind, donc balek)

[schema pipes](https://excalidraw.com/#room=aa8375d532a6c4570e5c,qya3ZovakAZvZ8mmSVGPug)