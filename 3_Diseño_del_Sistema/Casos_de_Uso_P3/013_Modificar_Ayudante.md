## Modificar Ayudante

**ID:** 014.  
**Breve descripción:** Permite editar un profesor ayudante ya existente.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El ayudante debe existir.
2. El usuario debe ser profesor coordinador.


**Flujo Principal:**

1. El caso empieza cuando el usuario desea modificar un ayudante.
2. El sistema pide al usuario que identifique al ayudante a modificar mediante su DNI.
3. El sistema pregunta al usuario que parámetro desea editar.
4. El sistema recoge el nuevo valor introducido por el usuario.
5. El sistema pregunta si se desea editar algún otro parámetro.
6. En caso afirmativo, se vuelve al paso 3.

**Postcondiciones:**

* El sistema sustituye la información antigua por la nueva introducida.

**Flujo alternativo:**

* Si el ayudante a modificar no existe, el sistema muestra un error.
