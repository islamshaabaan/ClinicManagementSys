/*
 * linked_list.c
 *
 *      Created on: Jul 30, 2023
 *      Author: Islam Shaaban
 */

#include "PatientList.h"

void List_voidInit(PatientsList * ListPtr){
    ListPtr->chain = NULL;
    ListPtr->size =0;
}

void List_voidAddLast(PatientsList *ListPtr,patient Copy_u32Data){
    node * NewNode = (node *) malloc(sizeof(node));
    // Validation to Allocation Memory
    if(NewNode != NULL){
        NewNode->next =NULL;
        NewNode->Pat = Copy_u32Data;
        //if the list is empty
        if( ListPtr->chain == NULL){
            ListPtr->chain= NewNode;
        }
        // Adding at the end
        else{
            node *current = ListPtr->chain ;
            while(current->next != NULL)
                current = current->next;
            current->next= NewNode;
        }
        ListPtr->size++;
    }
    else{
        printf("Malloc coudn't allocate memory.(Heap Problem)\n");
    }
}

//push
void List_voidAddFirst(PatientsList *ListPtr,patient Copy_u32Data){
    node *temp = (node *) malloc(sizeof(node));
    // Validation to Allocation Memory
    if(temp != NULL){
        temp->Pat = Copy_u32Data;
        temp->next = NULL;
        // if List empty
        if(ListPtr->chain == NULL){
            ListPtr->chain = temp;
        }
        else{
            temp->next = ListPtr->chain;
            ListPtr->chain = temp;
        }
        ListPtr->size++;
    }
    else{
        printf("Malloc coudn't allocate memory.(Heap Problem)\n");
    }
}

void List_voidAddPosition(PatientsList * ListPtr, patient Copy_u32Data, u32 Copy_u32Position){
    node * NewNode = (node *) malloc(sizeof(node));
    // Validation to Allocation Memory
    if(NewNode != NULL){
        NewNode->next =NULL;
        NewNode->Pat = Copy_u32Data;
        //if the list is empty
        if( ListPtr->chain == NULL){
            printf("The list is empty, so it will be added in the first place!\n");
            ListPtr->chain= NewNode;
        }
        else{}
            // Adding to Nth Position
            if(Copy_u32Position==1)
                List_voidAddFirst(ListPtr,Copy_u32Data);
            else if(Copy_u32Position == ListPtr->size)
                List_voidAddLast(ListPtr,Copy_u32Data);
            else{
                node *current = ListPtr->chain ;
                u32 counter = 1;
                while(counter < Copy_u32Position-1){
                    current = current->next;
                    if(current->next == NULL){
                        printf("Error, Size is smaller than your position!!\n");
                        return;
                    }
                    counter++;
                }
                node * temp1 = current-> next; // after = before->next
                current->next = NewNode;
                NewNode->next = temp1;
            }
        }
    

}

//pop
patient List_patientDeleteFirst(PatientsList * ListPtr){
    //if the list is empty
    patient P;
    P.ID = -1;
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return P;
    }
    
    node * temp = ListPtr->chain;
    patient value = temp->Pat;
    ListPtr->chain = ListPtr->chain->next;
    ListPtr->size--;
    free(temp);
    return value;

}

patient List_patientDeleteEnd(PatientsList * ListPtr){
    //if the list is empty
    patient P;
    P.ID = -1;
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return P;
    }
    node *current = ListPtr->chain;
    while(current->next->next != NULL)
        current = current->next;
    patient value = current->next->Pat;
    free(current->next);
    current->next=NULL;
    ListPtr->size--;
    return value; // value of last element;
    
}

patient List_patientDeleteData(PatientsList * ListPtr, patient Copy_u32Data){
    //if the list is empty
    patient P;
    P.ID = -1;
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return P; // not found
    }
    node *current = ListPtr->chain;
    // if the list is 1 element
    if(current->next == NULL && current->Pat.ID != Copy_u32Data.ID) {
        printf("List is Empty!!!\n");
        return P; // value not found
    }
    if(current->Pat.ID==Copy_u32Data.ID){
        return List_patientDeleteFirst(ListPtr);
    }
    while( current->next->Pat.ID != Copy_u32Data.ID ){
        current= current->next;
        if(current->next == NULL) {
            printf("This Data(%d) is not Found!!\n",Copy_u32Data.ID);
            return P;
        } // not found
    }
    node * temp = current ->next;
    current->next = temp-> next;
    free(temp);
    ListPtr->size--;
    return Copy_u32Data;
    
}

