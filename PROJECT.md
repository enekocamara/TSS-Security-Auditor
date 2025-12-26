# TSS AUDITOR DE SEGURIDAD

## STACK

Voy a utilizar C++23 con modules. Para compilar el programa usare CMAKE, VisualStudio y el compilador cl.
Utilizare Visual Studio Community 2026 para IDE.
Para la ui utilizare [fltk](https://github.com/fltk/fltk).
Para la cli utilizare [CLI11](https://github.com/CLIUtils/CLI11).
Utilizare mi propia herramienta [core](https://github.com/enekocamara/core) para prototipar el projecto y despues la quitare.

## APLICACIÓN UI

Toolbar para acciones de utilidad, si las hay.
A la izquierda un dropdown de categorias de tipos de vulneravididad con iconos marcando
el numero de cada una. Expandiendo sale cada una, y clicando abre en la pantalla derecha una descripcion de la vulneravilidad y pasos a dar.

![Error loading image from [docs/images/screen1.png]](docs/images/screen1.png)
## APLICACIÓN CLI
Usando CLI11, hacer commandos para conseguir informacion de las vulneravilidades, el output en modo visual o json para parsear.
Tener flags para listar por tipos de vulneravilidad y por seriedad.

## STRUCTURA DEL PROJECTO
El projecto estara separado en tres partes

* Una libreria estatica con todas las functiones y logica necesaria para conseguir la informacion requerida de windows, y el texto que explica el tipo de vulneravilidad y pasos a dar.
* Un ejecutable que lanza la aplicacion ui.
* Un ejecutable que se añade a bin para ser ejectuado como comando de terminal.


Todos utilizaran el mismo sistema de compilacion, y cada uno tendra su git.
Al principio todo estara en el mismo.