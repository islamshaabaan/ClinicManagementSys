#ifndef __ADMIN__H_
#define __ADMIN__H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#include "PatientList.h"

#define DEFAULT_PW 1234 // default password
#define TRIALS 3 // number of try that admin can try to write password

/***************************************************
* Function name :  Admin_u32ChooseFeature.                       
* Purpose : To print the features that admin can do it.        
* Parameters :   (void) No parameters.               
* Return value :  (u32) The feature option number.                              
***************************************************/
u32 Admin_u32ChooseFeature();

/***************************************************
* Function name :  Admin_boolAddPatient.                       
* Purpose : Allow to the admin to add new patient to the List.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (bool) True = the patient is added,
                         False = the patient is already exist.                              
***************************************************/
bool Admin_boolAddPatient(PatientsList * ListPtr);

/***************************************************
* Function name :  Admin_voidEditPatient.                       
* Purpose : Allow to the admin to edit patient profile information.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (void) No parameters.                              
***************************************************/
void Admin_voidEditPatient(PatientsList * ListPtr);

/***************************************************
* Function name :  Admin_voidReserveSlot.                       
* Purpose : Allow to the admin to reserve a slot for the patient.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (void) No parameters.                              
***************************************************/
void Admin_voidReserveSlot(PatientsList * ListPtr);

/***************************************************
* Function name :  Admin_voidCancelReservation.                       
* Purpose : Allow to the admin to cancel a reservation for a patient.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value :  (void) No parameters.                              
***************************************************/
void Admin_voidCancelReservation(PatientsList * ListPtr);

/***************************************************
* Function name :  Admin_boolAdminMode.                       
* Purpose : Admin Mode Function.        
* Parameters :   (ListPtr) The Address of the patients list and (u32) The Password.               
* Return value :  (bool) True = if the password is correct
                         False = if the admin wrote the password wronge three times.                              
***************************************************/
bool Admin_boolAdminMode(u32 Password,PatientsList * ListPtr );








#endif