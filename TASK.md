Me gustaría abordar en estas prácticas un proyecto técnico para TSS que nos ayude a mejorar la seguridad de nuestros sistemas Windows de forma automática: un auditor básico de configuración y exposición en sistemas Windows.

Necesitamos una solución técnica para el siguiente problema:

En entornos Windows, muchos incidentes de seguridad no se producen por malware avanzado, sino por configuraciones inseguras, servicios innecesarios activos o usuarios con privilegios excesivos. Detectar estos problemas manualmente es lento y poco fiable, especialmente cuando se revisan equipos de forma puntual o remota.

Las razones:

    Seguridad preventiva: Detectar configuraciones inseguras antes de que puedan ser explotadas.

    Automatización: Evitar revisiones manuales del sistema.

    Utilidad interna: Disponer de una herramienta de consola que permita obtener rápidamente un diagnóstico básico del estado de seguridad de un sistema Windows.

El primer objetivo es diseñar y prototipar un sistema que:

    Obtenga información real del propio sistema Windows, sin depender de archivos proporcionados externamente.

    Analice servicios activos y configuraciones potencialmente inseguras.

    Detecte usuarios con privilegios elevados.

    Genere un informe indicando riesgos básicos y recomendaciones.

Como parte de tu primera semana, tu tarea es presentarnos tu propuesta. Tú eliges el stack y cómo estructurarás la lógica de análisis del sistema y generación del informe.

Te invito a que investigues cómo obtener información del sistema Windows desde C++ utilizando las APIs del sistema operativo (por ejemplo, servicios, usuarios y configuración).

Te adelanto (copio y pego definición):

Windows expone información crítica del sistema a través de sus APIs y del Registro. Analizar estos datos permite conocer qué servicios están activos, qué usuarios tienen privilegios elevados y qué configuraciones pueden suponer un riesgo de seguridad. Este enfoque se utiliza habitualmente en auditorías básicas y tareas de hardening.