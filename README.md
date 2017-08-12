# Auteur

Je suis 
[Gerard KESSE](http://31.33.37.71:8855/presentation/ "Accédez à mon site web (ReadyDev)"),  
Ingénieur en Développement Informatique C/C++/Qt,  
Avec à la fois des compétences en Systèmes Embarqués et en Robotique.  

* Site Web : [ReadyDev](http://31.33.37.71:8855 "Accédez à mon site web (ReadyDev)")
* Email : [tiakagerard@hotmail.com](mailto:tiakagerard@hotmail.com?subject=Contact&body=Bonjour "Me contactez par email")
* Tel : [(+33) 06.58.77.23.97](tel:00330658772397 "Contactez-moi")
* Localité : **Toulouse - France**

# ReadyTTA

**ReadyTTA** est une bibliothèque de fonctions C pour le développement de systèmes 
embarqués multitâches temps réel. Elle est construite autour de l'architecture TTA 
(Time Triggered Architecture), une architecture logicielle déclenchée par le temps et 
certifiée pour le développement de systèmes de sécurité critique. Elle est portable 
sur plusieurs cibles de microcontrôleurs (8051, PIC) et de microprocesseurs (ARM). 
C'est une bibliothèque développée en C et maintenu par 
[Gerard KESSE](http://31.33.37.71:8855/presentation/ "Accédez à mon site web (ReadyDev)").

# Système d'Exploitation Embarqué Simple

```
#include "GSeos.h"
#include "GLed.h"

void main() {
    GSeos_Init(50);
    GLed_Init();
    GSeos_Start();
    while(1) {
        GSeos_Go_To_Sleep();
    }
}
```

# Ordonnancement Coopératif

```
#include "GSch.h"
#include "GStateMachine.h"

void main() {
    GSch_Init();
    GState_Init();
    GSch_Add_Task(GState_Light_L1, 0, 1000);
    GSch_Add_Task(GState_Light_L2, 1, 1000);
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
```

* **Structure d'une Tâche**

```
typedef data struct {
    void (*pTask)();    // pointeur de tâche
    uint delay;         // delai ou retard d'exécution
    uint period;        // periode d'exécution
    uchar runMe;        // drapeau d'exécution
} GTask;
```

# Ordonnancement Hybride

```
#include "GSchHybrid.h"
#include "GLed.h"

void main() {
    GSch_Init();
    GLed_Init();
    GSch_Add_Task(GLed_Short, 0, 1000, 1); // tâche coopérative
    GSch_Add_Task(GLed_Long, 1, 20000, 0); // tâche préemptive
    GSch_Start();
    while(1) {
        GSch_Dispatch_Tasks();
    }
}
```

* **Structure d'une Tâche**

```
typedef data struct {
    void (*pTask)();    // pointeur de tâche
    uint delay;         // delai ou retard d'exécution
    uint period;        // periode d'exécution
    uchar runMe;        // drapeau d'exécution
    uchar coop;         // tâche coopérative/préemptive
} GTask;
```

# Technologies

Le développement de la bibliothèque **ReadyTTA** a nécessité les technologies suivantes :

* Langage : **C**
* Microcontrôleur 8051 : **AT89C52, INFINEON C515**
* Microcontrôleur PIC : **PIC18F452**
* Microprocesseur ARM : **LPC1769**
* IDE 8051: **Keil µVision**
* IDE PIC: **MPLab**
* IDE ARM: **GNU ARM Eclipse**
* Compilateur 8051 : **SDDC**
* Simulateur de Circuit Electrique : **Proteus**
* Protocoles : **RS232, I2C, SPI, CAN**
* Modules : **Switch , Button, Keypad, LED, 7-segment, LCD, PWD**
* Architecture Logicielle : **TTA (Time Triggered Architecture)**
* Cible : **8051, PIC, ARM**
