# Sincronización con github

Github es una plataforma de trabajo colaborativo para alojar proyectos utilizando el sistema de control de versiondes ***Git***.  

## Vinculación con github

Para vincular nuestra cuenta de github con nuestro equipo en el que vamos a realizar el trabajo tendremos que generar una clave SSH.   
Lo primero es comprobar que no tenemos ya una clave SSH pública. Para ello nos movemos al directorio `~/.ssh` y comprobamos que no hay ningún archivo con la extensión `.pub`. Si tenemos un archivo con dicha extensión esa será nuestra clave y no tendremos que generar una.  
Para generar una clave nueva utilizaremos el siguente comando:

> ssh-keygen

Y para verla:

> cat ~/.ssh/id_rsa.pub

Copiamos todo su contenido y posteriormente vamos a la configuración de nuestra cuenta de github al apartado `SSH and GPG keys`. Allí configuramos una nueva y pegamos el contenido donde lo indica.



