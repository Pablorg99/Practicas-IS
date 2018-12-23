## Cargar Backup

**ID:** 009.
**Breve descripción:** Lee un archivo binario con los datos de los alumnos.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El usuario debe ser profesor coordinador.

**Flujo Principal:**

1. El caso comienza cuando el usuario quiere cargar una copia de seguridad de la base de datos.
2. El usuario introduce donde está almacenado el archivo.

**Postcondiciones:**

* El sistema carga la información del archivo.

**Flujo alternativo:**

* Si la ruta introducida no corresponde a una copia de seguridad del sistema, este devolverá un mensaje de error.
* Si el usuario no es coordinador el sistema muestra un error y se vuelve al menú.
