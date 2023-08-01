#ifndef __ADMIN__H_
#define __ADMIN__H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#include "PatientList.h"

u32 Admin_u32ChooseFeature1();


void User_voidViewPatient1(PatientsList * ListPtr);

void User_voidTodayReservations1(PatientsList * ListPtr);




#endif