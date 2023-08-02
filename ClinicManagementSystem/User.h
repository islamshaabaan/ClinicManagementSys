#ifndef __USER__H_
#define __USER__H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#include "PatientList.h"

/***************************************************
* Function name :  User_u32ChooseFeature1.                       
* Purpose : To print the features that user can do it.        
* Parameters :   (void) No parameters.               
* Return value :  (u32) The feature option number.                              
***************************************************/
u32 User_u32ChooseFeature1();

/***************************************************
* Function name :  User_voidViewPatient1.                       
* Purpose : To print the patient information who id is entered.        
* Parameters :   (ListPtr) The Address of the patients list.               
* Return value : (void) No parameters.                 
***************************************************/
void User_voidViewPatient1(PatientsList * ListPtr);

/***************************************************
* Function name :  User_voidTodayReservations1.                       
* Purpose : To print the reservation today.        
* Parameters :   (ListPtr) The Address of the patients list.                
* Return value : (void) No parameters.                 
***************************************************/
void User_voidTodayReservations1(PatientsList * ListPtr);

/***************************************************
* Function name :  User_voidTodayReservations1.                       
* Purpose : To enter the User Mode.       
* Parameters :   (ListPtr) The Address of the patients list.                
* Return value : (void) No parameters.                 
***************************************************/
void User_voidUserMode(PatientsList * ListPtr);


#endif