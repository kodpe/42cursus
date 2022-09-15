# Parenthesis

exitcode 2

```bash
(
#>
```

```bash
bonjour(
#bash: syntax error near unexpected token `newline'
```

```bash
)
#bash: syntax error near unexpected token `)'
```

```bash
bonjour)
#bash: syntax error near unexpected token `)'
```

```bash
()
#bash: syntax error near unexpected token `)'
```

```bash
(                     )
#bash: syntax error near unexpected token `)'
```

```bash
()()
#bash: syntax error near unexpected token `)'
```

```bash
(ls)(cd)
#bash: syntax error near unexpected token `('
```

---

erreurs parsign pas parentheses ; exitcode 2

```bash
&(
#bash: syntax error near unexpected token `&'

```

---

erreurs pas parsing; exitcode 1

```bash
((()))
#bash: ((: (()): syntax error: operand expected (error token is "))")
```

---

pas erreur du tout

```bash
(cmd)
#bash: cmd: command not found
```

```bash
((cmd))
#
```

```bash
(((cmd)))
#
```