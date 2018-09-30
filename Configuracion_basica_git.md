
![imagengit](https://upload-images.jianshu.io/upload_images/2982112-db343fb0221ada9f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/646)  

    
# Configuración básica de git  

## Instalación  (Ubuntu)

La instalación de Git en ubuntu es bastante sencilla. Basta con ejecutar el siguiente comando:

>sudo apt install git

Por lo general, en la mayoria de variantes del sistema ubuntu Git viene instalado de serie.

## Configuración básica

### Usuario y correo

Lo primero antes de empezar a utilizar git es configurar nuestro usuario y nuestro correo electronico:

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






