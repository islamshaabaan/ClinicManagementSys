#include "Admin.h"
#include "User.h"
#include "PatientList.h"

int main(){

    u32 mode;
    PatientsList PatList;
    List_voidInit(&PatList);
    do{ 
        printf("Please, Choose The Mode:\n");
        printf("1: Admin Mode.\n2: User Mode.\n0:Exit Program!!\n");
        scanf("%d",&mode);

        u32 pw;
        u32 Trial_Counter=1;
        switch (mode)
        {
            case 1:
                printf("\nWelcome To Admin Mode.\n");
                printf("Please Enter the password: ");
                scanf("%d",&pw);

                while(pw != DEFAULT_PW && Trial_Counter != TRIALS) 
                {
                    Trial_Counter++;
                    printf("\nSorry , Incorrect password pleas try again : ");
                    scanf("%d",&pw);
                }
                if(pw == DEFAULT_PW && Trial_Counter <= 3){
                    printf("\nYou are logged in successfully!!\n\n");
                    u32 feature;
                    do{
                        feature = Admin_u32ChooseFeature();                
                        switch (feature)
                        {
                            case 1:
                                Admin_boolAddPatient(&PatList);

                                break;
                            case 2:
                                Admin_voidEditPatient(&PatList);

                                break;
                            case 3:
                                List_voidPrint(&PatList);
                                Admin_voidReserveSlot(&PatList);

                                break;
                            case 4:
                                Admin_voidCancelReservation(&PatList);
                                break;
                            case 0:
                                break;            
                            default:
                                break;
                        }
                    }while(feature != 0);                

                }
                else{
                    printf("\nSorry, too many attempts.\n");
                    printf("System is closing...\n\n");
                    return 1;
                }

                
                
                break;
            case 2:
                printf("\nWelcome To User Mode.\n");
                u32 feature;
                    do{
                        feature = User_u32ChooseFeature1();                
                        switch (feature)
                        {
                            case 1:
                                User_voidViewPatient1(&PatList);

                                break;
                            case 2:
                                User_voidTodayReservations1(&PatList);

                                break;
                            case 0:
                                break;            
                            default:
                                break;
                        }
                    }while(feature != 0);
                break;
        
        
            default:
                
                break;
        }
    }while(mode != 0);
    List_voidPrint(&PatList);



    return 1;
}