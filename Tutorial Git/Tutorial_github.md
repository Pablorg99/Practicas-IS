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