## Eliminar Ayudante

**ID:** 014.  
**Breve descripción:** Permite eliminar un profesor ayudante.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El ayudante debe existir.
2. El usuario debe ser profesor coordinador.

**Flujo Principal:**

1. El caso empieza cuando el usuario desea eliminar un ayudante.
2. El sistema pide una confirmación del borrado del alumno seleccionado.

**Postcondiciones:**

* El ayudante seleccionado es eliminado del sistema.

**Flujo alternativo:**

* Si el ayudante a borrar no existe, el sistema muestra un error.
* Si el usuario rechaza la confirmación de borrado se rechaza la petición de borrado y se vuelve al menú.
