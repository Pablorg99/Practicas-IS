# Diagramas de Secuencia

## Este fichero describe una visión general de los diagramas de secuencia realizados que se encuentran en "Diagramas_de_Secuencia"

### Elementos

---

* **Actor**

Está presente en todos los diagramas de secuencia realizados.

Cuando se hace referencia al mismo con el identificador de "Profesor" se indica que el usuario que interactúa con el sistema puede ser tanto un coordinador como un ayudante.

Cuando se le identifica como coordinador se indica que solo el coordinador puede estar realizando la interacción con el sistema en cuestión.

* **Sistema**

Está presente en todos los diagramas de secuencia realizados.

Se corresponde con la clase Sistema especificada en el diagrama de clases y es la única que interactúa con el usuario de forma directa.

En los diagramas, se señala que el usuario manda un mensaje de tipo llamada al sistema que se corresponde con una función, aunque esto no es directamente. El usuario elige una opción del menú que está directamente relacionada con un método de sistema.

* **Base de Datos**

Está presente en algunos de los diagramas de secuencia. Esto se debe a que ciertos métodos de Sistema no necesitan interactuar con la base de datos.

### Combined Fragments

---

Los representan los diferentes recuadros presentes en algunos diagramas de secuencia que incluyen dentro de ellos ciertos mensajes.

Se observan dos tipos:

* Loop

    Los mensajes de su interior iteran hasta que un momento específico en el que se cumple una condición. La cual se señala en una nota situada al lado del loop.

* Ref

    Se trata de una referencia a otro diagrama de secuencia, implica que para que el sistema se encuentre en la situación posterior a la referencia, tiene que haberse realizado la secuencia expresada en el diagrama de "ref".
