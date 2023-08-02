#ifndef __PATIENTLIST__H_
#define __PATIENTLIST__H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#define NAME_SIZE 10 // size of patient name.
#define PATIENT_IS_OK -1 // the patient has no reservation, it's ok not sick.
#define DEFAULT_SLOTS 5 // default reservation slots.
#define AVAILABLE 100 // the slot is available.
#define RESERVED 200 // the slot is reserved.

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
static char *avalaibleReservation[DEFAULT_SLOTS] =  
    { "2 pm to 2:30 pm",
	  "2:30 pm to 3:00 pm",
	  "3:00 pm to 3:30 pm",
	  "4:00 pm to 4:30 pm",
	  "4:30 pm to 5:00 pm"
	};
static u32 checkSlot[5]={AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE};

/********************************************************************************
* Function name :  Patient_voidInit.                       
* Purpose : Patient information initialization.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (void) No parameters.                              
*********************************************************************************/
void Patient_voidInit(patient * PatientPtr);

/*******************************************************************************
* Function name :  List_voidInit.                       
* Purpose : Patient List information initialization.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (void) No parameters.                              
****************************************************************************/
void List_voidInit(PatientsList * ListPtr);

/****************************************************************************
* Function name :  List_voidAddLast.                       
* Purpose : Add Patient to the list at last place.        
* Parameters :  1- (ListPtr) The Address of the patients list,
                2- (patient) the patient object.               
* Return value :  (void) No parameters.   *                           
*******************************************************************************/
void List_voidAddLast(PatientsList *ListPtr,patient Copy_u32Data);

/**********************************************************************************
* Function name :  List_voidAddFirst.                       
* Purpose : Add Patient to the list at first place.        
* Parameters :  1- (ListPtr) The Address of the patients list,
                2- (patient) the patient object.               
* Return value :  (void) No parameters.                              
************************************************************************************/
void List_voidAddFirst(PatientsList *ListPtr,patient Copy_u32Data);

/*********************************************************************************
* Function name :  List_voidAddPosition.                       
* Purpose : Add Patient to the list at certain place.        
* Parameters :  1- (ListPtr) The Address of the patients list,
                2- (patient) the patient object,
                3- (u32) the position of the patient added.               
* Return value :  (void) No parameters.                              
*********************************************************************************/
void List_voidAddPosition(PatientsList * ListPtr, patient Copy_u32Data, u32 Copy_u32Position);

/***********************************************************************************
* Function name :  List_patientDeleteFirst.                       
* Purpose : Delete Patient from the list which at first place.        
* Parameters :   (ListPtr) The Address of the patients list,            
* Return value :  (patient) patient object which deleted.                              
***********************************************************************************/
patient List_patientDeleteFirst(PatientsList * ListPtr);

/***********************************************************************************
* Function name :  List_patientDeleteEnd.                       
* Purpose : Delete Patient from the list which at end place.        
* Parameters :   (ListPtr) The Address of the patients list,            
* Return value :  (patient) patient object which deleted.                              
***********************************************************************************/
patient List_patientDeleteEnd(PatientsList * ListPtr);

/*********************************************************************************
* Function name :  List_patientDeleteData.                       
* Purpose : Delete Patient from the list which has certain data.        
* Parameters :  1- (ListPtr) The Address of the patients list and,
                2- (u32) the data of the patient deleted.               
* Return value :  (void) No parameters.                              
*********************************************************************************/
patient List_patientDeleteData(PatientsList * ListPtr, patient Copy_u32Data);

/*********************************************************************************
* Function name :  List_s32DeletePosition.                       
* Purpose : Delete Patient from the list which at certain position.        
* Parameters :  1- (ListPtr) The Address of the patients list ,
                2- (u32) the position of the patient deleted.               
* Return value :  (void) No parameters.                              
*********************************************************************************/
patient List_s32DeletePosition(PatientsList * ListPtr,u32 Copy_u32Position);

/*********************************************************************************
* Function name :  List_voidPrintPatient.                       
* Purpose : Print information Data of patient object.        
* Parameters :   (patient) Patient object .             
* Return value :  (void) No parameters.                              
*********************************************************************************/
void List_voidPrintPatient(patient P);

/*********************************************************************************
* Function name :  List_voidPrint.                       
* Purpose : Print information Data of patient list object.        
* Parameters :  (ListPtr) The Address of the patients list,        
* Return value :  (void) No parameters.                              
*********************************************************************************/
void List_voidPrint(PatientsList * ListPtr);

u32 List_u32Size(PatientsList * ListPtr);
//bool List_boolSearchbyID(PatientsList * ListPtr, patient Copy_u32Data);

/*********************************************************************************
* Function name :  List_boolEditPatient.                       
* Purpose : Edit Patient information.        
* Parameters :  1- (ListPtr) The Address of the patients list and,
                2- (patient) the copy patient of the patient edited.               
* Return value :  (bool) True: the patient is edited.
                         False: the patient is not exist.                              
*********************************************************************************/
bool List_boolEditPatient(PatientsList * ListPtr, patient Copy_patientData);

/*********************************************************************************
* Function name :  List_patientSearchbyID.                       
* Purpose : Searching for patient by his ID.        
* Parameters :  1- (ListPtr) The Address of the patients list and,
                2- (patient) the copy patient of the patient which i looking for.               
* Return value :  (patient) the patient object which i looking for.                              
*********************************************************************************/
patient List_patientSearchbyID(PatientsList * ListPtr, patient Copy_u32Data);

#endif
