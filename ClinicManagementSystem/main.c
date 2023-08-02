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
        
        switch (mode)
        {
            case 1:
                printf("\nWelcome To Admin Mode.\n");
                printf("Please Enter the password: ");
                scanf("%d",&pw);

                if( ! Admin_boolAdminMode(pw,&PatList))
                    return 1;

                break;
            case 2:
                User_voidUserMode(&PatList);
                
                break;

        
            default:    
                break;
        }
    }while(mode != 0);
    List_voidPrint(&PatList);



    return 1;
}