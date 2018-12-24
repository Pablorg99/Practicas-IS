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

Se observan cuatro tipos:

* Loop

    Los mensajes de su interior iteran mientras que se cumpla la condición señalada entre corchetes.

* Alt

    Se utiliza para señalar una sentencia if. Implica que hay 2 secuencias de mensajes alternativas, que o se cumple una o la otra. La condición se señala entre corchetes cuando es necesario. En otras ocasiones se sobreentiende esta condición por el primer mensaje de la secuencia.

* Opt

	Implica que los mensajes que contiene no se producen en todas las ejecuciones, ya que son mensajes opcionales. En la mayoría de casos es utilizado para indicar el flujo de mensajes de una opción de un menú.

* Break

	Se incluye en el interior de algunos bucles para señalar que si se llega a esta secuencia, se produce una salida del mismo.
