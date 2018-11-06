## Seleccionar líder

**ID:** 005.  
**Breve descripción:** Permite introducir quien es el alumno líder de grupo (Solo 1 por grupo).

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir.
2. No puede haber otro líder en ese grupo.

**Flujo Principal:**

1. El caso comienza cuando el usuario quiere seleccionar quien es el lider de un grupo.
2. El usuario debe buscar y seleccionar el alumno que quiere seleccionar como lider.
3. El sistema comprueba que no hay otro lider en el grupo del alumno seleccionado.

**Postcondiciones:**

* El alumno queda guardado como líder de su grupo.

**Flujo alternativo:**

* Si el alumno buscado no existe el sistema mostrará un mensaje de error.
* Si ya hay un líder en ese grupo el sistema mostrará un error.
