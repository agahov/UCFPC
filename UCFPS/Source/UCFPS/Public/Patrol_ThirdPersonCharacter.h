// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Patrol_ThirdPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UCFPS_API APatrol_ThirdPersonCharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
	
	
	
	
};
