# **TUTORIAL GIT Y GITHUB**

![imagengit](https://upload-images.jianshu.io/upload_images/2982112-db343fb0221ada9f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/646)  


# Configuración básica de git  

## Instalación  (Ubuntu)

La instalación de Git en ubuntu es bastante sencilla. Basta con ejecutar el siguiente comando:

>sudo apt install git

Por lo general, en la mayoría de variantes del sistema ubuntu Git viene instalado de serie.

## Configuración básica

### Usuario y correo

Lo primero antes de empezar a utilizar git es configurar nuestro usuario y nuestro correo electrónico:

> git config --global user.name "tu usuario"

> git config --global user.email tuemail@example.com

Es importante hacerlo ya que en cada commit usaremos esta información.

Si queremos configurar un usuario distinto para un proyecto en concreto solo tenemos que ejecutar el mismo comando dentro del directorio sin `--global`.

### Editor de texto

Git utilizará un editor por defecto para editar los commits y demás documentos. Si queremos cambiar este editor usaremos:

> git config --global core.editor tu_editor_favorito

### Confirmar

Para comprobar que tenemos una configuración correcta utilizaremos:

> git config --list

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

# Ramas o Branches

Su utilización está muy extendida ya que permite un mejor control del código, especialmente cuando su evolución se produce en paralelo.

Uno de sus usos más comunes es representar las diferentes versiones del software.

### Ver listado de ramas
`git branch`

### Crear una rama
`git branch nombre_rama`

 Git es consciente de la rama en la que nos encontramos en cada momento debido a la existencia de un apuntador especial denominado HEAD que apunta a la rama en la que nos encontramos.

### Cambiar a una rama
`git checkout nombre_rama`

 A través de este comando, el apuntador HEAD mencionado anteriormente pasa a apuntar a la rama 'nombre_rama'.

### Comparar ramas
`git diff nombre_rama1..nombre_rama2`

>Para listar los archivos que han cambiado se puede utilizar `git diff --name-status nombre_rama1..nombre_rama2`

### Renombrar ramas
`git branch -m nombre_antiguo nombre_nuevo`

### Eliminar ramas
~~~
git branch -d nombre_rama
git branch -D nombre_rama
~~~
>El primero de estos 2 comandos dará un error si la rama no es idéntica a la rama master. Con el segundo forzamos el borrado.

### Ver si una rama es igual que la rama en la que nos encontramos
`git branch --merged`

### Integrar una rama a la acutal
`git branch merge rama_a_integrar`

Con la ejecución de este comando, suelen producirse conflictos con los archivos de ambas ramas. Estos conflictos suelen resolverse manualmente realizando commmits con el mensaje "merge"

## Cambios temporales

### Almacenar cambios temporales
`git stash save "Mensaje"`

### Listar cambios
`git stash --list`

### Ver contenido de un cambio
`git stash show -p nombre_stash`

### Eliminar un cambio
`git stash drop nombre_stash`

### Aplicar cambio del stash
~~~
git stash apply nombre_stash
git stash pop nombre nombre_stash
~~~

# Sincronización con github

Github es una plataforma de trabajo colaborativo para alojar proyectos utilizando el sistema de control de versiondes ***Git***.  

## Vinculación con github

Para vincular nuestra cuenta de github con nuestro equipo en el que vamos a realizar el trabajo tendremos que generar una clave SSH.  
Lo primero es comprobar que no tenemos ya una clave SSH pública. Para ello nos movemos al directorio `~/.ssh` y comprobamos que no hay ningún archivo con la extensión `.pub`. Si tenemos un archivo con dicha extensión esa será nuestra clave y no tendremos que generar una.  
Para generar una clave nueva utilizaremos el siguiente comando:

> ssh-keygen

Y para verla:

> cat ~/.ssh/id_rsa.pub

Copiamos todo su contenido y posteriormente vamos a la configuración de nuestra cuenta de github al apartado `SSH and GPG keys`. Allí configuramos una nueva y pegamos el contenido donde lo indica.

## Sincronización de repositorios con github

Para sincronizar un repositorio de github con un repositorio local nuestro ejecutaremos los siguientes comandos en nuestro repositorio local:

> git remote add origin git@github.com:usuario/repositorio.git

Podemos conseguir la dirección ssh de nuestro repositorio de github pinchando en el botón `clone or download` en la página principal del mismo.

## Comandos básicos con github

Hay dos comandos principales a la hora de trabajar con un repositorio remoto. Estos comandos son `git pull` y `git push`.

### Pull

Para bajarnos las últimas actualizaciones de nuestro repositorio remoto ejecutaremos `git pull`. Este comando comparará nuestro repositorio local con el remoto y descargará los cambios que no tengamos.

### Push

Para subir a nuestro repositorio remoto los últimos cambios que hemos realizado en el local ejecutaremos `git push`. Este comando subirá los últimos commits que estén en nuestro repositorio local y no en el remoto.

## Merge

Cuando queremos hacer un Push pero en el repositorio remoto hay contenido que no tenemos en nuestro local tendremos que bajar primero ese contenido y mezclarlo con el nuestro*.
Para ello haremos nuestro commit, un Pull y luego haremos push. O directamente ejecutaremos `git merge` (ver apartado de ramas para más información).

*Si hay un mismo archivo con más contenido arriba tendremos que decirle a git con que nos queremos quedar.
