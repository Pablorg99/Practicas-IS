## Generar Backup

**ID:** 006.
**Breve descripción:** Guardar un archivo binario con los datos de los alumnos.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Debe existir al menos un alumno en la base de datos.
2. El usuario debe ser profesor coordinador.

**Flujo Principal:**

1. El caso comienza cuando el usuario quiere guardar una copia exacta de la base de datos.
2. El usuario seleccionará donde quiere guardar el archivo.

**Postcondiciones:**

* El sistema crea el archivo.

**Flujo alternativo:**

* Si no hay datos el sistema mostrará un mensaje de error.
* Si no existe la ruta propuesta por el usuario el sistema mostrará un mensaje de error.
* Si el usuario no es coordinador el sistema muestra un error y se vuelve al menú.
