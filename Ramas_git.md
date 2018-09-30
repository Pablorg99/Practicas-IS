# Ramas o Branches

Su utilización está muy extendida ya que permite un mejor control del código, especialmente cuando su evolución se produce en paralelo

### Ver listado de ramas
`git branch`

### Crear una rama
`git branch nombre_rama`

 Git es consciente de la rama en la que nos encontramos en cada momento debido a la existencia de un apuntador especial denominado HEAD que apunta a la rama en la que nos encontramos

### Cambiar a una rama
`git checkout nombre_rama`

 A través de este comando, el apuntador HEAD mencionado anteriormente pasa a apuntar a la rama 'nombre_rama'

### Comparar ramas
`git diff nombre_rama1..nombre_rama2`

>Para simplemente listar los archivos que han cambiado se puede utilizar `git diff --name-status`

### Renombrar ramas
`git branch -m nombre_antiguo nombre_nuevo`
