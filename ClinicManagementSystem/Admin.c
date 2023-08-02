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
    /*admin shall enter these basic information: name, age, gender and ID. 
        The ID shall be unique for the user, if the entered ID is already exists, 
        the system shall reject the entry.*/
    u32 i;
    /*creating a patient profile*/
    patient P;
    Patient_voidInit(&P); // Initialize the patient information.

    printf("Enter the ID of the patient you want to add: ");
    scanf("%d",&P.ID);
    
    patient isFound = List_patientSearchbyID(ListPtr,P);
    /* Check if the ID is unique or repeated. */
    if( isFound.age != 0 ){
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
    /*By entering patient ID the system shall checks if the ID exists, 
    the system shall allow the user to edit thepatient information. 
    If not, the system shall display incorrect ID message.*/
    u32 ID;
    printf("Please, Enter patient ID to edit: ");
    scanf("%d",&ID);
    patient P;
    P.ID = ID;
    bool isFound = List_boolEditPatient(ListPtr,P);
    /* Check if the ID exist or not. */
    if(!isFound){
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        printf("Patient profile is updated successfully.\n\n"); 
    }


}

void Admin_voidReserveSlot(PatientsList * ListPtr){
    /*By default there are 5 available slots, Upon opening of this window, 
    the system shall display the available slots. 
    The admin shall enter the patient ID and the desired slot. 
    The reserved slot shall not appear again in the next patient reservation.*/
    printf("Please, Enter patient ID to reserve a slot: ");
    patient TempPatient;
    Patient_voidInit(&TempPatient);
    scanf("%d",&TempPatient.ID);
    TempPatient = List_patientSearchbyID(ListPtr,TempPatient);
    u32 NoSlotsAvailable = 1;
    if(TempPatient.age == 0 ){ // not found
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        if(TempPatient.s != PATIENT_IS_OK && (TempPatient.s <= 5 || TempPatient.s >= 1))
            printf("\nThe patient already has a reservation\n\n");
        else{
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
                /* traverse in the list till the desired patient and reserve a slot.*/
                else{ 
                    node *current = ListPtr->chain;
                    while(current->Pat.ID != TempPatient.ID){
                        current = current->next;
                    }
                    current->Pat.s = sl;
                    checkSlot[sl - 1] = RESERVED;  
                }
            }
        }
        
    }
}

void Admin_voidCancelReservation(PatientsList * ListPtr){
    /*The admin can cancel a reservation by entering the patient ID. 
    This reservation shall be shown again in the available slots window.*/
    printf("\nPlease, Enter the ID of the patient you want to cancel : ");
    patient TempPatient;
    Patient_voidInit(&TempPatient);
    scanf("%d",&TempPatient.ID);
    TempPatient = List_patientSearchbyID(ListPtr,TempPatient);
    if(TempPatient.age == 0 ){
        printf("\nIncorrect ID!, The entered ID does NOT exist!!\n\n");
    }
    else{
        if(TempPatient.s != PATIENT_IS_OK && (TempPatient.s <= 5 || TempPatient.s >= 1)){
            checkSlot[TempPatient.s - 1] = AVAILABLE; 
            node *current = ListPtr->chain;
            while(current->Pat.ID != TempPatient.ID){
                current = current->next;
            }
            current->Pat.s = PATIENT_IS_OK;
        }
        else{
            printf("The Patient is OK, and hadn't a reservation yet!\n\n");
        }
    }
}   

bool Admin_boolAdminMode(u32 Password,PatientsList * ListPtr ){
/* The system asks for password, the default password is 1234. 
    The system allows 3 trails for the password entry, 
    if the entered password was incorrect for 3 consecutive times, the system shall close. 
    After login in the admin mode, the system shall provide features..*/
    u32 Trial_Counter=1;
    while(Password != DEFAULT_PW && Trial_Counter != TRIALS) 
    {
        Trial_Counter++;
        printf("\nSorry , Incorrect password pleas try again : ");
        scanf("%d",&Password);
    }
    if(Password == DEFAULT_PW && Trial_Counter <= 3){
        printf("\nYou are logged in successfully!!\n\n");
        u32 feature;
        do{
            feature = Admin_u32ChooseFeature();                
            switch (feature){
                case 1:
                    Admin_boolAddPatient(ListPtr);
                    break;
                case 2:
                    Admin_voidEditPatient(ListPtr);
                    break;
                case 3:
                    List_voidPrint(ListPtr);
                    Admin_voidReserveSlot(ListPtr);
                    break;
                case 4:
                    Admin_voidCancelReservation(ListPtr);
                    break;
                case 0:
                    break;            
                default:
                    break;
            }
        }while(feature != 0);
        return true;                
    }
    else{
        printf("\nSorry, too many attempts.\n");
        printf("System is closing...\n\n");
        return false;
    }
}