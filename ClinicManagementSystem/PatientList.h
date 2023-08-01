#ifndef __PATIENTLIST__H_
#define __PATIENTLIST__H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#define NAME_SIZE 10
#define PATIENT_IS_OK -1
#define DEFAULT_SLOTS 5
#define AVAILABLE 100
#define RESERVED 200

typedef enum gender{ MALE,
                    FEMALE
}gender;

typedef struct patient{
    u8 name[NAME_SIZE];
    u32 ID;
    u32 age;
    u32 s;
    gender Gen;

}patient;
typedef struct node{
    patient Pat;
    struct node *next;
}node;
typedef struct {
     node *chain;
     u32 size;
}PatientsList;
static u8 *avalaibleReservation[DEFAULT_SLOTS] =  
    { "2 pm to 2:30 pm",
	  "2:30 pm to 3:00 pm",
	  "3:00 pm to 3:30 pm",
	  "4:00 pm to 4:30 pm",
	  "4:30 pm to 5:00 pm"
	};
static u32 checkSlot[5]={AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE};

void List_voidInit(PatientsList * ListPtr);
void List_voidAddLast(PatientsList *ListPtr,patient Copy_u32Data);
void List_voidAddFirst(PatientsList *ListPtr,patient Copy_u32Data);
void List_voidAddPosition(PatientsList * ListPtr, patient Copy_u32Data, u32 Copy_u32Position);
patient List_patientDeleteFirst(PatientsList * ListPtr);
patient List_patientDeleteEnd(PatientsList * ListPtr);
patient List_patientDeleteData(PatientsList * ListPtr, patient Copy_u32Data);
void List_voidPrintPatient(patient P);
patient List_s32DeletePosition(PatientsList * ListPtr,u32 Copy_u32Position);
void List_voidPrint(PatientsList * ListPtr);
u32 List_u32Size(PatientsList * ListPtr);
bool List_boolSearchbyID(PatientsList * ListPtr, patient Copy_u32Data);
bool List_boolEditPatient(PatientsList * ListPtr, patient Copy_patientData);
patient List_patientSearchbyID1(PatientsList * ListPtr, patient Copy_u32Data);

#endif
