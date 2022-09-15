# Bulletin / Executable

Si pipeline_size = 1

     Si builtin ⇒ exitcode = return builtin

     Si exec    ⇒ fork ⇒ exitcode = waitpid status

Sinon

Fd tab (pipe io)

Pid tab

While (nb_fork)

    Fork cmd

    Si builtin ⇒ exitcode = exit builtin

    Si exec    ⇒ exitcode = exit / execve

While waitpid status

Exitcode = convert last status