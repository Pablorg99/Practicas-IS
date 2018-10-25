# Caso_uso_003.md

## Borrar Alumno

**ID:** 003.  
**Breve descripción:** Permite borrar un alumno.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir.

**Flujo Principal:**

1. El caso empieza cuando el usuario desea eliminar un alumno.
2. El sistema pide una confirmación del borrado del alumno seleccionado.

**Postcondiciones:**

* El alumno seleccionado es borrado del sistema.

**Flujo alternativo:**

* Si el alumno a borrar no existe, el sistema muestra un error.
* Si el ususario rechaza la confirmación de borrado se rechaza la petición de borrado.
