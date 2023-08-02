#include "User.h"

u32 User_u32ChooseFeature1(){
    u32 feature1;
    
    printf("Please, Choose which feature do you want:\n");
    printf("1: To View patient record: Write 1\n");
	printf("2: To View patients reservation: Write 2\n");
    printf("0: Exit from User Mode\n\n");
    scanf("%d", &feature1);
    
    return feature1;

}

void User_voidViewPatient1(PatientsList * ListPtr){
    /*By entering the patient ID, the system shall show the basic information for the patient.*/
    patient P;
    Patient_voidInit(&P);
    printf("Enter the ID of the patient you want to View:  ");
    scanf("%d",&P.ID);
    node *current = ListPtr->chain;
    if(current == NULL )
        printf("List is Empty!!\n");
    else{
        P= List_patientSearchbyID(ListPtr,P); // Print Patient information.
        if(P.age != 0){
        }
        else{
            printf("\nREJECTED!, The entered ID doesn't exist!!\n\n");
        }
    }

}

void User_voidTodayReservations1(PatientsList * ListPtr){
    /*In this view, the system shall print all reservations with the patient ID attached to each reservation slot.*/
    node *current = ListPtr->chain;
    if(current == NULL )
        printf("Reservations List is Empty!!\n");
    else{
        printf("\nThe Reservations Today:\n");
        printf("------------------------------\n");
        printf("  ID        :           Slot        \n");
        /* Traverse into the patients having reservations slots.*/
        while(current != NULL){
            if(current->Pat.s != PATIENT_IS_OK && (current->Pat.s <= 5 || current->Pat.s >= 1)){   
                printf("  %d       :        %s        \n",current->Pat.ID,avalaibleReservation[current->Pat.s - 1]);
            }
            current = current->next;
        }
        printf("\n\n");
    }

}

void User_voidUserMode(PatientsList * ListPtr){

    printf("\nWelcome To User Mode.\n");
    u32 feature;
    do{
        feature = User_u32ChooseFeature1();                
        switch (feature){
            case 1:
                User_voidViewPatient1(ListPtr);

                break;
            case 2:
                User_voidTodayReservations1(ListPtr);

                break;
            case 0:
                break;            
            default:
                break;
        }
    }while(feature != 0);

}