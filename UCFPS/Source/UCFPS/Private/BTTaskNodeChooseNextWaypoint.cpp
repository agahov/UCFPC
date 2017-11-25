// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNodeChooseNextWaypoint.h"



EBTNodeResult::Type UBTTaskNodeChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    UE_LOG(LogTemp,Warning, TEXT("ExecuteTask ChooseNextWayPoint  ")); 
    //return EBTNodeResult::Type::Succeeded;
    return EBTNodeResult::Succeeded;

}

