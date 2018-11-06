## Mostrar alumnos

**ID:** 004.  
**Breve descripción:** Permite imprimir los datos en un archivo pdf.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir.
2. El usuario debe haber buscado y seleccionado los alumnos.
3. El usuario debe haber seleccionado el método de ordenación de los alumnos.

**Flujo Principal:**

1. El caso comienza cuando el usuario quiere mostrar los datos de uno o varios alumnos.
2. El usuario debe buscar y seleccionar los alumnos a mostrar.
3. El sistema obtiene y representa los datos de los alumnos siguiendo una plantilla predefinida.

**Postcondiciones:**

* El archivo pdf ha sido creado con los datos correctos.

**Flujo alternativo:**

* Si el alumno buscado no existe el sistema mostrará un mensaje de error.
