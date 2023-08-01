#include "Admin.h"
u32 Admin_u32ChooseFeature(){
    u32 feature1;
    
    printf("Please, Choose which feature do you want:\n");
    printf("1: To Add new patient record: Write 1\n");
	printf("2: To Edit patient record: Write 2\n");
	printf("3: To Reserve a slot with the doctor: Write 3\n");
	printf("4: To Cancel reservation: Write 4\n");
    printf("0: Exit from Admin Mode\n\n");
    scanf("%d", &feature1);
    
    return feature1;


}


bool Admin_boolAddPatient(PatientsList * ListPtr){
    u32 i;
    /*creating a patient profile*/
    patient P;
    printf("Enter the ID of the patient you want to add: ");
    scanf("%d",&P.ID);
    
    bool isFound = List_boolSearchbyID(ListPtr,P);
    /* Check if the ID is unique or repeated. */
    if(isFound){
        printf("\nREJECTED!, The entered ID is already exist!!\n\n");
        return false;
    }
    else{ /* The ID is unique.*/
        char gen[10];
        printf("Enter the name of the patient : ");  
        scanf("%s",&P.name);
	    printf("Enter the age of the patient : ");
     	scanf("%d",&P.age);
   		printf("Enter the gender of the patient[MALE or FEMALE] : ");
        scanf("%s",&gen);
        if(gen[0] == 'M' || gen[0]== 'm')
            P.Gen = MALE;
        else if(gen[0] == 'F' || gen[0] == 'f')
            P.Gen = FEMALE;
        P.s = PATIENT_IS_OK;
        List_voidAddLast(ListPtr,P);
        printf("\nThe patient is added successfully.\n\n");
        return true;
    }


}

void Admin_voidEditPatient(PatientsList * ListPtr){
    u32 ID;
    char gen[10];
    printf("Please, Enter patient ID to edit: ");
    scanf("%d",&ID);
    patient P;
    P.ID = ID;
    bool isFound = List_boolSearchbyID(ListPtr,P);
    /* Check if the ID exist or not. */
    if(!isFound){
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        printf("The ID is exist.\n");
        /*Edit The patient Profile*/
        printf("Please, Update patient profile.\n");
        printf("Enter the name of the patient : ");  
        scanf("%s",&P.name);
	    printf("Enter the age of the patient : ");
     	scanf("%d",&P.age);
   		printf("Enter the gender of the patient[MALE or FEMALE] : ");
        scanf("%s",&gen);
        if(gen[0] == 'M' || gen[0]== 'm')
            P.Gen = MALE;
        else if(gen[0] == 'F' || gen[0] == 'f')
            P.Gen = FEMALE;
        P.s = PATIENT_IS_OK;
        List_boolEditPatient(ListPtr,P);

    }


}


void Admin_voidReserveSlot(PatientsList * ListPtr){
    printf("Please, Enter patient ID to reserve a slot: ");
    patient P;
    scanf("%d",&P.ID);
    bool isFound = List_boolSearchbyID(ListPtr,P);
    u32 NoSlotsAvailable = 1;
    printf("The available slots is : \n"); /*Display the available slots.*/
    for (u32 i = 0; i < DEFAULT_SLOTS ; i++){
        if(checkSlot[i]==AVAILABLE){
		    printf("%d : %s\n\n" , i+1 , avalaibleReservation[i]);
            NoSlotsAvailable = 0;
        }
        
    }
    if(NoSlotsAvailable){
            printf("NONE!!\n\n");
    }
    if(!isFound){
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        P = List_patientSearchbyID1(ListPtr,P);
        if(P.s != PATIENT_IS_OK && (P.s <= 5 || P.s >= 1))
            printf("\nThe patient already has a reservation\n\n");
        else{
            u32 sl; //slot
            printf("Enter number of the desired slot : "); /*Choose the number of available slot you want.*/
            scanf("%d",&sl);
            if(sl >5 || sl < 1){
                printf("\nInvalid Slot.\n\n");
                //return;
            }
            else if(checkSlot[sl - 1]==RESERVED){
                printf("\nReserved Slot.\n\n");
            }
            else{
                P.s = sl;
                List_boolEditPatient(ListPtr,P);
                checkSlot[P.s - 1] = RESERVED;  
            }
        }
        
    }
}

void Admin_voidCancelReservation(PatientsList * ListPtr){
    
    printf("\nPlease, Enter the ID of the patient you want to cancel : ");
    patient P;
    scanf("%d",&P.ID);
    bool isFound = List_boolSearchbyID(ListPtr,P);
    if(!isFound){
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        P = List_patientSearchbyID1(ListPtr,P);
        if(P.s != PATIENT_IS_OK && (P.s <= 5 || P.s >= 1)){
            checkSlot[P.s - 1] = AVAILABLE; 
            P.s = PATIENT_IS_OK;
            List_boolEditPatient(ListPtr,P);
        }
        else{
            printf("The Patient is OK, and hadn't a reservation!\n\n");
        }
    }
}   
