# Comandos básicos de git

En este apartado veremos los comandos básicos para trabajar con git.

### Iniciar repositorio en un directorio:
` git  init`

### Agregar cambios al área de staging:
`git  add`

### Validar cambios en el repositorio:
`git  commit  -m "Mensaje"`

### Hacer los dos pasos anteriores en uno:
`git  commit  -am "Mensaje"`

### Historial de commits:
`git  log`

### Ayuda del listado anterior:
`git  help  log`

### Listar los 5 commits m ́as recientes:
`git  log -n 5`

### Listar los commits desde una fecha:
`git  log  --since =2018 -09 -18`

### Listar los commits por autor:
`git  log  --author =" Antonio"``

### Ver cambios en el directorio:
`git  status`

### Ver diferencia entre ficheros en el directorio y el repositorio de git:
`git  diff`

### Ver diferencia entre ficheros en el staging y el repositorio:
`git  diff  --staged`

### Eliminar archivos:
`git rm  archivo`
`git  commit  -m "Mensaje"`

### Mover o renombrar archivos:
`git mv  antiguo  nuevo`
`git  commit  -m "Mensaje"`

### Deshacer cambios con git:
`git  checkout  -- nombre_fichero`

### Retirar archivos del staging:
`git  reset  HEAD  nombre_fichero`

### Complementar  ́ultimo commit:
`git  commit  --amend  -m "Mensaje"`

### Recuperar version de un fichero de commit antiguo:
`git  checkout  <id_commit > -- nombre_archivo`

### Revertir un commit:
`git  revert  <id_commit >`

### Deshacer multiples cambios en el repositorio:
`git  reset  --soft <id_commit >`
`git  reset  --mixed  <id_commit >`
`git  reset  --hard <id_commit >`

### Listar archivos que git no controla:
`git  clean  -n`

### Eliminar archivos que git no controla:
`git  clean  -f`

### Ignorar archivos en el repositorio:
.gitignore

### Listar el contenido del repositorio de git:

`git ls-tree  master`

`git ls-tree  master ^^^`

`git ls-tree  master ~3`


### Log en una l ́ınea:
`git  log  --oneline`

### Log con los tres  ́ultimos commits en una l ́ınea:
`git  log  --oneline  -3`

 Para más opciones consultar documentacion de git.

### Examinar el contenido de un commit:
`git  show <id >`

### Comparar un commit con el actual:
`git  diff <id > nombre_archivo`

### Comparar dos commits:
`git  diff id..id  nombre_archivo`
