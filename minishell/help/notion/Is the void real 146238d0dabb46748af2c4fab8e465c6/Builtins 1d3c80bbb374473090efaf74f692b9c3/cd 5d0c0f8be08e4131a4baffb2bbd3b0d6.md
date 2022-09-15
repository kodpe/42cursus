# cd

![Screenshot from 2022-06-11 22-15-41.png](cd%205d0c0f8be08e4131a4baffb2bbd3b0d6/Screenshot_from_2022-06-11_22-15-41.png)

```bash
# il faut gérer

cd            # home

cd .          # current dir
cd ./         # current dir
cd ././././.  # current dir

cd ..         # parent dir
cd ../        # parent dir
cd .././././  # parent dir

cd ../..      # parent parent dir
cd ../../     # parent parent dir

cd ../../..   # parent parent parent dir like ... on zsh

cd ...        # ERROR
cd . .        # ERROR
cd /...        # ERROR
cd /...        # ERROR

cd /          # mount
cd //         # mount /!\ but with // and pwd //
cd ///
```

- il faut gérer ‘.’ ‘..’ ‘./’ ‘/.’ ‘./.’ ‘…’ ‘./././././././’

edit $PWD et $OLDPWD a chaque cd 

OLDPWD = PWD

PWD = current directory 

- code test
    
    ```c
    int t_chdir(char *dir)
    {
    	char	*new_dir;
    	char	*path;
    
    	path = ft_current_path();
    	if (!path)
    		return (0);
    	new_dir = ft_strjoin(path, dir);
    	chdir(new_dir);
    	free(dir);
    	free(path);
    	return (1);
    }
    ```