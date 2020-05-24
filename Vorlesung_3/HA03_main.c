#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"
/*******************************************************
* NAME: HA03_main.c (main) 
*
* AUTHOR: Weinreich Juliane und Bosch Janne (in cooperation with: jannik wiessler)
*											
									kleines Feedback:
									diesmal wars perfekt von der Zeit, wir saßen etwa 1,5h Stunden dran,
									man hat alles gut verstanden, man musste aber trotzdem noch das ein oder andere herausfinden oder im Internet recherchieren, was ja auch so sein soll.
									Die grobe Struktur, die du uns schon mal vorgegeben hast hat sehr geholfen!

* DATE: 2020-05-24
*
* DESCRIPTION:  Implementation of a simple linked list programm. 
*               UI-menu containing the following options:
*                   >> print list
*                   >> add element
*                   >> delete specific element
*                   >> delete whole list
*                   >> save current list to *.txt file
*                   >> load a stored list from *.txt file
*                   >> sort current list by user defined cirteria
*                   >> dlg for saving current list by exiting the program
*
* DEPENDENCIES: 
*   >> HA03_listL.c
*   >> myFunction.h
*
* INFO: For DHBW use only.
*   >> Typdef of struct
*   >> Practice of simple linked list
*
**/
int main(){

    listElement *start;
    start = (listElement *)malloc(sizeof(listElement));
    if (start == NULL) {
        printf("can't reserve storage.\n"); 
        return -1;
        }
    start->nextElem = NULL;

    int FLAGG = 1;
    while (FLAGG){
    
        printf("1... print list\n");
        printf("2... add element\n");
        printf("3... delete element\n");
        printf("4... delete list\n");
        printf("5... save list\n");
        printf("6... load list\n");
        printf("7... sort list\n");
        printf("0... quit\n");
        scanf("%d",&FLAGG);
        system("clear"); // cls for windows


        switch (FLAGG){
            case 1: printList(start); break;
            case 2: addListElem(start); break;
            case 3: delListElem(start); break;
            case 4: delList(start); break;
			case 5: saveList(start); break;
			case 6: loadList(start); break;
            case 7: sortList(start); break;
            case 0: FLAGG = 0; exitFcn(start); break;
            default: printf("invalid choice\n"); break;
        }
    }
    return 0;
}