void List_voidPrintPatient(patient P){

    printf("ID(%d): Name:(%s) Age(%d) ",P.ID,P.name,P.age);
    if(P.Gen == 0){
        printf("G(MALE) ");
    }
    else
        printf("G(FEMALE) ");
    printf("Slot(%d).\n\n",P.s);

}

patient List_s32DeletePosition(PatientsList * ListPtr,u32 Copy_u32Position)
{
	node* current = ListPtr->chain;
    patient P;
    P.ID = -1;
	if(Copy_u32Position > ListPtr->size || Copy_u32Position<=0)
	{
		printf("invalid position\n");
        return P;
	}
	else if(Copy_u32Position == 1)
	{
        return List_patientDeleteFirst(ListPtr);
	}
	else if(Copy_u32Position == ListPtr->size)
	{
        return List_patientDeleteEnd(ListPtr);
	}
	else
	{
		for(int i=1 ; i<Copy_u32Position-1; i++)
		{
			current = current -> next;
		}
        patient value = current->next->Pat;
		node* after = current -> next;
		current->next = after-> next;
		free(after);
		ListPtr->size --;
        return value;
	}
}

bool List_boolSearchbyID(PatientsList * ListPtr, patient Copy_u32Data){
    //if the list is empty
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return false; // not found
    }
    node *current = ListPtr->chain;
    // if the list is 1 element
    if(current->next == NULL && current->Pat.ID != Copy_u32Data.ID) {
        printf("List With one Patient!!!\n");
        return false; // value not found
    }
    if(current->Pat.ID==Copy_u32Data.ID){
        printf("\nThe Patient Profile:\n");
        List_voidPrintPatient(current->Pat);
        return true;
    }
    while( current->next->Pat.ID != Copy_u32Data.ID ){
        current= current->next;
        if(current->next == NULL) {
            printf("This ID(%d) is not Found!!\n",Copy_u32Data.ID);
            return false;
        } // not found
    }
    printf("The Old Patient Profile:\n");
    List_voidPrintPatient(current->next->Pat);

    return true; // found
    
}

bool List_boolEditPatient(PatientsList * ListPtr, patient Copy_patientData){
    //if the list is empty
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return false; // not found
    }
    node *current = ListPtr->chain;
    // if the list is 1 element
    if(current->next == NULL && current->Pat.ID != Copy_patientData.ID) {
        printf("List With one Patient!!!\n");
        return false; // value not found
    }
    if(current->Pat.ID==Copy_patientData.ID){
        current->Pat = Copy_patientData;
        printf("Patient profile is updated successfully.\n\n"); 
        return true;
    }
    while( current->next->Pat.ID != Copy_patientData.ID ){
        current= current->next;
        if(current->next == NULL) {
            printf("This ID(%d) is not Found!!\n",Copy_patientData.ID);
            return false;
        } // not found
    }
    current->next->Pat = Copy_patientData;
    printf("Patient profile is updated successfully.\n\n"); 
    return true; // found
}

void List_voidPrint(PatientsList * ListPtr){
    node *current = ListPtr->chain;
    if(current == NULL )
        printf("List is Empty!!\n");
    else{
        printf("\n");
        while(current != NULL){
            List_voidPrintPatient(current->Pat);

            current = current->next;
        }
        printf("\n\n");
    }
}

u32 List_u32Size(PatientsList * ListPtr){
    return (ListPtr->size);
}

patient List_patientSearchbyID1(PatientsList * ListPtr, patient Copy_u32Data){
    //if the list is empty
    if(ListPtr->chain == NULL){
        printf("List is Empty!!!\n");
        return Copy_u32Data;
    }
    node *current = ListPtr->chain;
    // if the list is 1 element
    if(current->next == NULL && current->Pat.ID != Copy_u32Data.ID) {
        printf("List With one Patient!!!\n");
        return Copy_u32Data; // value not found
    }
    if(current->Pat.ID==Copy_u32Data.ID){
        return current->Pat;
    }
    while( current->next->Pat.ID != Copy_u32Data.ID ){
        current= current->next;
        if(current->next == NULL) {
            printf("This ID(%d) is not Found!!\n",Copy_u32Data.ID);
            return Copy_u32Data;
        } // not found
    }

    return current->next->Pat; // found
}