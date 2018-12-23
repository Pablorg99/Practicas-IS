## Modificar Coordinador

**ID:** 011.  
**Breve descripción:** Permite editar al coordinador de un sistema.

**Actores principales:** Profesor.  
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El coordinador debe existir.
2. El usuario debe identificarse con la clave del coordinador actual del sistema, en caso de ser un nuevo coordinar dicha clave debe haber sido provista por el centro.

**Flujo Principal:**

1. El caso empieza cuando el usuario desea modificar la información del coordinador, ya sea por corregir o añadir información del coordinador actual o por un cambio de coordinador.
2. El sistema pide la clave de coordinador para confirmar la selección de la opción.
3. El sistema pregunta al usuario que parámetro desea editar.
4. El sistema recoge el nuevo valor introducido por el ususario.
5. El sistema pregunta si se desea editar algún otro parámetro.
6. En caso afirmativo, se vuelve al paso 3.

**Postcondiciones:**

* El sistema sustituye los datos antiguos por los nuevos datos introducidos.

**Flujo alternativo:**

* Si el usuario introduce una clave errónea al confirmar la selección de esta opción el sistema mostrará un error y volvería al menú.
