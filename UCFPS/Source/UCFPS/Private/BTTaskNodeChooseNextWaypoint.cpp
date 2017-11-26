// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNodeChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


#include "AIController.h"
#include "PatrolRouteComponent.h"

EBTNodeResult::Type UBTTaskNodeChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    
    

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!ensure(BlackboardComp) )return EBTNodeResult::Failed;

    if (!OwnerComp.GetAIOwner())
    {
     	UE_LOG(LogTemp, Warning, TEXT("GetAIOwner is null"));
		return EBTNodeResult::Failed;
    }
    
    auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (!ensure(ControlledPawn) )return EBTNodeResult::Failed;

    auto PatrolRouteComp = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();
    

    if (!ensure(PatrolRouteComp) )return EBTNodeResult::Failed;

    auto PatrolPoints = PatrolRouteComp->GetPatrolPoints();

    if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}


    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    // if (!Index)
    // {
    //     UE_LOG(LogTemp,Warning, TEXT("IndexValue is Null "));     
    //     Index = 0;
    //     BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
    // }

    UE_LOG(LogTemp,Warning, TEXT("Set Index: %i"), Index);     

    auto PatrolPoint = PatrolPoints[Index];
    if (!(ensure(PatrolPoint)))
    {
        UE_LOG(LogTemp, Warning, TEXT("patrol point is null"));
		return EBTNodeResult::Failed;
    }


     
     BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoint);

     

     Index = (Index+1)% PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

    return EBTNodeResult::Succeeded;

}

