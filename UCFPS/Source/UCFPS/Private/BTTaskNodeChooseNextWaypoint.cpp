// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNodeChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UBTTaskNodeChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    
    //return EBTNodeResult::Type::Succeeded;

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    //int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

    if (Index)
    {
        UE_LOG(LogTemp,Warning, TEXT("ExecuteTask IndexValue %i "), Index);     
    }
    else
    {
        UE_LOG(LogTemp,Warning, TEXT("IndexValue is Null "));     
    }

    

    return EBTNodeResult::Succeeded;

}

