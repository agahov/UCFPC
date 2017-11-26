// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNodeChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Patrol_ThirdPersonCharacter.h"
#include "AIController.h"

EBTNodeResult::Type UBTTaskNodeChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    
    //return EBTNodeResult::Type::Succeeded;

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!ensure(BlackboardComp) )return EBTNodeResult::Failed;

    if (!OwnerComp.GetAIOwner())
    {
     	UE_LOG(LogTemp, Warning, TEXT("GetAIOwner is null"));
		return EBTNodeResult::Failed;
   
    }
    
    auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();


    if (!ensure(ControlledPawn) )return EBTNodeResult::Failed;

    auto PatrolingCharacter = Cast<APatrol_ThirdPersonCharacter>(ControlledPawn);

    if (!ensure(PatrolingCharacter) )return EBTNodeResult::Failed;

    auto PatrolPoints = PatrolingCharacter->PatrolPointsCPP;

    if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}


    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    if (!Index)
    {
        UE_LOG(LogTemp,Warning, TEXT("IndexValue is Null "));     
        Index = 0;
        BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
    }

    //UE_LOG(LogTemp,Warning, TEXT("Set Index: %i"), Index);     

    auto PatrolPoint = PatrolPoints[Index];
    if (!(ensure(PatrolPoint)))
    {
        UE_LOG(LogTemp, Warning, TEXT("patrol point is null"));
		return EBTNodeResult::Failed;
    }
    else
    {
        //todo look in batale tank how to get name  
        //auto Name = PatrolPoint->GetName();
        //UE_LOG(LogTemp, Warning, TEXT("PatrolPoint  %s"),*Name);
         
        //UE_LOG(LogTemp, Warning, TEXT("PatrolPoint %s"), *PatrolPoint.GetName());
    }


     //BlackboardComp->SetValueAsObject(WayPointName, PatrolPoint);
     BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoint);

     

     Index = (Index+1)% PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

    return EBTNodeResult::Succeeded;

}

