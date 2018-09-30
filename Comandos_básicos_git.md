### Los estados de *git*.
![Git states](https://alexdiliberto.com/talks/all-things-git/img/git_local_to_remote.png)

Antes de empezar a trabajar con *git* debemos entender que existen tres posibles estados. Estos estados son los representados en el área local de la imagen anterior. El cuarto estado (*remote*) hace referencia a los repositorios sincronizados con *github*.  
En la siguiente sección aprenderá los comandos necesarios para cambiar el estado de los repositorios.

# Comandos básicos de *git*.

En este apartado veremos los comandos básicos para trabajar con *git*.  

### Iniciar repositorio en un directorio:
` git  init`

Es necesario usar este comando lo primero en cualquier directorio donde se vaya a trabajar con git.

### Agregar cambios al área de *staging*:
`git  add nombre_fichero`

Permite agregar un fichero al área de *staging*.

### Validar cambios en el repositorio:
`git  commit  -m "Mensaje"`

Valida los ficheros antes añadidos al *staging* con *git add* para subirlos a *git*.

### Hacer los dos pasos anteriores en uno:
`git  commit  -am "Mensaje"`

Añade al *staging* y sube a *git*.

### Historial de *commits*:
`git  log`

Permite ver los *commits* realizados.

### Ayuda del listado anterior:
`git  help  log`

Ayuda para trabajar con el historial de *commits*.

### Listar los 5 *commits* mas recientes:
`git  log -n 5`

Permite ver los 5 últimos *commits* realizados.
>Si se cambia el 5 por otro número se modificará el número de *commits* a ver.

### Listar los *commits* desde una fecha:
`git  log  --since =2018 -09 -18`

Permite ver los *commits* desde la fecha introducida.

### Listar los *commits* por autor:
`git  log  --author =" Antonio"`

Permite ver los *commits* realizados por el autor que se introduzca.

### Ver cambios en el directorio:
`git  status`

Permite ver los cambios realizados en un directorio.

### Ver diferencia entre ficheros en el directorio y el repositorio de *git*:
`git  diff`

Permite ver la diferencia entre un directorio y lo que hay en *git*.

### Ver diferencia entre ficheros en el *staging* y el repositorio:
`git  diff  --staged`

Permite ver la diferencia entre un directorio y lo que hay en *staging*

### Eliminar archivos:
* `git rm  archivo`
* `git  commit  -m "Mensaje"`

Deben ser ejecutados en este orden y permiten borrar un archivo de *git*.

### Mover o renombrar archivos:
* `git mv  nombre_antiguo  nombre_nuevo`
* `git  commit  -m "Mensaje"`

Ejecutados por este orden permiten mover un fichero y cambiarle el nombre si se desea.


### Deshacer cambios con *git*:
`git  checkout  -- nombre_fichero`

Permite quitar un fichero de *git*.

### Retirar archivos del *staging*:
`git  reset  HEAD  nombre_fichero`

Permite quitar un archivo del *staging*.

### Complementar último *commit*:
`git  commit  --amend  -m "Mensaje"`

Añade información al último *commit*.

### Recuperar version de un fichero de commit antiguo:
`git  checkout  <id_commit > -- nombre_archivo`

Permite recuperar una versión anterior de un fichero.

### Revertir un commit:
`git  revert  <id_commit >`

Deshace un *commit*.

### Deshacer multiples cambios en el repositorio:
* `git  reset  --soft <id_commit >`
* `git  reset  --mixed  <id_commit >`
* `git  reset  --hard <id_commit >`

**Soft** deshace los de *git*, pero estos seguirá en el *staging*.
**Mixed** deshace los cambios de *git* y del *staging*. **Hard** deshace los cambios de *git*, del *staging* y del directorio local.

### Listar archivos que *git* no controla:
`git  clean  -n`

Permite ver los archivos del directorio que no están sincronizados con *git*.

### Eliminar archivos que *git* no controla:
`git  clean  -f`

Borra los archivos nombrados en el apartado anterior.

### Ignorar archivos en el repositorio:
.gitignore

Los nombres de los archivos que estén en este fichero serán como si no estuvieran en el directorio para *git*.
>Se puede usar *.[extension] para referenciar a todos los archivos con dicha extensión.

### Listar el contenido del repositorio de *git*:

* `git ls-tree  master`
* `git ls-tree  master ^^^`
* `git ls-tree  master ~3`

Permiten ver lo que hay actualmente en el directorio de *git*.

### Log en una línea:
`git  log  --oneline`

Permite ver todos los *commits* realizados en este directorio.

### Log con los tres últimos commits en una línea:
`git  log  --oneline  -3`

Permite ver los 3 últimos *commits* realizados en este repositorio.
>Si se cambia el 3 por *n* se verán los *n* últimos *commits*.

 Para más opciones consultar [documentacion de git](https://git-scm.com/docs/git-log).

### Examinar el contenido de un commit:
`git  show <id>`

Muestra el contenido del *commit* con dicha *id*.

### Comparar un commit con el actual:
`git  diff <id> nombre_archivo`

Muestra la comparación entre entre el *commit* actual y el introducido.

### Comparar dos commits:
`git  diff id..id  nombre_archivo`

Muestra la comparación entre dos *commits*.

Más información sobre [comparación de *commits*](https://git-scm.com/docs/git-diff).
