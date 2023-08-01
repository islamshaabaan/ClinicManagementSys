#ifndef __ADMIN__H_
#define __ADMIN__H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#include "PatientList.h"

#define DEFAULT_PW 1234
#define TRIALS 3


u32 Admin_u32ChooseFeature();

bool Admin_boolAddPatient(PatientsList * ListPtr);

void Admin_voidEditPatient(PatientsList * ListPtr);

void Admin_voidReserveSlot(PatientsList * ListPtr);

void Admin_voidCancelReservation(PatientsList * ListPtr);










#endif